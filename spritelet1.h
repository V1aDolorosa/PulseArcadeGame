#ifndef SPRITELET1_H
#define SPRITELET1_H

#include <QObject>
#include <QGraphicsPixmapItem>

class spriteLet1 : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    explicit spriteLet1(const QPixmap &pixmap, QGraphicsItem *parent = nullptr)
        : QGraphicsPixmapItem(pixmap, parent) {};

    QRectF boundingRect() const override {
        return QGraphicsPixmapItem::boundingRect();
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        QGraphicsPixmapItem::paint(painter, option, widget);
    }

signals:

};

#endif // SPRITELET1_H
