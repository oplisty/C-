/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../SCUT Store/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_userB_clicked",
    "",
    "on_addB_clicked",
    "on_cartB_clicked",
    "removeFromCart",
    "index",
    "on_bankB_clicked",
    "readCards",
    "payCart",
    "payOK",
    "payAbort",
    "on_boughtB_clicked",
    "on_categoryButtonClicked",
    "id",
    "setupMainCategoryButtons",
    "on_subcategoryButtonClicked",
    "on_searchButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[17];
    char stringdata5[15];
    char stringdata6[6];
    char stringdata7[17];
    char stringdata8[10];
    char stringdata9[8];
    char stringdata10[6];
    char stringdata11[9];
    char stringdata12[19];
    char stringdata13[25];
    char stringdata14[3];
    char stringdata15[25];
    char stringdata16[28];
    char stringdata17[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 16),  // "on_userB_clicked"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 15),  // "on_addB_clicked"
        QT_MOC_LITERAL(45, 16),  // "on_cartB_clicked"
        QT_MOC_LITERAL(62, 14),  // "removeFromCart"
        QT_MOC_LITERAL(77, 5),  // "index"
        QT_MOC_LITERAL(83, 16),  // "on_bankB_clicked"
        QT_MOC_LITERAL(100, 9),  // "readCards"
        QT_MOC_LITERAL(110, 7),  // "payCart"
        QT_MOC_LITERAL(118, 5),  // "payOK"
        QT_MOC_LITERAL(124, 8),  // "payAbort"
        QT_MOC_LITERAL(133, 18),  // "on_boughtB_clicked"
        QT_MOC_LITERAL(152, 24),  // "on_categoryButtonClicked"
        QT_MOC_LITERAL(177, 2),  // "id"
        QT_MOC_LITERAL(180, 24),  // "setupMainCategoryButtons"
        QT_MOC_LITERAL(205, 27),  // "on_subcategoryButtonClicked"
        QT_MOC_LITERAL(233, 23)   // "on_searchButton_clicked"
    },
    "MainWindow",
    "on_userB_clicked",
    "",
    "on_addB_clicked",
    "on_cartB_clicked",
    "removeFromCart",
    "index",
    "on_bankB_clicked",
    "readCards",
    "payCart",
    "payOK",
    "payAbort",
    "on_boughtB_clicked",
    "on_categoryButtonClicked",
    "id",
    "setupMainCategoryButtons",
    "on_subcategoryButtonClicked",
    "on_searchButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    1,  101,    2, 0x08,    4 /* Private */,
       7,    0,  104,    2, 0x08,    6 /* Private */,
       8,    0,  105,    2, 0x08,    7 /* Private */,
       9,    0,  106,    2, 0x08,    8 /* Private */,
      10,    0,  107,    2, 0x08,    9 /* Private */,
      11,    0,  108,    2, 0x08,   10 /* Private */,
      12,    0,  109,    2, 0x08,   11 /* Private */,
      13,    1,  110,    2, 0x08,   12 /* Private */,
      15,    0,  113,    2, 0x08,   14 /* Private */,
      16,    1,  114,    2, 0x08,   15 /* Private */,
      17,    0,  117,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_userB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cartB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeFromCart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_bankB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readCards'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'payCart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'payOK'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'payAbort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_boughtB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_categoryButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setupMainCategoryButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_subcategoryButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_searchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_userB_clicked(); break;
        case 1: _t->on_addB_clicked(); break;
        case 2: _t->on_cartB_clicked(); break;
        case 3: _t->removeFromCart((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_bankB_clicked(); break;
        case 5: _t->readCards(); break;
        case 6: _t->payCart(); break;
        case 7: _t->payOK(); break;
        case 8: _t->payAbort(); break;
        case 9: _t->on_boughtB_clicked(); break;
        case 10: _t->on_categoryButtonClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->setupMainCategoryButtons(); break;
        case 12: _t->on_subcategoryButtonClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_searchButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
