/****************************************************************************
** Meta object code from reading C++ file 'cs8logfiledata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cs8logfiledata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cs8logfiledata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cs8LogFileData_t {
    QByteArrayData data[15];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cs8LogFileData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cs8LogFileData_t qt_meta_stringdata_cs8LogFileData = {
    {
QT_MOC_LITERAL(0, 0, 14), // "cs8LogFileData"
QT_MOC_LITERAL(1, 15, 4), // "load"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "QFile*"
QT_MOC_LITERAL(4, 28, 4), // "file"
QT_MOC_LITERAL(5, 33, 8), // "FileType"
QT_MOC_LITERAL(6, 42, 9), // "CS8Legacy"
QT_MOC_LITERAL(7, 52, 3), // "CS8"
QT_MOC_LITERAL(8, 56, 3), // "CS9"
QT_MOC_LITERAL(9, 60, 12), // "MessageLevel"
QT_MOC_LITERAL(10, 73, 8), // "Anything"
QT_MOC_LITERAL(11, 82, 11), // "Information"
QT_MOC_LITERAL(12, 94, 7), // "Warning"
QT_MOC_LITERAL(13, 102, 5), // "Error"
QT_MOC_LITERAL(14, 108, 9) // "Undefined"

    },
    "cs8LogFileData\0load\0\0QFile*\0file\0"
    "FileType\0CS8Legacy\0CS8\0CS9\0MessageLevel\0"
    "Anything\0Information\0Warning\0Error\0"
    "Undefined"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cs8LogFileData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       2,   22, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // enums: name, flags, count, data
       5, 0x0,    3,   30,
       9, 0x0,    5,   36,

 // enum data: key, value
       6, uint(cs8LogFileData::CS8Legacy),
       7, uint(cs8LogFileData::CS8),
       8, uint(cs8LogFileData::CS9),
      10, uint(cs8LogFileData::Anything),
      11, uint(cs8LogFileData::Information),
      12, uint(cs8LogFileData::Warning),
      13, uint(cs8LogFileData::Error),
      14, uint(cs8LogFileData::Undefined),

       0        // eod
};

void cs8LogFileData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cs8LogFileData *_t = static_cast<cs8LogFileData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        }
    }
}

const QMetaObject cs8LogFileData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cs8LogFileData.data,
      qt_meta_data_cs8LogFileData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cs8LogFileData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cs8LogFileData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cs8LogFileData.stringdata0))
        return static_cast<void*>(const_cast< cs8LogFileData*>(this));
    return QObject::qt_metacast(_clname);
}

int cs8LogFileData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
