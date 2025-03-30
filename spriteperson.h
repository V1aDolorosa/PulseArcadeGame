#ifndef SPRITEPERSON_H
#define SPRITEPERSON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QRect>


class spritePerson : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    spritePerson(const QPixmap &spriteSheet, int frameWidth, int frameHeight, int numFrames, QGraphicsItem *parent = nullptr);
    void startRunningAnimation();
    void stopRunningAnimation();

private slots:
    void nextFrame();
private:
    QPixmap spriteSheet;
    int frameWidth;
    int frameHeight;
    int numFrames;
    int currentFrame;
    QTimer animationTimer;
};

#endif // SPRITEPERSON_H
