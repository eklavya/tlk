/****************************************************************************
** Meta object code from reading C++ file 'toc_window.h'
**
** Created: Mon Mar 19 22:30:04 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "toc_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toc_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TocWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x0a,
      44,   10,   10,   10, 0x0a,
      63,   10,   10,   10, 0x0a,
      89,   10,   10,   10, 0x0a,
     103,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TocWindow[] = {
    "TocWindow\0\0,\0newMsgArrived(QString,quint32)\0"
    "mousePressed(Pal*)\0palWindowClosed(QWidget*)\0"
    "refreshList()\0aboutTriggered()\0"
};

void TocWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TocWindow *_t = static_cast<TocWindow *>(_o);
        switch (_id) {
        case 0: _t->newMsgArrived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 1: _t->mousePressed((*reinterpret_cast< Pal*(*)>(_a[1]))); break;
        case 2: _t->palWindowClosed((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->refreshList(); break;
        case 4: _t->aboutTriggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TocWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TocWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TocWindow,
      qt_meta_data_TocWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TocWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TocWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TocWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TocWindow))
        return static_cast<void*>(const_cast< TocWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int TocWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
