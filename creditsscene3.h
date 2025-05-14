#ifndef CREDITSSCENE3_H
#define CREDITSSCENE3_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QTimer>
#include <QGraphicsTextItem>
class CreditsScene3 : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CreditsScene3(QObject *parent = nullptr);

public slots:
    void moveTextDown();

private:
    QGraphicsPixmapItem *backgroundItem;
    QGraphicsProxyWidget *proxyWidget;
    QGraphicsTextItem *scrollingTextItem1;
    QGraphicsTextItem *scrollingTextItem2;
    QTimer *timer;
    int yPos;
signals:
};

#endif // CREDITSSCENE3_H
