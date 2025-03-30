#include "spriteperson.h"
#include <QDebug>
#include <QGraphicsScene>
spritePerson::spritePerson(const QPixmap &spriteSheet, int frameWidth, int frameHeight, int numFrames, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(spriteSheet.copy(0, 0, frameWidth, frameHeight), parent),
      spriteSheet(spriteSheet), frameWidth(frameWidth), frameHeight(frameHeight), numFrames(numFrames), currentFrame(0)
{
    connect(&animationTimer, &QTimer::timeout, this, &spritePerson::nextFrame);
}

void spritePerson::nextFrame()
{
    currentFrame = (currentFrame + 1) % numFrames;
    int x = (currentFrame * frameWidth) % spriteSheet.width();
    int y = (currentFrame * frameWidth) / spriteSheet.width() * frameHeight;
    setPixmap(spriteSheet.copy(x, y, frameWidth, frameHeight));

    setOffset(-frameWidth / 2, frameHeight / 2);
}
void spritePerson::startRunningAnimation()
{
    animationTimer.start(100);
}
void spritePerson::stopRunningAnimation()
{
    animationTimer.stop();
}
