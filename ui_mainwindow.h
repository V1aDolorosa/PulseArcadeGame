/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *Button1;
    QPushButton *Button2;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(713, 1020);
        MainWindow->setMinimumSize(QSize(713, 1020));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 711, 1011));
        widget->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Pulse/machine1.png);"));
        Button1 = new QPushButton(widget);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        Button1->setGeometry(QRect(400, 820, 71, 41));
        Button1->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Pulse/button12.png);\n"
"background-color: rgb(13, 12, 15);"));
        Button2 = new QPushButton(widget);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        Button2->setGeometry(QRect(480, 820, 71, 41));
        Button2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Pulse/button12.png);\n"
"background-color: rgb(13, 12, 15);\n"
""));
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(130, 400, 461, 341));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Pulse/nope.png);\n"
""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Button1->setText(QString());
        Button2->setText(QString());
#if QT_CONFIG(whatsthis)
        graphicsView->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>scene1 : \320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203 , \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 ,\321\202\320\270\321\202\321\200\321\213, \320\262\321\213\320\271\321\202\320\270 \320\270\320\267 \320\270\320\263\321\200\321\213.</p><p>scene 2 : Game</p><p>scene 3 : \320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 (\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 ,\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\272\320\275\320\276 \321\201 \320\274\321\203\320\267\321\213\320\272\320\276\320\271 (\320\262\320\272\320\273/\320\262\321\213\320\272\320\273 ,\320\263\321\200\320\276\320\274\320\272\320\276\321\201\321\202\321\214 , \321\201\320\274\320\265\320\275\320\260 \321\202\321\200\320\265\320\272\320\260) \320\270 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265</p><p>scene 4 : \321\202\320\270\321\202"
                        "\321\200\321\213(\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\207\321\202\320\276\320\261\321\213 \320\277\320\265\321\200\320\262\321\213\320\274 \320\277\320\276\321\217\320\262\320\273\321\217\320\273\320\276\321\201\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217 \320\270\320\263\321\200\321\213 \320\270 \321\202\320\270\321\202\321\200\321\213 \320\275\320\265 \321\210\320\273\320\270 \321\201 \320\274\320\276\320\274\320\265\320\275\321\202\320\260 \321\201\320\261\320\276\321\200\320\272\320\270)</p><p>\320\230\320\227\320\234\320\225\320\235\320\230\320\242\320\254 \320\227\320\220\320\223\320\236\320\233\320\236\320\222\320\236\320\247\320\235\320\243\320\256 \320\237\320\220\320\235\320\225\320\233\320\254<br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
