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
#include object.h

typedef struct {
        PyObject_VAR_HEAD
                PyObject **ob_item;
        Py_ssize_t allocated;
}PyListObject;

#define PyList_SET_ITEM(op, i, v) (((PyListObject *)(op)) -> ob_item[i] = (v))
