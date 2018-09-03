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
    QByteArrayData data[25];
    char stringdata0[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZHPlayerBaseUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZHPlayerBaseUI_t qt_meta_stringdata_ZHPlayerBaseUI = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ZHPlayerBaseUI"
QT_MOC_LITERAL(1, 15, 13), // "OnTouchVolume"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "OnTouchPlay"
QT_MOC_LITERAL(4, 42, 19), // "OnTouchGetMusicPath"
QT_MOC_LITERAL(5, 62, 11), // "OnTouchNext"
QT_MOC_LITERAL(6, 74, 11), // "OnTouchLast"
QT_MOC_LITERAL(7, 86, 15), // "OnTouchPlayType"
QT_MOC_LITERAL(8, 102, 21), // "OnSliderPositionMoved"
QT_MOC_LITERAL(9, 124, 18), // "OnSliderVoiceMoved"
QT_MOC_LITERAL(10, 143, 16), // "OnUpdatePosition"
QT_MOC_LITERAL(11, 160, 9), // "nPosition"
QT_MOC_LITERAL(12, 170, 16), // "OnUpdateDuration"
QT_MOC_LITERAL(13, 187, 9), // "nDuration"
QT_MOC_LITERAL(14, 197, 19), // "OnItemDoubleClicked"
QT_MOC_LITERAL(15, 217, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(16, 234, 4), // "item"
QT_MOC_LITERAL(17, 239, 13), // "OnTouchSearch"
QT_MOC_LITERAL(18, 253, 14), // "OnSearchResult"
QT_MOC_LITERAL(19, 268, 25), // "std::vector<tagMusicInfo>"
QT_MOC_LITERAL(20, 294, 10), // "vMusicInfo"
QT_MOC_LITERAL(21, 305, 25), // "OnSearchItemDoubleClicked"
QT_MOC_LITERAL(22, 331, 16), // "GetSongSrcFinish"
QT_MOC_LITERAL(23, 348, 8), // "SongInfo"
QT_MOC_LITERAL(24, 357, 9) // "pSongInfo"

    },
    "ZHPlayerBaseUI\0OnTouchVolume\0\0OnTouchPlay\0"
    "OnTouchGetMusicPath\0OnTouchNext\0"
    "OnTouchLast\0OnTouchPlayType\0"
    "OnSliderPositionMoved\0OnSliderVoiceMoved\0"
    "OnUpdatePosition\0nPosition\0OnUpdateDuration\0"
    "nDuration\0OnItemDoubleClicked\0"
    "QListWidgetItem*\0item\0OnTouchSearch\0"
    "OnSearchResult\0std::vector<tagMusicInfo>\0"
    "vMusicInfo\0OnSearchItemDoubleClicked\0"
    "GetSongSrcFinish\0SongInfo\0pSongInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZHPlayerBaseUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    1,   97,    2, 0x0a /* Public */,
      12,    1,  100,    2, 0x0a /* Public */,
      14,    1,  103,    2, 0x0a /* Public */,
      17,    0,  106,    2, 0x0a /* Public */,
      18,    1,  107,    2, 0x0a /* Public */,
      21,    1,  110,    2, 0x0a /* Public */,
      22,    1,  113,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void, QMetaType::LongLong,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 23,   24,

       0        // eod
};

void ZHPlayerBaseUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZHPlayerBaseUI *_t = static_cast<ZHPlayerBaseUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnTouchVolume(); break;
        case 1: _t->OnTouchPlay(); break;
        case 2: _t->OnTouchGetMusicPath(); break;
        case 3: _t->OnTouchNext(); break;
        case 4: _t->OnTouchLast(); break;
        case 5: _t->OnTouchPlayType(); break;
        case 6: _t->OnSliderPositionMoved(); break;
        case 7: _t->OnSliderVoiceMoved(); break;
        case 8: _t->OnUpdatePosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->OnUpdateDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->OnItemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->OnTouchSearch(); break;
        case 12: _t->OnSearchResult((*reinterpret_cast< std::vector<tagMusicInfo>(*)>(_a[1]))); break;
        case 13: _t->OnSearchItemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->GetSongSrcFinish((*reinterpret_cast< SongInfo(*)>(_a[1]))); break;
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
