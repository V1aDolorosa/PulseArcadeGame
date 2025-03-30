#include "gamescene4.h"
#include "spriteperson.h"
#include "spritelet1.h"
#include "mainwindow.h"
#include <QGraphicsItem>
#include <QPropertyAnimation>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>

GameScene4::GameScene4(QObject *parent) : QGraphicsScene(parent),timerScore(nullptr)
{
    currentScore = 0 ;
    record = 0;
    intXP = 6 ;
    intShield = 0 ;
    k = 0 ;
    difficulty = 100 ;
    scoreOnOff = 0;

//HUD

    QPixmap HUD(":/images/Pulse/girl-Photoroom.png");
    HUDItem = new spriteLet1(HUD);
    addItem(HUDItem);
    HUDItem->setPos(10, 10);

    //HUD XP
        QPixmap xpPixmap(":/images/xp/xp6.png");
        xp = new spriteLet1(xpPixmap);
        addItem(xp);
        xp->setPos(110, 10);
    //HUD speed
        QPixmap speedPixmap(":/images/speed/speed1.png");
        speed = new spriteLet1(speedPixmap);
        addItem(speed);
        speed->setPos(22, 90);
    //HUD shield
        QPixmap shieldPixmap(":/images/Pulse/nope.png");
        shield = new spriteLet1(shieldPixmap);
        addItem(shield);
        shield->setPos(235, 12);


//sprite person
    QPixmap spriteSheet(":/images/sprites/run.png");
    int frameWidth = spriteSheet.width() / 6 + 5;
    int frameHeight = spriteSheet.height() + 5;
    int numFrames = 6;

    spriteItem = new spritePerson(spriteSheet, frameWidth, frameHeight, numFrames);
    addItem(spriteItem);
    spriteItem->setPos(50, 210);

//sprite Let
    QPixmap spriteLet(":/images/sprites/spriteLet(1).png");
    spriteItem2 = new spriteLet1(spriteLet);
    addItem(spriteItem2);

    QPixmap spriteLet2(":/images/sprites/spriteLet(1).png");
    spriteItem3 = new spriteLet1(spriteLet);
    addItem(spriteItem3);

    QPixmap spriteLet3(":/images/sprites/spriteLet(1).png");
    spriteItem4 = new spriteLet1(spriteLet3);
    addItem(spriteItem4);

    animationLet3 = new QPropertyAnimation(spriteItem4, "pos");
    animationLet3->setDuration(3100 - difficulty);
    animationLet3->setStartValue(QPointF(500, 285));
    animationLet3->setEndValue(QPointF(-130, 285));

    animationLet1 = new QPropertyAnimation(spriteItem2, "pos");
    animationLet1->setDuration(3600 - difficulty);
    animationLet1->setStartValue(QPointF(500, 285));
    animationLet1->setEndValue(QPointF(-130, 285));

    animationLet2 = new QPropertyAnimation(spriteItem3, "pos");
    animationLet2->setDuration(4100 - difficulty);
    animationLet2->setStartValue(QPointF(500, 285));
    animationLet2->setEndValue(QPointF(-130, 285));

    XPOSNEW();
    LET();

    connect(animationLet1, &QPropertyAnimation::finished, this, &GameScene4::LET);
    connect(animationLet2, &QPropertyAnimation::finished, this, &GameScene4::LET);
    connect(animationLet3, &QPropertyAnimation::finished, this, &GameScene4::LET);

//sprite background
    QPixmap background(":/images/Pulse/BiGgamefon(1).png");
    backgroundItem = new spriteLet1(background);
    addItem(backgroundItem);
    backgroundItem->setPos(0, -3);

    backgroundAnimation = new QPropertyAnimation(backgroundItem, "pos");
    backgroundAnimation->setDuration(10000);
    backgroundAnimation->setStartValue(QPointF(0, 0));
    backgroundAnimation->setEndValue(QPointF(-910, 0));
    backgroundAnimation->setLoopCount(-1);
    backgroundItem->setZValue(-1);
    backgroundAnimation->start();

    connect(&collisionTimer, &QTimer::timeout, this, &GameScene4::checkCollisions);
    collisionTimer.start(300);

//currentScore
       recordItem = new QGraphicsTextItem(QString::number(currentScore));
       addItem(recordItem);
       QFont font("New_Zelek", 16);
       recordItem->setFont(font);
       recordItem->setPos(230, 135);
       QColor textColor(255, 242, 0);
       recordItem->setDefaultTextColor(textColor);

//recordLabel
       scoreLabel = new QGraphicsTextItem("Record : " + QString::number(record)+" km");
       addItem(scoreLabel);
       QFont font1("New_Zelek", 7);
       scoreLabel->setFont(font1);
       scoreLabel->setPos(115, 40);
       QColor textColor1(255, 242, 0);
       scoreLabel->setDefaultTextColor(textColor1);
//replayGame
       QPushButton *buttonStart = new QPushButton("start game");
       proxyWidget = addWidget(buttonStart);
       buttonStart->setStyleSheet("font: 7pt New_Zelek;color: rgb(250, 215, 0);background-image: url(:/images/Pulse/buttonFon.png);");
       buttonStart->setGeometry(QRect(QPoint(150, 70), QSize(100, 28)));
       connect(buttonStart, &QPushButton::clicked, this, &GameScene4::replayGame);

}
void GameScene4 :: LET(){
    k++;
        if (k >= 3) {
            XPOSNEW();
            k = 0;
        }
}
void GameScene4::startGame(){
    k = 0 ;
    intShield = 0 ;
    XPOSNEW();
    spriteItem->startRunningAnimation();

    QTimer::singleShot(100, this, [this]() {
        animationLet1->start();
    });
    QTimer::singleShot(200, this, [this]() {
        animationLet2->start();
    });
    QTimer::singleShot(300, this, [this]() {
        animationLet3->start();
    });
    if (timerScore) {
           timerScore->stop();
           timerScore->deleteLater();
       }

       timerScore = new QTimer(this);
       connect(timerScore, &QTimer::timeout, this, &GameScene4::score);
       timerScore->start(500);

    QPixmap newPixmap(":/images/speed/speed1.png");
    speed->setPixmap(newPixmap);
}
void GameScene4::checkCollisions()
{
    if (spriteItem->collidesWithItem(spriteItem2) or spriteItem->collidesWithItem(spriteItem3) or spriteItem->collidesWithItem(spriteItem4)) {
        if (intShield > 0){
        intShield -=1 ;
        }
        else {intXP -= 1 ;
        }
 }
    //XP
    if (intShield > 0){
        if (intShield == 3){
            QPixmap newPixmap(":/images/xp/shield.png");
            shield->setPixmap(newPixmap);
        }
        if (intShield == 2){
            QPixmap newPixmap(":/images/xp/shield3.png");
            shield->setPixmap(newPixmap) ;
        }
        if (intShield == 1){
            QPixmap newPixmap(":/images/xp/shield2.png");
            shield->setPixmap(newPixmap) ;
        }
    }
    else {
        QPixmap new2Pixmap(":/images/Pulse/nope.png");
        shield->setPixmap(new2Pixmap);
    if (intXP == 6 ){
        QPixmap newPixmap(":/images/xp/xp6.png");
        xp->setPixmap(newPixmap);
    }
    if (intXP == 5){
        QPixmap newPixmap(":/images/xp/xp5.png");
        xp->setPixmap(newPixmap);
    }
    if (intXP == 4){
        QPixmap newPixmap(":/images/xp/xp4.png");
        xp->setPixmap(newPixmap);
    }
    if (intXP == 3){
        QPixmap newPixmap(":/images/xp/xp3.png");
        xp->setPixmap(newPixmap);
    }
    if (intXP == 2){
        QPixmap newPixmap(":/images/xp/xp2.png");
        xp->setPixmap(newPixmap);
    }
    if (intXP == 1){
        QPixmap newPixmap(":/images/xp/xp1.png");
        xp->setPixmap(newPixmap);
    }
    if (intXP == 0){
        QPixmap newPixmap(":/images/xp/xp0.png");
        xp->setPixmap(newPixmap);

    }
}
    //speed
    if (difficulty == 100){

    }
    else if (difficulty == 500){
        QPixmap newPixmap(":/images/speed/speed2.png");
        speed->setPixmap(newPixmap);
    }
    else if (difficulty == 1000){
        QPixmap newPixmap(":/images/speed/speed3.png");
        speed->setPixmap(newPixmap);
    }
    else if (difficulty == 1500){
        QPixmap newPixmap(":/images/speed/speed4.png");
        speed->setPixmap(newPixmap);
    }

}
void GameScene4 ::XPOSNEW(){

    int minXPos = 400;
    int maxXPos = 500;

    int minX2Pos = 650;
    int maxX2Pos = 750;

    int minX3Pos = 850;
    int maxX3Pos = 950;


    int newXPos = QRandomGenerator::global()->bounded(minXPos, maxXPos);
    int newX2Pos = QRandomGenerator::global()->bounded(minX2Pos, maxX2Pos);
    int newX3Pos = QRandomGenerator::global()->bounded(minX3Pos, maxX3Pos);

    updatePositions(newXPos , newX2Pos , newX3Pos);
}
void GameScene4 ::updatePositions(int newXPos , int newX2Pos , int newX3Pos){
    if (currentScore < 100){
        difficulty = 100 ;
    }
    else if (currentScore > 100 and currentScore < 300){
        difficulty = 500 ;
    }
    else if (currentScore > 300 and currentScore < 500 ){
        difficulty = 1000 ;
    }
    else if (currentScore > 500){
        difficulty = 1500;
    }
        animationLet1->stop();
        animationLet2->stop();
        animationLet3->stop();

        spriteItem2->setPos(newXPos, 270);
        spriteItem4->setPos(newX2Pos, 270);
        spriteItem3->setPos(newX3Pos, 270);

        int baseDurationLet1 = 3100;
        int baseDurationLet2 = 3600;
        int baseDurationLet3 = 4100;

        int newDurationLet1 = baseDurationLet1 - difficulty;
        int newDurationLet2 = baseDurationLet2 - difficulty;
        int newDurationLet3 = baseDurationLet3 - difficulty;

        animationLet1->setDuration(newDurationLet1);
        animationLet2->setDuration(newDurationLet2);
        animationLet3->setDuration(newDurationLet3);

        animationLet1->setStartValue(QPointF(newXPos, 285));
        animationLet1->setEndValue(QPointF(-100, 285));

        animationLet2->setStartValue(QPointF(newX2Pos, 285));
        animationLet2->setEndValue(QPointF(-100, 285));

        animationLet3->setStartValue(QPointF(newX3Pos, 285));
        animationLet3->setEndValue(QPointF(-100, 285));

        animationLet1->start();
        animationLet2->start();
        animationLet3->start();
}
//score
void GameScene4::score(){

    if (intXP > 0 ) {
            currentScore += 1;
            recordItem->setPlainText(QString::number(currentScore));
            if (record < currentScore){
                record = currentScore ;
                scoreLabel->setPlainText("Record : " + QString::number(record)+" km");
            }
}
    else if (intXP <= 0) {
        spriteItem->stopRunningAnimation();
        scoreOnOff = 0 ;
        animationLet1->stop();
        animationLet2->stop();
        animationLet3->stop();
        if (record < currentScore){
            record = currentScore ;
            scoreLabel->setPlainText("Record : " + QString::number(record)+" km");
            }

        }

}
//replay game
void GameScene4::replayGame(){
    if (timerScore) {
            timerScore->stop();
            timerScore->deleteLater();
        }
       intXP = 6;
       startGame();
       currentScore = 0;
       updatePositions(300 , 800 , 1000);

}
//обработчик клавиатуры
void MainWindow::handleUpKeys() {

      if (currentScene == 4){
                spritePerson* spriteItem = scene4->getSpriteItem();
                QPropertyAnimation* animationJump = new QPropertyAnimation(spriteItem, "pos");
                animationJump->setDuration(500);
                animationJump->setStartValue(QPointF(50, 210));
                animationJump->setEndValue(QPointF(50, 180));

                QPropertyAnimation* animationJumpDown = new QPropertyAnimation(spriteItem, "pos");
                animationJumpDown->setDuration(500);
                animationJumpDown->setStartValue(QPointF(50, 210));
                animationJumpDown->setEndValue(QPointF(50, 180));

                animationJump->setDirection(QAbstractAnimation::Forward);
                animationJumpDown->setDirection(QAbstractAnimation::Backward);

                connect(animationJump, &QPropertyAnimation::finished, [=]() {
                    animationJumpDown->start();
                });
                animationJump->start();
    }
}
void MainWindow:: handleDownKeys(){
}

void GameScene4::Cheat1(){
    intXP = 1000;
    qDebug()<<"cheat activated";
    QPixmap newPixmap(":/images/xp/xp6.png");
    xp->setPixmap(newPixmap);
}
void GameScene4::Cheat2(){
    intShield = 3;
    qDebug()<<"cheat activated";

}
