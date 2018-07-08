/****************************************************************************
** Meta object code from reading C++ file 'dialogalternativeeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialogalternativeeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogalternativeeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DialogAlternativeEditor_t {
    QByteArrayData data[7];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogAlternativeEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogAlternativeEditor_t qt_meta_stringdata_DialogAlternativeEditor = {
    {
QT_MOC_LITERAL(0, 0, 23), // "DialogAlternativeEditor"
QT_MOC_LITERAL(1, 24, 31), // "on_leEditorFilePath_textChanged"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 4), // "arg1"
QT_MOC_LITERAL(4, 62, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(5, 84, 19), // "on_pbSelect_clicked"
QT_MOC_LITERAL(6, 104, 21) // "on_buttonBox_rejected"

    },
    "DialogAlternativeEditor\0"
    "on_leEditorFilePath_textChanged\0\0arg1\0"
    "on_buttonBox_accepted\0on_pbSelect_clicked\0"
    "on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogAlternativeEditor[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogAlternativeEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogAlternativeEditor *_t = static_cast<DialogAlternativeEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_leEditorFilePath_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_buttonBox_accepted(); break;
        case 2: _t->on_pbSelect_clicked(); break;
        case 3: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    }
}

const QMetaObject DialogAlternativeEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogAlternativeEditor.data,
      qt_meta_data_DialogAlternativeEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogAlternativeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogAlternativeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogAlternativeEditor.stringdata0))
        return static_cast<void*>(const_cast< DialogAlternativeEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogAlternativeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
