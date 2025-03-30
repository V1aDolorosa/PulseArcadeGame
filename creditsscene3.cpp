#include "creditsscene3.h"
#include "QGraphicsItem"
#include "mainwindow.h"
CreditsScene3::CreditsScene3(QObject *parent): QGraphicsScene(parent)
{

    QPixmap background(":/images/Pulse/creditscene3(3).png");
    backgroundItem = new QGraphicsPixmapItem(background);
    addItem(backgroundItem);
    backgroundItem->setZValue(-1);

    scrollingTextItem1 = new QGraphicsTextItem("  \n"
                                               "                 art designer \nkhabipov aidan\n"
                                               "                 game designer  \nkhabipov aidan \n"
                                               "                 programmer \nkhabipov aidan\n\n"
                                               "created for course work\n"
                                               "thank you for being with us");
    addItem(scrollingTextItem1);
    QFont font("NCL Robowapix Personal Use", 16);
    scrollingTextItem1->setFont(font);
    scrollingTextItem1->setPos(10, yPos-387);
    QColor textColor(255, 242, 0);
    scrollingTextItem1->setDefaultTextColor(textColor);

    scrollingTextItem2 = new QGraphicsTextItem("pulse");
    addItem(scrollingTextItem2);
    QFont font1("NCL Kregas Personal Use", 40);
    scrollingTextItem2->setFont(font1);
    scrollingTextItem2->setPos(10, yPos-437);
    QColor textColor1(222,19,73);
    scrollingTextItem2->setDefaultTextColor(textColor1);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CreditsScene3::moveTextDown);
    timer->start(30);

   }

void CreditsScene3::moveTextDown() {
       yPos += 1;
       scrollingTextItem1->setPos(10, yPos-387);
       scrollingTextItem2->setPos(10, yPos-437);
       if (yPos > 725) {
           yPos = -35;
       }
   }
