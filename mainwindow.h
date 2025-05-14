#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QGraphicsView>
#include "mainscene1.h"
#include "controlscene2.h"
#include "creditsscene3.h"
#include "gamescene4.h"
#include "spriteperson.h"
#include <QSound>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int currentScene ;

private:
    QString keySequence;
    Ui::MainWindow *ui;
    QPixmap pixmap1 ;
    QPixmap pixmap2 ;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem;
    QPoint Tittle_Position;
    MainScene1 *scene1;
    ControlScene2 *scene2;
    CreditsScene3 *scene3;
    GameScene4 *scene4 ;
    int currentMuzic ;
    int *intXP ;
    QSound *sound;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QPropertyAnimation animationJump;
    QPropertyAnimation *animationLet1;
    spritePerson *spriteItem;

private slots :
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void switchToControlScene();
    void switchToCreditsScene();
    void switchToStartScene();
    void switchToClose();
    void switchToMainScene();
    void Muzic();
    void on_Button1_clicked();
    void on_Button2_clicked();
    void handleUpKeys();
    void handleDownKeys();
    void changeVolume(int value);


};
#endif // MAINWINDOW_H
