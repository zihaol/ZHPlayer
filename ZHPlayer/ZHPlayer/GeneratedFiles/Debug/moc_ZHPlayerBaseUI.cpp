/****************************************************************************
** Meta object code from reading C++ file 'ZHPlayerBaseUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ZHPlayerBaseUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZHPlayerBaseUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZHPlayerBaseUI_t {
    QByteArrayData data[11];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZHPlayerBaseUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZHPlayerBaseUI_t qt_meta_stringdata_ZHPlayerBaseUI = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ZHPlayerBaseUI"
QT_MOC_LITERAL(1, 15, 11), // "OnTouchPlay"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "OnTouchGetMusicPath"
QT_MOC_LITERAL(4, 48, 11), // "OnTouchNext"
QT_MOC_LITERAL(5, 60, 11), // "OnTouchLast"
QT_MOC_LITERAL(6, 72, 13), // "OnSliderMoved"
QT_MOC_LITERAL(7, 86, 16), // "OnUpdatePosition"
QT_MOC_LITERAL(8, 103, 9), // "nPosition"
QT_MOC_LITERAL(9, 113, 16), // "OnUpdateDuration"
QT_MOC_LITERAL(10, 130, 9) // "nDuration"

    },
    "ZHPlayerBaseUI\0OnTouchPlay\0\0"
    "OnTouchGetMusicPath\0OnTouchNext\0"
    "OnTouchLast\0OnSliderMoved\0OnUpdatePosition\0"
    "nPosition\0OnUpdateDuration\0nDuration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZHPlayerBaseUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    1,   54,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, QMetaType::LongLong,   10,

       0        // eod
};

void ZHPlayerBaseUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZHPlayerBaseUI *_t = static_cast<ZHPlayerBaseUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnTouchPlay(); break;
        case 1: _t->OnTouchGetMusicPath(); break;
        case 2: _t->OnTouchNext(); break;
        case 3: _t->OnTouchLast(); break;
        case 4: _t->OnSliderMoved(); break;
        case 5: _t->OnUpdatePosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->OnUpdateDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ZHPlayerBaseUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ZHPlayerBaseUI.data,
      qt_meta_data_ZHPlayerBaseUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ZHPlayerBaseUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZHPlayerBaseUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZHPlayerBaseUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ZHPlayerBaseUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
