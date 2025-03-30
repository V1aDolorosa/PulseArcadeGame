#ifndef CONTROLSCENE2_H
#define CONTROLSCENE2_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QSlider>
class ControlScene2 : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ControlScene2(QObject *parent = nullptr);

private:
    QGraphicsPixmapItem *backgroundItem;
    QGraphicsProxyWidget *proxyWidget;
    QSlider *volumeSlider;
signals:
    void buttonBackClicked();
    void buttonMuzicClicked();
    void volumeChanged(int value);
};

#endif // CONTROLSCENE2_H
