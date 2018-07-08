/****************************************************************************
** Meta object code from reading C++ file 'cs8systemconfigurationmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cs8systemconfigurationmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cs8systemconfigurationmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cs8SystemConfigurationModel_t {
    QByteArrayData data[15];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cs8SystemConfigurationModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cs8SystemConfigurationModel_t qt_meta_stringdata_cs8SystemConfigurationModel = {
    {
QT_MOC_LITERAL(0, 0, 27), // "cs8SystemConfigurationModel"
QT_MOC_LITERAL(1, 28, 30), // "systemConfigurationSetDetected"
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 26), // "cs8SystemConfigurationSet*"
QT_MOC_LITERAL(4, 87, 9), // "completed"
QT_MOC_LITERAL(5, 97, 10), // "setLogData"
QT_MOC_LITERAL(6, 108, 13), // "logFileModel*"
QT_MOC_LITERAL(7, 122, 7), // "logData"
QT_MOC_LITERAL(8, 130, 14), // "setMachineInfo"
QT_MOC_LITERAL(9, 145, 8), // "customer"
QT_MOC_LITERAL(10, 154, 14), // "internalNumber"
QT_MOC_LITERAL(11, 169, 13), // "machineNumber"
QT_MOC_LITERAL(12, 183, 12), // "workingHours"
QT_MOC_LITERAL(13, 196, 5), // "clear"
QT_MOC_LITERAL(14, 202, 22) // "slotProcessingFinished"

    },
    "cs8SystemConfigurationModel\0"
    "systemConfigurationSetDetected\0\0"
    "cs8SystemConfigurationSet*\0completed\0"
    "setLogData\0logFileModel*\0logData\0"
    "setMachineInfo\0customer\0internalNumber\0"
    "machineNumber\0workingHours\0clear\0"
    "slotProcessingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cs8SystemConfigurationModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       8,    4,   51,    2, 0x0a /* Public */,
      13,    0,   60,    2, 0x0a /* Public */,
      14,    0,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cs8SystemConfigurationModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cs8SystemConfigurationModel *_t = static_cast<cs8SystemConfigurationModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->systemConfigurationSetDetected((*reinterpret_cast< cs8SystemConfigurationSet*(*)>(_a[1]))); break;
        case 1: _t->completed(); break;
        case 2: _t->setLogData((*reinterpret_cast< logFileModel*(*)>(_a[1]))); break;
        case 3: _t->setMachineInfo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 4: _t->clear(); break;
        case 5: _t->slotProcessingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< logFileModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cs8SystemConfigurationModel::*_t)(cs8SystemConfigurationSet * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cs8SystemConfigurationModel::systemConfigurationSetDetected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (cs8SystemConfigurationModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cs8SystemConfigurationModel::completed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject cs8SystemConfigurationModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_cs8SystemConfigurationModel.data,
      qt_meta_data_cs8SystemConfigurationModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cs8SystemConfigurationModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cs8SystemConfigurationModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cs8SystemConfigurationModel.stringdata0))
        return static_cast<void*>(const_cast< cs8SystemConfigurationModel*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int cs8SystemConfigurationModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void cs8SystemConfigurationModel::systemConfigurationSetDetected(cs8SystemConfigurationSet * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cs8SystemConfigurationModel::completed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
