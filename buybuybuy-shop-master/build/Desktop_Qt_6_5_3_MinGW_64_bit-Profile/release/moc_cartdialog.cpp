/****************************************************************************
** Meta object code from reading C++ file 'cartdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../SCUT Store/cartdialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cartdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCartDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCartDialogENDCLASS = QtMocHelpers::stringData(
    "CartDialog",
    "delFromCart",
    "",
    "pay",
    "on_delB_clicked",
    "showCart",
    "showCount",
    "refresh",
    "on_cancelB_clicked",
    "on_payB_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCartDialogENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[16];
    char stringdata5[9];
    char stringdata6[10];
    char stringdata7[8];
    char stringdata8[19];
    char stringdata9[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCartDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCartDialogENDCLASS_t qt_meta_stringdata_CLASSCartDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "CartDialog"
        QT_MOC_LITERAL(11, 11),  // "delFromCart"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 3),  // "pay"
        QT_MOC_LITERAL(28, 15),  // "on_delB_clicked"
        QT_MOC_LITERAL(44, 8),  // "showCart"
        QT_MOC_LITERAL(53, 9),  // "showCount"
        QT_MOC_LITERAL(63, 7),  // "refresh"
        QT_MOC_LITERAL(71, 18),  // "on_cancelB_clicked"
        QT_MOC_LITERAL(90, 15)   // "on_payB_clicked"
    },
    "CartDialog",
    "delFromCart",
    "",
    "pay",
    "on_delB_clicked",
    "showCart",
    "showCount",
    "refresh",
    "on_cancelB_clicked",
    "on_payB_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCartDialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       3,    0,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   66,    2, 0x08,    4 /* Private */,
       5,    0,   67,    2, 0x08,    5 /* Private */,
       6,    0,   68,    2, 0x08,    6 /* Private */,
       7,    0,   69,    2, 0x08,    7 /* Private */,
       8,    0,   70,    2, 0x08,    8 /* Private */,
       9,    0,   71,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CartDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSCartDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCartDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCartDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CartDialog, std::true_type>,
        // method 'delFromCart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'pay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showCart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refresh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancelB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_payB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CartDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CartDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->delFromCart((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->pay(); break;
        case 2: _t->on_delB_clicked(); break;
        case 3: _t->showCart(); break;
        case 4: _t->showCount(); break;
        case 5: _t->refresh(); break;
        case 6: _t->on_cancelB_clicked(); break;
        case 7: _t->on_payB_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CartDialog::*)(int );
            if (_t _q_method = &CartDialog::delFromCart; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CartDialog::*)();
            if (_t _q_method = &CartDialog::pay; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *CartDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CartDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCartDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CartDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CartDialog::delFromCart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CartDialog::pay()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
