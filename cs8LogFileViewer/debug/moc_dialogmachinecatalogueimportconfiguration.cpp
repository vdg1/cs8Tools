/****************************************************************************
** Meta object code from reading C++ file 'dialogmachinecatalogueimportconfiguration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../common/dialogmachinecatalogueimportconfiguration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogmachinecatalogueimportconfiguration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DialogMachineCatalogueImportConfiguration_t {
    QByteArrayData data[14];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogMachineCatalogueImportConfiguration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogMachineCatalogueImportConfiguration_t qt_meta_stringdata_DialogMachineCatalogueImportConfiguration = {
    {
QT_MOC_LITERAL(0, 0, 41), // "DialogMachineCatalogueImportC..."
QT_MOC_LITERAL(1, 42, 9), // "selectRow"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 3), // "row"
QT_MOC_LITERAL(4, 57, 23), // "on_cbWithHeader_toggled"
QT_MOC_LITERAL(5, 81, 4), // "arg1"
QT_MOC_LITERAL(6, 86, 16), // "selectionChanged"
QT_MOC_LITERAL(7, 103, 8), // "selected"
QT_MOC_LITERAL(8, 112, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(9, 134, 30), // "on_sbCustomerName_valueChanged"
QT_MOC_LITERAL(10, 165, 32), // "on_sbInternalNumber_valueChanged"
QT_MOC_LITERAL(11, 198, 23), // "on_sbUrlId_valueChanged"
QT_MOC_LITERAL(12, 222, 40), // "on_sbControllerSerialNumber_v..."
QT_MOC_LITERAL(13, 263, 33) // "on_sbArmSerialNumber_valueCha..."

    },
    "DialogMachineCatalogueImportConfiguration\0"
    "selectRow\0\0row\0on_cbWithHeader_toggled\0"
    "arg1\0selectionChanged\0selected\0"
    "on_buttonBox_accepted\0"
    "on_sbCustomerName_valueChanged\0"
    "on_sbInternalNumber_valueChanged\0"
    "on_sbUrlId_valueChanged\0"
    "on_sbControllerSerialNumber_valueChanged\0"
    "on_sbArmSerialNumber_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogMachineCatalogueImportConfiguration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       6,    2,   65,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      10,    1,   74,    2, 0x08 /* Private */,
      11,    1,   77,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    7,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void DialogMachineCatalogueImportConfiguration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogMachineCatalogueImportConfiguration *_t = static_cast<DialogMachineCatalogueImportConfiguration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_cbWithHeader_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 3: _t->on_buttonBox_accepted(); break;
        case 4: _t->on_sbCustomerName_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_sbInternalNumber_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_sbUrlId_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_sbControllerSerialNumber_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_sbArmSerialNumber_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DialogMachineCatalogueImportConfiguration::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogMachineCatalogueImportConfiguration.data,
      qt_meta_data_DialogMachineCatalogueImportConfiguration,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogMachineCatalogueImportConfiguration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogMachineCatalogueImportConfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogMachineCatalogueImportConfiguration.stringdata0))
        return static_cast<void*>(const_cast< DialogMachineCatalogueImportConfiguration*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogMachineCatalogueImportConfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
