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

extern PyObject * _PyObject_GC_New(PyTypeObject *);

#define PyObject_GC_New(type, typeobj)\
        ((type *) _PyObject_GC_New(typeobj))

typedef struct {
        //Pointer to next object in the list
        //0 means the object is not tracked
        uintptr_t _gc_next;
        //Pointer to previous object in the list
        //Lowest two are used for flags documented later
        uintptr_t _gc_prev;
} PyGC_Head;


