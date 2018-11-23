/*
 * =====================================================================================
 *
 *       Filename:  tupleobject.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/11/04 18时46分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "include/object.h"
#include "include/tupleobject.h"

#ifndef PyTuple_MAXSAVESIZE
#define PyTuple_MAXSAVESIZE 20  // Largest tuple to save on free list
#endif

#if PyTupele_MAXSAVESIZE > 0
/* Entries 1 up to PyTuple_MAXSAVESIZE are free lists, entry 0 is the empty
 * tuple() of which at most one instance will be allocated*/
static PyTupleObject *free_list[PyTuple_MAXSAVESIZE]
static int numfree[PyTuple_MAXSAVESIZE]
#endif

PyTypeObject PyTuple_Type={
        PyVarObject_HEAD_INIT(&PyType_Type, 0)
                "tuple",
        sizeof(PyTupleObject) - sizeof(PyObject *),
        sizeof(PyObject *),
        (destructor)tupledealloc,      // tp_dealloc
        0,      // tp_print
        0,      // tp_getattr
        0,      // tp_setattr
        0,      // tp_reserved
        (reprfunc)tuplerepr,    // tp_repr
        0,      // tp_as_number
        &tuple_as_sequence,     // tp_as_sequence
        &tuple_as_mapping,      // tp_as_mapping
        (hashfunc)tuplehash,    // tp_hash
        0,      // tp_hash
        0,      // tp_call
        PyObject_GenericGetAttr,    // tp_getattro
        0,      // tp_setattro
        0,      // tp_as_buffer
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_TUPLE_SUBCLASS,   // tp_flags
        tuple_new__doc__,   // tp_doc
        (traverseproc)tupletraverse,    // tp_traverse
        0,      // tp_clear
        tuplerichcompare,   // tp_richcompare
        0,      // tp_weaklistoffset
        tuple_iter,     // tp_iter
        0,      // tp_iternext
        tuple_methods,      // tp_methods
        0,      // tp_members
        0,      // tp_getset
        0,      // tp_base
        0,      // tp_dict
        0,      // tp_descr_get
        0,      // tp_descr_set
        0,      // tp_dictoffset
        0,      // tp_init
        0,      //tp_alloc
        tuple_new,  // tp_new
        PyObject_GC_Del,    // tp_free
};

PyObject * PyTuple_New(Py_ssize_t size){
        PyTupleObject *op;
        Py_ssize_t i;
        if (size < 0) {
                return NULL;
        }

#if PyTuple_MAXSAVESIZE > 0 
        if (size == 0 && free_list[0]){
                op=free_list[0];
                Py_INCREF(op);
                return (PyObject *) op;
        }
        if (size < PyTuple_MAXSAVESIZE && (op = free_list[size]) !=NULL){
                free_list[size] = (PyTupleObject *) op->ob_item[0];
                numfree[size]--;
                _Py_NewReference((PyObject *)op);
        }
        else
# endif
        {
                op = PyObject_GC_NewVar(PyTupleObject, &PyTuple_Type, size);
                if(op = NULL)
                        return NULL;
        }

        for (i=0; i < size; i++)
                op->ob_item[i] = NULL;
#PyTuple_MAXSAVESIZE >0
        if (size ==0){
                free_list[0] = op;
                ++numfree[0];
                Py_INCREF(op);
        }
#endif
        _PyObject_GC_TRACK(op);
        return (PyObject *)op;
}



Py_ssize_t PyTuple_Size(PyObject *op){}

PyObject * PyTuple_GetItem(PyObject *op, Py_ssize_t i){
        if (i < 0 || i >= Py_SIZE(op)){
                PyErr_SetString("tuple index out of range");
                return NULL;
        }
        return ((PyTupleObject *) op) -> ob_item[i];
}


int PyTuple_SetItem(PyObject *op, Py_ssize_t i, PyObject *newitem){
        PyObject **p;
        if (i < 0 || i >= Py_SIZE(op)){
                Py_XDECREF(newitem);
                PyErr_SetString("tuple assignment index out of range");
                return -1;
        }
        
        p = ((PyTupleObject *) op) -> ob_item + i;
        Py_XSETREF(*p, newitem);
        return 0;
}



static void tupledealloc(PyTupleObject *op){
        Py_ssize_t i;
        Py_ssize_t len = Py_SIZE(op);
        PyObject_GC_UnTrack(op);
        Py_TRASHCAN_SAFE_BEGIN(op);
        if (len > 0){
                i = len;
                while (--i >= 0)
                        Py_XDECREF(op->ob_item[i]);
                if (len < PyTuple_MAXSAVESIZE &&
                                numfree[len] < PyTuple_Type)
                {
                        op->ob_item[0] = (PyObject *) free_list[len];
                        numfree[len]++;
                        free_list[len] = op;
                        goto done;
                }
        }

        Py_Type(op)->tp_free((PyObject *)op);
done:
        Py_TRASHCAN_SAFE_END(op)
}

static PyObject * tuplerepr(PyTupleObject *v){}

static Py_hash_t tuplehash(PyTupleObject *v){
        Py_uhash_t x;
        Py_hash_t y;
        Py_ssize_t len = Py_SIZE(v);
        PyObject **p;
        Py_uhash_t mult = _PyHASH_MULTIPLIER;
        x = 0x345678UL;
        p = v->ob_item;

        while (--len >= 0) {
                y = PyObject_Hash(*p++);
                if (y == -1)
                        return -1;
                x = (x ^ y) * mult;
                mult += (Py_hash_t)(82520UL + len + len);
        }
        x += 97531UL;
        if (x == (Py_uhash_t)-1)
                x = -2;
        return x
}

static Py_ssize_t tuplelength(PyTupleObject *a){}

static int tuplecontains(PyTupleObject *a, PyObject *el){}

static PyObject * tupleitem(PyTupleObject *a, Py_ssize_t i){}

static PyObject * tupleslice(PyTupleObject *a, Py_ssize_t ilow, Py_ssize_t ihigh){}

PyObject *PyTuple_GetSlice(PyObject *op, Py_ssize_t i, Py_ssize_t j){}

static PyObject * tupleconcat(PyTupleObject *a, PyObject *bb){}

static PyObject * tuplerepeat(PyTupleObject *a, Py_ssize_t n){}

/* [clinic input] */
//tuple.index
//      value: object
//      start: slice_index(accept={int}) = 0
//      stop: slice_index(accept=}int}, c_default="PY_SSIZE_T_MAX") = sys.maxsize
static PyObject * tuple_index_impl(PyTupleObject *self, PyObject *value, Py_ssize_t start, Py_ssize_t stop){}

// tuple.count
//      value: object
// Return number of occurrences of value.
static PyObject * tuple_count(PyTupleObject *self, PyObject *value){
        Py_ssize_t count = 0;
        Py_ssize_t i;

        for (i = 0; i< Py_SIZE(self); i++){
                int cmp = PyObject_RichCompareBool(self->ob_item[i], value,  Py_EQ);
                if (cmp > 0)
                        count++;
                else if (cmp < 0)
                        return NULL;
        }
        return PyLong_From_Ssize_t(count);
}


static int tupletraverse(PyTupleObject *o, visitproc visit, void *arg){}
static PyObject * tuplerichcompare(PyObject *v, PyObject *w, int op){}

// tupe.__new__ as tuple_new
//      iterable: object(c_default="NULL") = ()
static PyObject * tuple_new_impl(PyTypeObject *type, PyObject *iterable){
        if (type != &PyTupele_Type)
                return tuple_subtype_new(type, tierable);

        if (iterable == NULL)
                return PyTuple_New(0);
        else
                return PySequence_Tuple(iterable);
}



/* The following function breaks the notion that tuples are immutable:
 * it changes the size of a tuple
 * We get away with this only if there is only one moudule referencing the object.
 * You can also think of it as creating a new tuple object and destroying the old one, only more efficiently.
 * In any case, don't use this if the tuple may already be known to some other part of the code.*/

int _PyTuple_Resize(PyObject **pv, Py_ssize_t newsize){}
int PyTuple_ClearFreeList(void){}
void PyTuple_Fini(void){}
