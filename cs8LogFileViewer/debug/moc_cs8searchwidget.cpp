/****************************************************************************
** Meta object code from reading C++ file 'cs8searchwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cs8searchwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cs8searchwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cs8SearchWidget_t {
    QByteArrayData data[12];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cs8SearchWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cs8SearchWidget_t qt_meta_stringdata_cs8SearchWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "cs8SearchWidget"
QT_MOC_LITERAL(1, 16, 12), // "lineSelected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "line"
QT_MOC_LITERAL(4, 35, 22), // "updateSearchParameters"
QT_MOC_LITERAL(5, 58, 26), // "on_toolButtonClear_clicked"
QT_MOC_LITERAL(6, 85, 33), // "on_lineEditSearchText_textCha..."
QT_MOC_LITERAL(7, 119, 10), // "searchText"
QT_MOC_LITERAL(8, 130, 24), // "slotSearchResultSelected"
QT_MOC_LITERAL(9, 155, 5), // "index"
QT_MOC_LITERAL(10, 161, 30), // "on_cbRegularExpression_toggled"
QT_MOC_LITERAL(11, 192, 7) // "checked"

    },
    "cs8SearchWidget\0lineSelected\0\0line\0"
    "updateSearchParameters\0"
    "on_toolButtonClear_clicked\0"
    "on_lineEditSearchText_textChanged\0"
    "searchText\0slotSearchResultSelected\0"
    "index\0on_cbRegularExpression_toggled\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cs8SearchWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x09 /* Protected */,
       6,    1,   49,    2, 0x09 /* Protected */,
       8,    1,   52,    2, 0x09 /* Protected */,
      10,    1,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void cs8SearchWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cs8SearchWidget *_t = static_cast<cs8SearchWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lineSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateSearchParameters(); break;
        case 2: _t->on_toolButtonClear_clicked(); break;
        case 3: _t->on_lineEditSearchText_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->slotSearchResultSelected((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_cbRegularExpression_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cs8SearchWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cs8SearchWidget::lineSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject cs8SearchWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cs8SearchWidget.data,
      qt_meta_data_cs8SearchWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cs8SearchWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cs8SearchWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cs8SearchWidget.stringdata0))
        return static_cast<void*>(const_cast< cs8SearchWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int cs8SearchWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void cs8SearchWidget::lineSelected(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
