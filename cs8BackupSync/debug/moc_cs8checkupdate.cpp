/****************************************************************************
** Meta object code from reading C++ file 'cs8checkupdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../common/cs8checkupdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cs8checkupdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cs8CheckUpdate_t {
    QByteArrayData data[18];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cs8CheckUpdate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cs8CheckUpdate_t qt_meta_stringdata_cs8CheckUpdate = {
    {
QT_MOC_LITERAL(0, 0, 14), // "cs8CheckUpdate"
QT_MOC_LITERAL(1, 15, 14), // "checkCompleted"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "updates"
QT_MOC_LITERAL(4, 39, 8), // "versions"
QT_MOC_LITERAL(5, 48, 5), // "error"
QT_MOC_LITERAL(6, 54, 15), // "checkForUpdates"
QT_MOC_LITERAL(7, 70, 15), // "notifyOnSuccess"
QT_MOC_LITERAL(8, 86, 13), // "notifyOnError"
QT_MOC_LITERAL(9, 100, 18), // "enableRegularCheck"
QT_MOC_LITERAL(10, 119, 13), // "intervalInMin"
QT_MOC_LITERAL(11, 133, 12), // "slotFinished"
QT_MOC_LITERAL(12, 146, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(13, 167, 10), // "exitStatus"
QT_MOC_LITERAL(14, 178, 9), // "slotError"
QT_MOC_LITERAL(15, 188, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(16, 211, 18), // "slotCheckCompleted"
QT_MOC_LITERAL(17, 230, 14) // "slotCheckTimer"

    },
    "cs8CheckUpdate\0checkCompleted\0\0updates\0"
    "versions\0error\0checkForUpdates\0"
    "notifyOnSuccess\0notifyOnError\0"
    "enableRegularCheck\0intervalInMin\0"
    "slotFinished\0QProcess::ExitStatus\0"
    "exitStatus\0slotError\0QProcess::ProcessError\0"
    "slotCheckCompleted\0slotCheckTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cs8CheckUpdate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   71,    2, 0x0a /* Public */,
       6,    1,   76,    2, 0x2a /* Public | MethodCloned */,
       6,    0,   79,    2, 0x2a /* Public | MethodCloned */,
       9,    1,   80,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x2a /* Public | MethodCloned */,
      11,    2,   84,    2, 0x09 /* Protected */,
      14,    1,   89,    2, 0x09 /* Protected */,
      16,    3,   92,    2, 0x09 /* Protected */,
      17,    0,   99,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,    2,   13,
    QMetaType::Void, 0x80000000 | 15,    5,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool,    3,    4,    5,
    QMetaType::Void,

       0        // eod
};

void cs8CheckUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cs8CheckUpdate *_t = static_cast<cs8CheckUpdate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkCompleted((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->checkForUpdates((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 2: _t->checkForUpdates((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 3: _t->checkForUpdates(); break;
        case 4: _t->enableRegularCheck((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->enableRegularCheck(); break;
        case 6: _t->slotFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 7: _t->slotError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 8: _t->slotCheckCompleted((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 9: _t->slotCheckTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cs8CheckUpdate::*_t)(const QStringList & , const QStringList & , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cs8CheckUpdate::checkCompleted)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject cs8CheckUpdate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cs8CheckUpdate.data,
      qt_meta_data_cs8CheckUpdate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cs8CheckUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cs8CheckUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cs8CheckUpdate.stringdata0))
        return static_cast<void*>(const_cast< cs8CheckUpdate*>(this));
    return QObject::qt_metacast(_clname);
}

int cs8CheckUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void cs8CheckUpdate::checkCompleted(const QStringList & _t1, const QStringList & _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
