#ifndef GAMESCENE4_H
#define GAMESCENE4_H
#include "spriteperson.h"
#include "spritelet1.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QTimer>

class GameScene4 : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene4(QObject *parent = nullptr);
    spritePerson* getSpriteItem() const { return spriteItem; }
    void score();
    int k ;
public slots :
    void startGame();
    void replayGame();
    void XPOSNEW();
    void LET();
    void updatePositions(int , int , int);
    void Cheat1();
    void Cheat2();


private slots:
    void checkCollisions();
private:
    QGraphicsTextItem *scoreLabel ;
    spriteLet1 *backgroundItem;
    spriteLet1 *xp ;
    spriteLet1 *speed;
    spriteLet1 *shield ;
    int intXP ;
    int scoreOnOff ;
    int intShield ;
    int record ;
    int currentScore ;
    int difficulty ;
    QGraphicsTextItem *recordItem;
    QGraphicsProxyWidget *proxyWidget;
    QPropertyAnimation *animationLet1;
    QPropertyAnimation *animationLet2;
    QPropertyAnimation *animationLet3;
    spritePerson *spriteItem;
    spriteLet1 *spriteItem2;
    spriteLet1 *spriteItem3;
    spriteLet1 *spriteItem4;
    spriteLet1 *HUDItem;
    int* currentScene ;
    QTimer collisionTimer;
    QTimer* timerScore;
    QPropertyAnimation *backgroundAnimation;
    QPushButton *buttonStart;
};

#endif // GAMESCENE4_H
