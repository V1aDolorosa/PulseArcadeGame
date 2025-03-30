#ifndef MAINSCENE1_H
#define MAINSCENE1_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QTimer>

class MainScene1 : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MainScene1(QObject *parent = nullptr);

private:
    QGraphicsPixmapItem *backgroundItem;
    QGraphicsProxyWidget *proxyWidget;

public slots :
signals:
    void buttonControlClicked();
    void buttonStartClicked();
    void buttonCreditsClicked();
    void buttonCloseClicked();

};

#endif // MAINSCENE1_H
