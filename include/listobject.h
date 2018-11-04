/*
 * =====================================================================================
 *
 *       Filename:  listobject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/21 14时20分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "object.h"

typedef struct {
        PyObject_VAR_HEAD
        // list[0] is ob_item[0], vector of pointers to list elements
        PyObject **ob_item;

        /* 
         * ob_item contains space for 'allocated' elements.
         * the number currently in use is ob_size.
         *
         * 0 <= ob_size <= allocated
         * len(list) == ob_size
         * ob_item == NULL implies ob_size == allocated == 0
         *
         * list.sort() temporarily sets allocated to -1 to detect mutations
         *
         * items must normally not NULL, except during construction when the list is not yet visible outside the function that builds it.*/
        Py_ssize_t allocated;
}PyListObject;


PyTypeObject PyList_Type;
PyTypeObject PyListIter_Type;
PyTypeObject PyListRevIter_Type;
PyTypeObject PYSortWrapper_Type;

PyObject * PyList_New(Py_ssize_t size);
Py_ssize_t PyList_Size(PyObject *);
PyObject * PyList_GetItem(PyObject*, Py_ssize_t);
int PyList_SetItem(PyObject *, Py_ssize_t, PyObject *);
int PyList_Insert(PyObject *, Py_ssize_t, PyObject *);
int PyList_Append(PyObject *, PyObject *);

PyObject * PyList_GetSlice(PyObject *, Py_ssize_t, Py_ssize_t);
int PyList_SetSlice(PyObject *, Py_ssize_t, Py_ssize_t, PyObject *);
int PyList_Sort(PyObject *);
int PyList_Reverse(Pyobject *);

PyOjbect * PyList_AsTuple(PyObject *);

Pyobject * PyList_ClearFreeList(void);

#define PyList_GET_ITEM(op, i) (((PyListObject *)(op)) -> ob_item[i])
#define PyList_SET_ITEM(op, i, v) (((PyListObject *) (op)) -> ob_item[i]=(v))
#define PyList_GET_SIZE(op) (assert(PyList_Check(op)), Py_SIZE(op))
#define _PyList_ITEMS(op) (((PyListObject *)(op)) -> ob_item)
