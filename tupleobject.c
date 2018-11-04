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

PyObject * PyTuple_New(Py_ssize_t size){}

Py_ssize_t PyTuple_Size(PyObject *op){}

PyObject * PyTuple_GetItem(PyObject *op, Py_ssize_t i){}

int PyTuple_SetItem(PyObject *op, Py_ssize_t i, PyObject *newitem){}


static void tupledealloc(PyTupleObject *op){}

static PyObject * tuplerepr(PyTupleObject *v){}

static Py_hash_t tuplehash(PyTupleObject *v){}

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
static PyObject * tuple_count(PyTupleObject *self, PyObject *value){}
static int tupletraverse(PyTupleObject *o, visitproc visit, void *arg){}
static PyObject * tuplerichcompare(PyObject *v, PyObject *w, int op){}

// tupe.__new__ as tuple_new
//      iterable: object(c_default="NULL") = ()
static PyObject * tuple_new_impl(PyTypeObject *type, PyObject *iterable){}


PyTyupeObject PyTuple_Type={
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

/* The following function breaks the notion that tuples are immutable:
 * it changes the size of a tuple
 * We get away with this only if there is only one moudule referencing the object.
 * You can also think of it as creating a new tuple object and destroying the old one, only more efficiently.
 * In any case, don't use this if the tuple may already be known to some other part of the code.*/

int _PyTuple_Resize(PyObject **pv, Py_ssize_t newsize){}
int PyTuple_ClearFreeList(void){}
void PyTuple_Fini(void){}
