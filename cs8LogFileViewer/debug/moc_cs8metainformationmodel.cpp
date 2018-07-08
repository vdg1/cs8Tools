/****************************************************************************
** Meta object code from reading C++ file 'cs8metainformationmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cs8metainformationmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cs8metainformationmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cs8MetaInformationModel_t {
    QByteArrayData data[10];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cs8MetaInformationModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cs8MetaInformationModel_t qt_meta_stringdata_cs8MetaInformationModel = {
    {
QT_MOC_LITERAL(0, 0, 23), // "cs8MetaInformationModel"
QT_MOC_LITERAL(1, 24, 18), // "informationUpdated"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 3), // "row"
QT_MOC_LITERAL(4, 48, 24), // "metaInformationAvailable"
QT_MOC_LITERAL(5, 73, 36), // "slotProcessingConfigurationsF..."
QT_MOC_LITERAL(6, 110, 12), // "Preselection"
QT_MOC_LITERAL(7, 123, 5), // "Unset"
QT_MOC_LITERAL(8, 129, 3), // "Yes"
QT_MOC_LITERAL(9, 133, 2) // "No"

    },
    "cs8MetaInformationModel\0informationUpdated\0"
    "\0row\0metaInformationAvailable\0"
    "slotProcessingConfigurationsFinished\0"
    "Preselection\0Unset\0Yes\0No"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cs8MetaInformationModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       1,   34, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   33,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // enums: name, flags, count, data
       6, 0x0,    3,   38,

 // enum data: key, value
       7, uint(cs8MetaInformationModel::Unset),
       8, uint(cs8MetaInformationModel::Yes),
       9, uint(cs8MetaInformationModel::No),

       0        // eod
};

void cs8MetaInformationModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cs8MetaInformationModel *_t = static_cast<cs8MetaInformationModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->informationUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->metaInformationAvailable(); break;
        case 2: _t->slotProcessingConfigurationsFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cs8MetaInformationModel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cs8MetaInformationModel::informationUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (cs8MetaInformationModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cs8MetaInformationModel::metaInformationAvailable)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject cs8MetaInformationModel::staticMetaObject = {
    { &QSqlTableModel::staticMetaObject, qt_meta_stringdata_cs8MetaInformationModel.data,
      qt_meta_data_cs8MetaInformationModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cs8MetaInformationModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cs8MetaInformationModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cs8MetaInformationModel.stringdata0))
        return static_cast<void*>(const_cast< cs8MetaInformationModel*>(this));
    return QSqlTableModel::qt_metacast(_clname);
}

int cs8MetaInformationModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void cs8MetaInformationModel::informationUpdated(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cs8MetaInformationModel::metaInformationAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
