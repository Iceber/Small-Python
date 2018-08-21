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

#define PyObject_VAR_HEAD   PyVarObject ob_base;

typedef struct _typeobject{
        PyObject_VAR_HEAD
        const char *tp_name;
        Py_ssize_t tp_basicsize, tp_itemsize;

        destructor tp_dealloc;

        reprfunc tp_repr;

        PyNumberMethods *tp_as_number;

        hashfunc tp_hash;
        reprfunc tp_str;
        getattrofunc tp_getattro;

        unsigned long tp_flags;
        const char *tp_doc;

        /* rich comparisons */
        richcmpfunc tp_richcompare;

        struct PyMethodDef *tp_methods;
        struct PyGetSetDef *tp_getset;

        newfunc tp_new;
        freefunc tp_free;
}

#define Py_XSETREF(op, op2) \
        do {
                PyObject *_py_tmp = (PyObject *)(op);
                (op) = (op2);
                Py_XDECREF(_py_temp);
        }while(0)

#define Py_XDECREF(op) \
        do {
                PyObject *_py_xdecref_tmp = (PyObject *)(op);
                if (_py_xdecref_tmp != NULL)
                        PY_DECREF(_py_xdecref_tmp);
        }while(0)

#define _Py_CHECK_REFCNT(OP)    ; //a semicolon

#define _Py_INC_TRFREES(op)
#define _Py_COUNT_ALLOCS_COMMA

#define _Py_Dealloc(op) ( \
                _Py_INC_TRFREES(op) _Py_COUNT_ALLOCS_COMMA \
                (*Py_TYPE(op)->tp_dealloc)((PyObject *) (op)))

#define _Py_DEC_REFTOTAL 
#define _Py_REF_DEBUG_COMMA

#define Py_DECREF(op) \
        do{
                PyObject *_py_decref_tmp = (PyObject *)(op);
                if (_Py_DEC_REFTOTAL _Py_REF_DEBUG_COMMA --(_py_decref_tmp)->ob_refcnt != 0)
                        _Py_CHECK_REFCNT(_py_decref_tmp)
                else
                        _Py_Dealloc(_py_decref_tmp);
        }while(0)
