/*
 * =====================================================================================
 *
 *       Filename:  object.h
 *
 *    Description:  Small Python object
 *
 *        Version:  1.0
 *        Created:  2018/08/16 21时39分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define _PyObject_HEAD_EXTRA
#define _PyObject_EXTRA_INIT

typedef struct _object {
        _PyObject_HEAD_EXTRA;
        py_ssize_t ob_refcnt;
        struct _typeobject *ob_type;
}PyObject;

typedef struct _py_var_object {
        PyObject ob_base;
        Py_ssize_t ob_size;
}PyVarObject;

#define Py_REFCNT(ob)   (((PyObject *)(ob)) -> ob_refcnt)
#define Py_TYPE(ob)     (((PyObject *)(ob)) -> ob_type)
#define Py_SIZE(ob)     (((PyObject *)(ob)) -> ob_size)


#define _Py_NewRederence(op)\
        ( _Py_INC_TPALLOCS(op) _Py_COUNT_ALLOCS_COMMA _Py_INC_REFTOTAL _Py_REF_DEBUG_COMMA Py_REFCNT(op)=1)

#define _Py_INC_TRALLOC(OP)

