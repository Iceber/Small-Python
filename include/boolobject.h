/*
 * =====================================================================================
 *
 *       Filename:  boolobject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/11/08 16时47分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

PyTypeObject PyBoolType;

struct _longobject _Py_FalseStruct, _Py_TrueStruct;

#define Py_False ((PyObject *) &_PY_FalseStruct)
#define Py_True ((PyObject *) &_Py_TrueStruct)

#define Py_RETURN_TRUE return Py_INCREF(Py_True), Py_True
#define Py_RETURN_FALSE return Py_INCREF(Py_False), Py_False

PyObject * PyBool_FromLong(long);
