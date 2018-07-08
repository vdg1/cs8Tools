/****************************************************************************
** Meta object code from reading C++ file 'dialoghighlightconfiguration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialoghighlightconfiguration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialoghighlightconfiguration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_highlightItemList_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_highlightItemList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_highlightItemList_t qt_meta_stringdata_highlightItemList = {
    {
QT_MOC_LITERAL(0, 0, 17) // "highlightItemList"

    },
    "highlightItemList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_highlightItemList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void highlightItemList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject highlightItemList::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_highlightItemList.data,
      qt_meta_data_highlightItemList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *highlightItemList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *highlightItemList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_highlightItemList.stringdata0))
        return static_cast<void*>(const_cast< highlightItemList*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int highlightItemList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_DialogHighLightConfiguration_t {
    QByteArrayData data[20];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogHighLightConfiguration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogHighLightConfiguration_t qt_meta_stringdata_DialogHighLightConfiguration = {
    {
QT_MOC_LITERAL(0, 0, 28), // "DialogHighLightConfiguration"
QT_MOC_LITERAL(1, 29, 20), // "on_pbAddItem_clicked"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 23), // "on_pdRemoveItem_clicked"
QT_MOC_LITERAL(4, 75, 19), // "on_pdMoveUp_clicked"
QT_MOC_LITERAL(5, 95, 14), // "slotRowChanged"
QT_MOC_LITERAL(6, 110, 5), // "index"
QT_MOC_LITERAL(7, 116, 15), // "slotDataChanged"
QT_MOC_LITERAL(8, 132, 4), // "from"
QT_MOC_LITERAL(9, 137, 15), // "slotItemChanged"
QT_MOC_LITERAL(10, 153, 14), // "QStandardItem*"
QT_MOC_LITERAL(11, 168, 4), // "item"
QT_MOC_LITERAL(12, 173, 19), // "on_pbSubmit_clicked"
QT_MOC_LITERAL(13, 193, 17), // "on_cbBold_clicked"
QT_MOC_LITERAL(14, 211, 19), // "on_cbItalic_clicked"
QT_MOC_LITERAL(15, 231, 32), // "on_lbForegroundColor_textChanged"
QT_MOC_LITERAL(16, 264, 32), // "on_lbBackgroundColor_textChanged"
QT_MOC_LITERAL(17, 297, 4), // "arg1"
QT_MOC_LITERAL(18, 302, 21), // "on_pdMoveDown_clicked"
QT_MOC_LITERAL(19, 324, 30) // "on_cbLevel_currentIndexChanged"

    },
    "DialogHighLightConfiguration\0"
    "on_pbAddItem_clicked\0\0on_pdRemoveItem_clicked\0"
    "on_pdMoveUp_clicked\0slotRowChanged\0"
    "index\0slotDataChanged\0from\0slotItemChanged\0"
    "QStandardItem*\0item\0on_pbSubmit_clicked\0"
    "on_cbBold_clicked\0on_cbItalic_clicked\0"
    "on_lbForegroundColor_textChanged\0"
    "on_lbBackgroundColor_textChanged\0arg1\0"
    "on_pdMoveDown_clicked\0"
    "on_cbLevel_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogHighLightConfiguration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    2,   85,    2, 0x08 /* Private */,
       9,    1,   90,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    1,   96,    2, 0x08 /* Private */,
      16,    1,   99,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    1,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    8,    2,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void DialogHighLightConfiguration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogHighLightConfiguration *_t = static_cast<DialogHighLightConfiguration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pbAddItem_clicked(); break;
        case 1: _t->on_pdRemoveItem_clicked(); break;
        case 2: _t->on_pdMoveUp_clicked(); break;
        case 3: _t->slotRowChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->slotDataChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->slotItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 6: _t->on_pbSubmit_clicked(); break;
        case 7: _t->on_cbBold_clicked(); break;
        case 8: _t->on_cbItalic_clicked(); break;
        case 9: _t->on_lbForegroundColor_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_lbBackgroundColor_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_pdMoveDown_clicked(); break;
        case 12: _t->on_cbLevel_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DialogHighLightConfiguration::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogHighLightConfiguration.data,
      qt_meta_data_DialogHighLightConfiguration,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogHighLightConfiguration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogHighLightConfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogHighLightConfiguration.stringdata0))
        return static_cast<void*>(const_cast< DialogHighLightConfiguration*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogHighLightConfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
