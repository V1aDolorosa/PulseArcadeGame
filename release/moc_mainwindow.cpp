/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "mousePressEvent"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 41, 5), // "event"
QT_MOC_LITERAL(5, 47, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(6, 62, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(7, 80, 13), // "keyPressEvent"
QT_MOC_LITERAL(8, 94, 10), // "QKeyEvent*"
QT_MOC_LITERAL(9, 105, 20), // "switchToControlScene"
QT_MOC_LITERAL(10, 126, 20), // "switchToCreditsScene"
QT_MOC_LITERAL(11, 147, 18), // "switchToStartScene"
QT_MOC_LITERAL(12, 166, 13), // "switchToClose"
QT_MOC_LITERAL(13, 180, 17), // "switchToMainScene"
QT_MOC_LITERAL(14, 198, 5), // "Muzic"
QT_MOC_LITERAL(15, 204, 18), // "on_Button1_clicked"
QT_MOC_LITERAL(16, 223, 18), // "on_Button2_clicked"
QT_MOC_LITERAL(17, 242, 12), // "handleUpKeys"
QT_MOC_LITERAL(18, 255, 14), // "handleDownKeys"
QT_MOC_LITERAL(19, 270, 12), // "changeVolume"
QT_MOC_LITERAL(20, 283, 5) // "value"

    },
    "MainWindow\0mousePressEvent\0\0QMouseEvent*\0"
    "event\0mouseMoveEvent\0mouseReleaseEvent\0"
    "keyPressEvent\0QKeyEvent*\0switchToControlScene\0"
    "switchToCreditsScene\0switchToStartScene\0"
    "switchToClose\0switchToMainScene\0Muzic\0"
    "on_Button1_clicked\0on_Button2_clicked\0"
    "handleUpKeys\0handleDownKeys\0changeVolume\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       6,    1,   95,    2, 0x08 /* Private */,
       7,    1,   98,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    0,  110,    2, 0x08 /* Private */,
      19,    1,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->switchToControlScene(); break;
        case 5: _t->switchToCreditsScene(); break;
        case 6: _t->switchToStartScene(); break;
        case 7: _t->switchToClose(); break;
        case 8: _t->switchToMainScene(); break;
        case 9: _t->Muzic(); break;
        case 10: _t->on_Button1_clicked(); break;
        case 11: _t->on_Button2_clicked(); break;
        case 12: _t->handleUpKeys(); break;
        case 13: _t->handleDownKeys(); break;
        case 14: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
