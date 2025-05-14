#ifndef SPRITEHERO_H
#define SPRITEHERO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsObject>
#include <QTimer>

class SpriteHero : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    SpriteHero(const QPixmap &pixmap, QGraphicsItem *parent = nullptr)
        : QGraphicsPixmapItem(pixmap, parent) {}

    QRectF boundingRect() const override {
        return QGraphicsPixmapItem::boundingRect();
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        QGraphicsPixmapItem::paint(painter, option, widget);
    }
    void startRunningAnimation();

   private slots:
       void nextFrame();
private:
    QVector<QPixmap> m_frames;
    int currentFrame;
    QTimer animationTimer;

};

#endif // SPRITEHERO_H
