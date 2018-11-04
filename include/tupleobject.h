/*
 * =====================================================================================
 *
 *       Filename:  tupleobject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/11/04 18时31分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "object.h"

type struct {
        PyObject_VAR_HEAD
        PyObject *ob_item[1];
}PyTupleObject;

PyTypeObject PyTuple_Type;

PyObject * PyTuple_New(Py_ssize_t size);
Py_ssize_t PyTuple_Size(PyObject *);
PyObject * PyTuple_GetItem(PyObject *, Py_ssize_t);
int PyTuple_SetItem(PyObject *, Py_ssize_t, Py_ssize_t);
PyObject * PyTuple_GetSlice(PyObject *, Py_ssize_t, Py_ssize_t);
int PyTupele_Resize(PyObject **, Py_ssize_t);
PyObject * PyTuple_Pack(Py_ssize_t, ...);
void _PyTuple_MaybeUntrack(PyObject *);

#define PyTuple_GET_ITEM(op, i) (((PyTupleObject *)(op)) -> ob_item[i])
#define PyTuple_GET_SIZE(op)    (assert(PyTuple_Check(op)), Py_SIZE(op))

#define PyTuple_SET_ITEM(op, i, v) (((PyTupleObject *)(op)) -> ob_item[i] = v)

int PyTuple_ClearFreeList(void);
