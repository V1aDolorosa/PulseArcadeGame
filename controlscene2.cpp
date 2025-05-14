#include "controlscene2.h"
#include "QGraphicsItem"
#include <QSlider>
ControlScene2::ControlScene2(QObject *parent) : QGraphicsScene(parent)
{
    QPixmap background(":/images/Pulse/conrolFon(2).png");
    backgroundItem = new QGraphicsPixmapItem(background);
    addItem(backgroundItem);
    backgroundItem->setZValue(-1);

    QPushButton *buttonBack = new QPushButton("back");
    proxyWidget = addWidget(buttonBack);
    buttonBack->setStyleSheet("font: 7pt NCL Kregas Personal Use;color: rgb(255, 242, 0);background-image: url(:/images/Pulse/buttonFon.png);");
    buttonBack->setGeometry(QRect(QPoint(15, 285), QSize(170, 28)));
    connect(buttonBack, &QPushButton::clicked, this, &ControlScene2::buttonBackClicked);

    QPushButton *buttonMuzic = new QPushButton("muzic(on/off)");
    proxyWidget = addWidget(buttonMuzic);
    buttonMuzic->setStyleSheet("font: 7pt New_Zelek;color: rgb(255, 242, 0);background-image: url(:/images/Pulse/buttonFon.png);");
    buttonMuzic->setGeometry(QRect(QPoint(300, 140), QSize(130, 28)));
    connect(buttonMuzic, &QPushButton::clicked, this, &ControlScene2::buttonMuzicClicked);

    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    proxyWidget = addWidget(volumeSlider);
    volumeSlider->setGeometry(QRect(QPoint(300, 120), QSize(130, 8)));
    connect(volumeSlider, &QSlider::valueChanged, this, &ControlScene2::volumeChanged);
    volumeSlider->setStyleSheet(
                  "QSlider {"
                          "    background: transparent;"
                          "}"
                  "QSlider::groove:horizontal {"
                      "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                      "                                stop:0 rgb(155, 45, 48),"
                      "                                stop:1 rgb(155, 45, 48));"
                      "    height: 8px;"
                      "    border-radius: 4px;"
                      "}"

                      "QSlider::handle:horizontal {"
                      "    background: cyan;"
                      "    border: 2px solid #21cbf3;"
                      "    width: 16px;"
                      "    border-radius: 8px;"
                      "}"

         );
}
