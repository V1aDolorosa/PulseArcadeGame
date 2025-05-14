#include "mainwindow.h"
#include "controlscene2.h"
#include "creditsscene3.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QPixmap>
#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QTimeLine>
#include "mainscene1.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QDebug>
#include <QSound>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    currentScene = 1 ;
    ui->setupUi(this);

//музыка
      player = new QMediaPlayer(this);
      playlist = new QMediaPlaylist(this);
      playlist->addMedia(QUrl::fromLocalFile("C:/Users/Via/Documents/COURSEWORKarcadeGame/sound/522_full_rise-of-liberty_0138_preview.mp3"));
      playlist->setPlaybackMode(QMediaPlaylist::Loop);

      player->setPlaylist(playlist);
      player->setVolume(50);
      player->play();

      currentMuzic = 1;

//сцены
      scene1 = new MainScene1(this);
      scene2 = new ControlScene2(this);
      scene3 = new CreditsScene3(this);
            int sceneWidth = 444;
            int sceneHeight = 330;
            scene3->setSceneRect(5, 0, sceneWidth, sceneHeight);
      scene4 = new GameScene4(this);
            scene4->setSceneRect(5, 0, sceneWidth, sceneHeight);

      currentScene = 1;


      ui->graphicsView->setScene(scene1);
      ui->graphicsView->setRenderHint(QPainter::Antialiasing);

      ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


//connects
       connect(scene1, &MainScene1::buttonControlClicked, this, &MainWindow::switchToControlScene);
       connect(scene1, &MainScene1::buttonCloseClicked, this, &MainWindow::switchToClose);
       connect(scene1, &MainScene1::buttonCreditsClicked, this, &MainWindow::switchToCreditsScene);
       connect(scene1, &MainScene1::buttonStartClicked, this, &MainWindow::switchToStartScene);
       connect(scene2, &ControlScene2::buttonBackClicked, this, &MainWindow::switchToMainScene);
       connect(scene2, &ControlScene2::buttonMuzicClicked, this, &MainWindow::Muzic);
       connect(scene2, &ControlScene2::volumeChanged, this, &MainWindow::changeVolume);



//цвет окна
       QPalette pal = palette();
       pal.setColor(QPalette::Background, QColor(0, 0, 0));
       setPalette(pal);
//заголовочная панель
       setWindowFlags(Qt::FramelessWindowHint);


       QLabel *label = new QLabel(this);
       //QPixmap pixmap(":/images/Pulse/png.png");
       //label->setPixmap(pixmap);
       label->setScaledContents(true);

       pixmap2 = QPixmap(":/images/Pulse/close.png");
       QPushButton *closeButton = new QPushButton(label);
       closeButton->setFixedSize(22, 20);
       closeButton->setIcon(pixmap2);
       connect(closeButton, &QPushButton::clicked, this, &QMainWindow::close);

       QPixmap pixmapMinimize(":/images/Pulse/minimize.png");
       QPushButton *minimizeButton = new QPushButton(label);
       minimizeButton->setFixedSize(22, 20);
       minimizeButton->setIcon(QIcon(pixmapMinimize));
       connect(minimizeButton, &QPushButton::clicked, this, &MainWindow::showMinimized);

       QHBoxLayout *headerLayout = new QHBoxLayout(label);
       headerLayout->addStretch();
       headerLayout->addWidget(minimizeButton, 0, Qt::AlignTop | Qt::AlignRight);
       headerLayout->addWidget(closeButton, 0, Qt::AlignTop | Qt::AlignRight);
       headerLayout->setContentsMargins(0, 0, 0, 0);

       setMenuWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;

    if (player) {
        delete player;
    }
}

//передвижение сцены

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        Tittle_Position = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - Tittle_Position);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

//mainScene1_Buttons

void MainWindow::switchToControlScene()
{

    currentScene = 2;
    ui->graphicsView->setScene(scene2);
}

void MainWindow::switchToMainScene()
{

    currentScene = 1;
    ui->graphicsView->setScene(scene1);
}

void MainWindow::switchToClose()
{
    this->close();
}

void MainWindow::switchToCreditsScene()
{

    ui->graphicsView->setScene(scene3);
}

void MainWindow::switchToStartScene()
{

    currentScene = 4;
    scene4->startGame();
    ui->graphicsView->setScene(scene4);
}

//arcade_buttons

void MainWindow::on_Button1_clicked()
{

    if (currentScene == 1){
        currentScene = 2;
        ui->graphicsView->setScene(scene2);
    }
    else if (currentScene == 2){
        currentScene = 3;
        ui->graphicsView->setScene(scene3);
    }
    else if (currentScene == 3){
        currentScene = 4;
        scene4->startGame();
        ui->graphicsView->setScene(scene4);

    }
    else if(currentScene == 4){
        currentScene = 1;
        ui->graphicsView->setScene(scene1);
    }
}

void MainWindow::on_Button2_clicked()
{

    if (currentScene == 1){
        currentScene = 4;
        scene4->startGame();
        ui->graphicsView->setScene(scene4);
    }
    else if (currentScene == 2){
        currentScene = 1;
        ui->graphicsView->setScene(scene1);
    }
    else if (currentScene == 3){
        currentScene = 2;
        ui->graphicsView->setScene(scene2);
    }
    else if(currentScene ==4){
        currentScene = 3;
        ui->graphicsView->setScene(scene3);
    }
}

//обработка кнопок
void MainWindow::keyPressEvent(QKeyEvent *event)
{
      keySequence.append(event->text().toUpper());
      if (keySequence.length() > 5) {
          keySequence = keySequence.right(5);
      }

      if (keySequence == "WSSWS") {
          if (currentScene == 4) {
              scene4->Cheat1();
          }
          keySequence.clear();
      }
      else if(keySequence == "SWWSS"){
          if (currentScene == 4) {
              scene4->Cheat2();
          }
          keySequence.clear();
      }
    switch (event->key()) {
        case Qt::Key_W:
        case Qt::Key_Space:
            handleUpKeys();
            break;
        case Qt::Key_S:
            handleDownKeys();
            break;
        default:
        if (event->text() == "ц" || event->text() == "Ц") {
                        handleUpKeys();
                    } else {
                        QMainWindow::keyPressEvent(event);
                    }
            QMainWindow::keyPressEvent(event);
    }
}
//музыка
void MainWindow::Muzic()
{
    if (currentMuzic == 0) {
            currentMuzic = 1;
            player->play();
        } else {
            currentMuzic = 0;
            player->stop();
        }
}
void MainWindow::changeVolume(int value)
{
    player->setVolume(value);
}
