/****************************************************************************
** Meta object code from reading C++ file 'addnewfriend.h'
**
** Created: Wed May 14 08:56:38 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addnewfriend.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addnewfriend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_addnewfriend[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   13,   13,   13, 0x0a,
      37,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_addnewfriend[] = {
    "addnewfriend\0\0addthis(QString)\0add()\0"
    "cancel()\0"
};

void addnewfriend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        addnewfriend *_t = static_cast<addnewfriend *>(_o);
        switch (_id) {
        case 0: _t->addthis((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->add(); break;
        case 2: _t->cancel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData addnewfriend::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject addnewfriend::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addnewfriend,
      qt_meta_data_addnewfriend, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &addnewfriend::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *addnewfriend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *addnewfriend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addnewfriend))
        return static_cast<void*>(const_cast< addnewfriend*>(this));
    return QDialog::qt_metacast(_clname);
}

int addnewfriend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void addnewfriend::addthis(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
