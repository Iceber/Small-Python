/*
 * =====================================================================================
 *
 *       Filename:  objimpl.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/17 20时29分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define PyObject_MALLOC     PyObject_Malloc

#define PyObject_New(op, typeobj) \
        ((type *) _PyObject_New(typeobj))
#define PyObject_NewVar(type, typeobj, n) \
        ((type *) _PyObject_NewVar((typeobj), (n)) )

#define PyObject_INIT(op, typeobj) \
        (Py_Type(op) = (typeobj), _Py_NewReference((PyObject *)(op)), (op))
#define PyObject_INIT_VAR(op, typeobj, size)\
        (Py_SIZE(op) = (size), PyObject_INIT((op), (typeobj)))




