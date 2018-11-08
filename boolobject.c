/*
 * =====================================================================================
 *
 *       Filename:  boolobject.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/11/08 16时47分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Python.h"
#include "longintrepr.h"

static PyObject *false_str = NULL;
static PyObject *true_str = NULL;

static PyObject * bool_repr(PyObject *self){}

PyObject *PyBool_FromLong(long ok){}
static PyObject * bool_new(PyTypeObject *type, PyObjec *args, PyObject *kwds){}

static PyObject * bool_and(PyObject *a, PyObject *b){}
static PyObject * bool_or(PyObject *a, PyObject *b){}
static PyObject * bool_xor(PyObject *a, PyObject *b){}

PyTypeObject PyBool_Type = {
        PyVarObject_HEAD_INIT(&PyType_Type, 0)
                "bool",

        sizeof(struct _longobject),
        0,  // tp_dealloc
        0,  // tp_print
        0,  // tp_getattr
        0,  // tp_setattr
        0,  // tp_reserved
        bool_repr,  // tp_repr
        &bool_as_number,    // tp_as_number
        0,      // tp_as_sequence
        0,  // tp_hash
        0,  // tp_call
        bool_repr,  // tp_str
        0,  // tp_getattro
        0,  // tp_setattro
        0,  // tp_flags
        Py_TPFLAGS_DEFAULT, // tp_flags
        bool_doc,   // tp_doc
        0,  // tp_traverse
        0,  // tp_clear
        0,  // tp_richcompare
        0,  // 
}
