/*
 * =====================================================================================
 *
 *       Filename:  listobject.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/21 14时02分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef PyList_MAXFREELIST
#define PyList_MAXFREELIST 80
#endif

#include "include/listobject.h"

static int list_resize(PyListObject *self, Py_ssize_t newsize){}


int PyList_ClearFreeList(void){}
void PyList_Fini(void){}

PyObject * PyList_New(Py_ssize_t size){}

Py_ssize_t PyList_Size(PyObject *op){}

PyObject * PyList_GetItem(PyObject *op, Py_ssize_t i ){}

int PyList_SetItem(PyObject *op, Py_ssize_t i,PyObject *newitem){}

static int ins1(PyListObject *self, Py_ssize_t where, PyObject *v){}

int PyList_Insert(PyObject *op, Py_ssize_t where, PyObject *newitem){}

static int app1(PyListObject *self, PyObject *v){}

int PyList_Append(PyObject *op, PyObject *newitem){}

static void list_dealloc(PylistObject *op){}
static PyObject * list_repr(PyListObject *v){}

static Py_ssize_t list_length(PyListObject *a, PyObject *el){}

static int list_contains(PyListObject *a, PyObject *el){}

static PyObject * list_item(PyListObject *a, Py_ssize_t){}

static PyObject * list_slice(PyListObject *a ,Py_ssize_t ilow, Py_ssize_t ihigh){}

PyObject * PyList_GetSlice(PyObject *a, Py_ssize_t ilow, Py_ssize_t ihigh){}

static PyObject * list_concat(PyLIstObject *a, PyOBject *bb){}

static PyObject * list_repeat(PyListObject *a, Py_ssize_t n){}

static int _list_clear(PyListObject *a){}

static int list_ass_slice(PyLIstObject *a, Py_ssize_t ilow, Py_ssize_t ihigh, PyObject *v){}

int PyList_SetSlice(PyObject *a, Py_ssize_t ilow, Py_ssize_t ihigh, PyObject *v){}

static PyObject * list_inplace_repeat(PyListObject *self, Py_ssize_t n){}

static int list_ass_item(PyListObject *a, Py_ssize_t i, PyObject *v){}

/* [clicnc input] */
// list.insert
//      index: Py_ssize_t
//      object: object
// Insert object before index
static PyObject * list_insert_impl(PyListObject *self, Py_ssize_t index, PyObject *object){}

// list.clear
// Remove all items from list
static PyObject * list_clear_impl(PyListObject *self){}

// list.copy
// Return a shallow copy of the list
static PyObject * list_copy_impl(PyListObject *self){}

// list.append
//      object: object 
//  Append object to the end of the list
static PyObject * list_append(PyListObject *self, PyObject *object){}

// list.extend
//      iterable: object
// Extend list by appending elements from the iterable
static PyObject * list_extend(PyListObject *self, PyObejct *iterable){}

PyObject * _PyList_Extend(PyListObject *self, PyObject *iterable){}
static PyObject * list_inplace_concat(PyListObject *self, PyObject *other){}

// list.pop
//      index: Py_ssize_t = -1
//  Remove and return item at index (default last)
//  Raises IndexError if list is empty or index is out of range
static PyObject * list_pop_impl(PyListObject *self, Py_ssize_t index){}

// Reverse a slice of a list in place, from lo up to (exclusive) hi

static void reverse_slice(PyObject **lo, PYObject **hi){}

// list.reverse
//  Reverse 
static PyObject * list_reverse_impl(PyListObject *self){}
int PyListReverse(PyObject *v){}

PyObject * PyList_AsTuple(PyObject *v){}

// list.index
//      value: object 
//      start: slice_index(accept={int}) = 0
//      stop: slice_index(accept={int}, c_default="PY_SSIZE_T_MAX")=sys.maxsize
// Return first index of value
// Raise ValueError if the value is not present
static PyObject * list_index_impl(PyListObject *self, PyObject *value, Py_ssize_t start, Py_ssize_t stop){}

// list.count
//      value: object
// Return number of occurrences of value
static PyObject * list_count(PyListObject *self, PyObject *value){}

//list.remove
//      value: object
// Remove first occurence of value
// Raise ValueError if the value is not present
static PyObject * list_remove(PyListObject *self, PyObject *value){}

static int list_traverse(PyListObject *o, visitproc visit, void *arg){}

static PyObject * list_richcompare(PyObject *v, PyObject *w, int op){}

// list.__init__
//      iterable: object(c_default="NULL") = ()
// Built_in mutable sequence
static int list___init___impl(PyListObject *self, PyObject *iterable){}

// list.__sizeof__
// Return the size of the list in memory, in bytes
static PyObject * list___sizeof___impl(PyListObject *self){}

PyTypeObject PyList_Type = {
        PyVarObject_HEAD_INIT(&PyType_Type, 0)
                "list",
        sizeof(PyListObject),
        0,
        (destructor)list_dealloc, // tp_dealloc
        0,  // tp_print
        0,  // tp_getattr
        0,  // tp_setattr
        0,  // tp_reserved
        (reprfunc)list_repr,    // tp_repr
        0,  // tp_as_number
        &list_as_sequence,  //tp_as_sequence
        &list_as_mapping,   // tp_as_mapping
        PyObject_HashNotImplemented,    // tp_hash
        0,  // tp_call
        0,  // tp_str
        PyObject_GenericGetAttr,    // tp_getattro
        0,  // tp_setattro
        0,  // tp_as_buffer
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_LIST_SUBCLASS,   //tp_flags
        list___init___doc__,    // tp_doc
        (traverseproc)list_traverse,    // tp_traverse
        (inquiry)_list_clear,   // tp_clear
        list_richcompare,   // tp_richcompare
        0,  //tp_weaklistoffset
        list_iter,  // tp_iter
        0,  // tp_iternext
        list_methods,   // tp_methods
        0,  // tp_members
        0,  //tp_getset
        0,  //tp_base
        0,  //tp_dict
        0,  // tp_descr_get
        0,  // tp_descr_set
        0,  // tp_dictoffset
        (initproc)list___init__,    // tp_init
        PyType_GenericAlloc,    //tp_alloc
        PyType_GenericNew,  // tp_new
        PyObject_GC_Del,    // tp_free
};

               

