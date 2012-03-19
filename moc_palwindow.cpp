/****************************************************************************
** Meta object code from reading C++ file 'palwindow.h'
**
** Created: Mon Mar 19 22:30:02 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "palwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'palwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PalWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PalWindow[] = {
    "PalWindow\0\0windowClosed(QWidget*)\0"
    "msgSent()\0"
};

void PalWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PalWindow *_t = static_cast<PalWindow *>(_o);
        switch (_id) {
        case 0: _t->windowClosed((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->msgSent(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PalWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PalWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PalWindow,
      qt_meta_data_PalWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PalWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PalWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PalWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PalWindow))
        return static_cast<void*>(const_cast< PalWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int PalWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PalWindow::windowClosed(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
