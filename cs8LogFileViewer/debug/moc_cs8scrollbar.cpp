/****************************************************************************
** Meta object code from reading C++ file 'cs8scrollbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cs8scrollbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cs8scrollbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cs8ScrollBar_t {
    QByteArrayData data[10];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cs8ScrollBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cs8ScrollBar_t qt_meta_stringdata_cs8ScrollBar = {
    {
QT_MOC_LITERAL(0, 0, 12), // "cs8ScrollBar"
QT_MOC_LITERAL(1, 13, 12), // "addHighlight"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "row"
QT_MOC_LITERAL(4, 31, 8), // "totalRow"
QT_MOC_LITERAL(5, 40, 5), // "brush"
QT_MOC_LITERAL(6, 46, 14), // "resetHighlight"
QT_MOC_LITERAL(7, 61, 18), // "completedHighlight"
QT_MOC_LITERAL(8, 80, 17), // "reverseHighlights"
QT_MOC_LITERAL(9, 98, 7) // "reverse"

    },
    "cs8ScrollBar\0addHighlight\0\0row\0totalRow\0"
    "brush\0resetHighlight\0completedHighlight\0"
    "reverseHighlights\0reverse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cs8ScrollBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x0a /* Public */,
       7,    0,   42,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QBrush,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void cs8ScrollBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cs8ScrollBar *_t = static_cast<cs8ScrollBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addHighlight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QBrush(*)>(_a[3]))); break;
        case 1: _t->resetHighlight(); break;
        case 2: _t->completedHighlight(); break;
        case 3: _t->reverseHighlights((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject cs8ScrollBar::staticMetaObject = {
    { &QScrollBar::staticMetaObject, qt_meta_stringdata_cs8ScrollBar.data,
      qt_meta_data_cs8ScrollBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cs8ScrollBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cs8ScrollBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cs8ScrollBar.stringdata0))
        return static_cast<void*>(const_cast< cs8ScrollBar*>(this));
    return QScrollBar::qt_metacast(_clname);
}

int cs8ScrollBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
