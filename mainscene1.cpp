#include "mainscene1.h"
#include "QPixmap"
#include <QDebug>
#include <QTimer>
MainScene1::MainScene1(QObject *parent)
    : QGraphicsScene(parent)
{
    QPixmap background(":/images/Pulse/mainfon1(1).png");
    backgroundItem = new QGraphicsPixmapItem(background);
    addItem(backgroundItem);
    backgroundItem->setZValue(-1);

    QPushButton *buttonStartGame = new QPushButton("start game");
    proxyWidget = addWidget(buttonStartGame);
    buttonStartGame->setStyleSheet("font: 7pt NCL Kregas Personal Use;color: rgb(250, 215, 0);background-image: url(:/images/Pulse/buttonFon.png);");
    buttonStartGame->setGeometry(QRect(QPoint(280, 105), QSize(170, 28)));
    connect(buttonStartGame, &QPushButton::clicked, this, &MainScene1::buttonStartClicked);

    QPushButton *buttonControl = new QPushButton("control");
    proxyWidget = addWidget(buttonControl);
    buttonControl->setStyleSheet("font: 7pt NCL Kregas Personal Use;color: rgb(255, 215, 0);background-image: url(:/images/Pulse/buttonFon.png);");
    buttonControl->setGeometry(QRect(QPoint(280, 155), QSize(170, 28)));
    connect(buttonControl, &QPushButton::clicked, this, &MainScene1::buttonControlClicked);

    QPushButton *buttonCredits = new QPushButton("credits");
    proxyWidget = addWidget(buttonCredits);
    buttonCredits->setGeometry(QRect(QPoint(280, 205), QSize(170, 28)));
    buttonCredits->setStyleSheet("font: 7pt NCL Kregas Personal Use;color: rgb(255, 215, 0);background-image: url(:/images/Pulse/buttonFon.png);");
    connect(buttonCredits, &QPushButton::clicked, this, &MainScene1::buttonCreditsClicked);

    QPushButton *buttonClose = new QPushButton("exit");
    proxyWidget = addWidget(buttonClose);
    buttonClose->setGeometry(QRect(QPoint(280, 255), QSize(170, 28)));
    buttonClose->setStyleSheet("font: 7pt NCL Kregas Personal Use;color: rgb(255, 215, 0);background-image: url(:/images/Pulse/buttonFon.png);");
    connect(buttonClose, &QPushButton::clicked, this, &MainScene1::buttonCloseClicked);

}

