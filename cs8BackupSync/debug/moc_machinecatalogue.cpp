/****************************************************************************
** Meta object code from reading C++ file 'machinecatalogue.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../common/machinecatalogue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'machinecatalogue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_machineCatalogue_t {
    QByteArrayData data[14];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_machineCatalogue_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_machineCatalogue_t qt_meta_stringdata_machineCatalogue = {
    {
QT_MOC_LITERAL(0, 0, 16), // "machineCatalogue"
QT_MOC_LITERAL(1, 17, 31), // "setControllerSerialNumberColumn"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 3), // "arg"
QT_MOC_LITERAL(4, 54, 24), // "setArmSerialNumberColumn"
QT_MOC_LITERAL(5, 79, 21), // "setCustomerNameColumn"
QT_MOC_LITERAL(6, 101, 23), // "setInternalNumberColumn"
QT_MOC_LITERAL(7, 125, 14), // "setURLIdColumn"
QT_MOC_LITERAL(8, 140, 11), // "URLIdColumn"
QT_MOC_LITERAL(9, 152, 13), // "setWithHeader"
QT_MOC_LITERAL(10, 166, 28), // "controllerSerialNumberColumn"
QT_MOC_LITERAL(11, 195, 18), // "customerNameColumn"
QT_MOC_LITERAL(12, 214, 20), // "internalNumberColumn"
QT_MOC_LITERAL(13, 235, 10) // "withHeader"

    },
    "machineCatalogue\0setControllerSerialNumberColumn\0"
    "\0arg\0setArmSerialNumberColumn\0"
    "setCustomerNameColumn\0setInternalNumberColumn\0"
    "setURLIdColumn\0URLIdColumn\0setWithHeader\0"
    "controllerSerialNumberColumn\0"
    "customerNameColumn\0internalNumberColumn\0"
    "withHeader"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_machineCatalogue[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       5,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       9,    1,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,    3,

 // properties: name, type, flags
      10, QMetaType::UInt, 0x00095103,
      11, QMetaType::UInt, 0x00095103,
      12, QMetaType::UInt, 0x00095103,
       8, QMetaType::UInt, 0x00095103,
      13, QMetaType::Bool, 0x00095103,

       0        // eod
};

void machineCatalogue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        machineCatalogue *_t = static_cast<machineCatalogue *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setControllerSerialNumberColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setArmSerialNumberColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setCustomerNameColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setInternalNumberColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setURLIdColumn((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->setWithHeader((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        machineCatalogue *_t = static_cast<machineCatalogue *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->controllerSerialNumberColumn(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->customerNameColumn(); break;
        case 2: *reinterpret_cast< uint*>(_v) = _t->internalNumberColumn(); break;
        case 3: *reinterpret_cast< uint*>(_v) = _t->URLIdColumn(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->withHeader(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        machineCatalogue *_t = static_cast<machineCatalogue *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setControllerSerialNumberColumn(*reinterpret_cast< uint*>(_v)); break;
        case 1: _t->setCustomerNameColumn(*reinterpret_cast< uint*>(_v)); break;
        case 2: _t->setInternalNumberColumn(*reinterpret_cast< uint*>(_v)); break;
        case 3: _t->setURLIdColumn(*reinterpret_cast< uint*>(_v)); break;
        case 4: _t->setWithHeader(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject machineCatalogue::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_machineCatalogue.data,
      qt_meta_data_machineCatalogue,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *machineCatalogue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *machineCatalogue::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_machineCatalogue.stringdata0))
        return static_cast<void*>(const_cast< machineCatalogue*>(this));
    return QObject::qt_metacast(_clname);
}

int machineCatalogue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
