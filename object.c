/*
 * =====================================================================================
 *
 *       Filename:  object.c
 *
 *    Description:  Small Python object
 *
 *        Version:  1.0
 *        Created:  2018/08/16 21时27分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Python.h"

void Py_IncRef(PyObject *o){}
void Py_DecRef(PyObject *o){}

PyObject * PyObject_Init(PyObject *op, PyTypeObject *tp){}
PyVarObject * PyObject_InitVar(PyVarobject *op, PyTypeObject *tp, Py_ssize_t size){}

PyObject * _PyObject_New(PyTypeObject *tp){}

PyVarObject * _PyObject_NewVar(PyTypeObject *tp, Py_ssize_t nitems){}
void PyObject_CallFinalizer(PyObject *self){}

int PyObject_CallFinalizerFromDealloc(PyObject *self){}

int PyObject_Print(PyObject *op, FILE *fp, int flags){}

PyObject * PyObject_Repr(PyObject *v){}

PyObject * PyObject_Str(PyObject *v){}

PyObject * PyObject_ASCII(PyObject *v){}

PyObject * PyObject_Bytes(PyObject *v){}

Py_hash_t PyObject_HashNotImplemented(PyObject *v){}

Py_hash_t PyObject_Hash(PyObject *v){}

PyObject *PyObject_GetAttrString(PytObject *v, const char *name){}

int PyObject_HasAttrString(PyObject *v, const char *name){}

int PyObject_SetAttrString(PyObject *v, const char *name, Pyobject *w){}
int _PyObject_IsAbstract(PyObject *obj){}

PyObject * _PyObject_GetAttrId(PyObject *v, _Py_Identifier *name){}

int _PyObject_HasAttrId(PyObject *v, _Py_Identifier *name){}
int _PyObject_SetAttrId(PyObject *v, _Py_Identifier *name, PyObject *w){}

PyObject * PyObject_GetAttr(PyObject *v, PyObject *name){}

int _PyObject_LookupAttr(PyObject *v, PyObject *name, PyObject **result){}

int _PyObject_LookupAttrId(PyObject *v, _Py_Identifier *name, PyObject **result){}

int PyObject_HasAttr(PyObject *v, PyObject *name){}

int PyObject_SetAttr(PyObject *v, PyObject *name, PyObject *value){}

PyObject ** _PyObject_GetDictPtr(PyObject *obj){}

int PyObject_IsTrue(PyObject *v){}
int PyObject_Not(PyObject *v){}

PyObject * _PyObject_GenericGetAttrWithDict(PyObject *obj, PyObject *name, PyObject *dict, int suppress){}
