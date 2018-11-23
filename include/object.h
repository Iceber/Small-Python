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

#define PyObject_HEAD   PyObject ob_base;
#define PyObject_HEAD_INIT(type)    \
{_PyObject_EXTRA_INIT\
        1, type},

#define PyVarObject_HEAD_INIT(type, size)   \
{ _PyObject_HEAD_INIT(type) size},

#define PyObject_VAR_HEAD   PyVarObject ob_base;
#define Py_INVALID_SIZE (Py_ssize_t)-1

typedef struct _object {
        _PyObject_HEAD_EXTRA
        Py_ssize_t ob_refcnt;
        struct _typeobject *ob_type;
} PyObject;

typedef struct {
        PyObject ob_base;
        Py_ssize_t ob_size
} PyVarObject;

#define Py_REFCNT(ob)    (((PyObject*)(ob)) -> ob_refcnt)
#define Py_TYPE(ob)      (((PyObject*)(ob)) -> ob_type)
#define Py_SIZE(ob)      (((PyVarObject*)(ob)) -> ob_size)

typedef struct _Py_Identifier{
        struct _Py_Identifier *next;
        const char*string;
        PyObject *object;
} _Py_Identifier;


#define _Py_static_string_init(void) { .next = NULL, .string = value, object = NULL}
#define _Py_static_string(varname, value) static _Py_Identifier varname = _Py_static_string_init(value)
#define _Py_INENTIFIER(varname) _Py_static_string(PyId_##vauname, #vauname)

typedef PyObject * (*unaryfunc)PyObject *);
typedef PyObject * (*binaryfunc)(PyObject *, PyObject *);
typedef PyObject * (*ternaryfunc)(PyObject *, PyObject *, PyObject *);
typedef int (*inquiry)(PyObject *);


typedef struct bufferinfo{
        void *buf;
        PyObject *obj;
        Py_ssize_t len;
        Py_ssize_t itemsize;

        int readonely;
        int ndim;
        char *format;
        Py_ssize_t *shape;
        Py_ssize_t *strides;
        Py_ssize_t *suboffsets;
        void *internal;
} Py_buffer;   

typedef void (*freefunc)(void *);
typedef void (*destructor)(PyObject *);
typedef int (*printfunc)(PyObject *, FILE *, int);

typedef PyObject *(*getattrfunc)(PyObject *, char *);
typedef Pyobject *(*getattrofunc)(PyObject*, PyObject *);
typedef int (*setattrfunc) (PyObject *, char *, PyObject *);
typedef int (*setattrofunc) (PyObject *, PyObject *, PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
typedef Py_hash_t (*hashfunc)(PyObject *);
typedef PyObject *(*richcmpfunc) (PyObject *, PyObject *, int);
typedef int (*initproc)(PyObject *, PyObject *, PyObject *);
typedef PyObject *(*newfunc)(struct _typeobject *, PyObject *, PyObject *);
typedef PYObject *(*allocfunc)(struct _typeobject *, Py_ssize_t);

typedef struct _typeobject PyTypeObject;

typedef struct _typeobject {
        PyObject_VAR_HEAD
        const char *tp_name, // For printing, in format"<module>.<name>"
        Py_ssize_t tp_basicsize, tp_itemsize;   // for allocation

        destructor tp_dealloc;
        printfunc tp_print;
        getattrfunc tp_getattr;
        setattrunc tp_setattr;
        PyAsyncMethods *tp_as_async, // formerly known as tp_reserved
        
        reprfunc tp_repr;

        PyNumberMethods *tp_as_number;
        PySequenceMethods *tp_as_sequence;
        PyMappingMethods *tp_as_mapping;

        hashfunc tp_hash;
        ternaryfunc tp_call;
        reprfunc tp_str;
        getattrofunc tp_getattro;
        setattrofunc tp_setattro;

        PyBufferProc *tp_as_buffer;
        unsigned long tp_flags;
        const char *tp_doc;

        traverseproc tp_traverse;

        inquiry tp_clear;
        richcmpfunc tp_richcompare;
        Py_ssize_t tp_weaklistoffset;

        getiterfunc tp_iter;
        iternextfunc tp_iternext;

        struct PyMethodDef *tp_methods;
        struct PyMemberDef *tp_members;
        struct PyGetSetDef *tp_getset;
        struct _typeobject *tp_base;

        PyObject *tp_dict;
        descrgetfunc tp_descr_get;
        descrsetfunc tp_descr_set;
        Py_ssize_t tp_dictoffset;
        initproc tp_init;
        allocfunc tp_alloc;
        newfunc tp_new;
        freefunc tp_free;
        inquiry tp_is_gc;

        PyObject *tp_bases;
        PyObject *tp_mro;
        PyObject *tp_cache;
        PyObject *tp_subclasses;
        Pyobject *tp_weaklist;
        destructor tp_del;

        unsigned int tp_version_tag;

        destructor tp_finalize;

        Py_ssize_t tp_allocs;
        Py_ssize_t tp_frees;
        Py_ssize_t tp_maxalloc;
        struct _typeobject *tp_prev;
        struct _typeobject *tp_next;
}PyTypeObject;

typedef struct {
        int slot;   // slot id
        void *pfunc;    // function pointer
}PyType_Slot;


int PyType_IsSubtype(PyTypeObject *, PyTypeObject *);
#define PyObject_TypeCheck(ob, tp) \ 
    (Py_TYPE(ob) == (tp) || PyType_IsSubtype(Py_TYPE(ob), (tp)))

PyTypeObject PyType_Type;   //build-in 'type'
PyTypeObject PyBaseObject_Type; // build-in 'object'
PyTypeObject PySuper_Type;  // build-in 'super'

#define PyType_Check(op) \ 
    PyType_FastSubclass(Py_TYPE(op), Py_TPFLAGS_TYPE_SUBCLASS)
#define PyType_CheckExact(op) (Py_TYPE(op) == &PyType_Type)

int PyType_Ready(PyTypeObject *);
PyObject * PyType_GenericAlloc(PyTypeObject *, Py_ssize_t);
PyObject * PyType_GenericNew(PyTypeObject *, PyObject *, PyObject *);

const char * _PyTyp_Name(PyTypeObject *);
PyObject * _PyType_Lookup(PyTypeObject *, PyObject *);
PyObject * _PyType_LookupId(PyTypeObject *, _Py_Identifier *);

struct _Py_Identifier;
int PyObject_Print(PyObject *, FILE *, int);
void _Py_BreakPoint(void);
void _PyObject_Dump(PyObject *);

PyObject * PyObject_Repr(PyObject *);
PyObject * PyObject_Str(PyObject *);
PyObject * PyObject_ASCII(PyObject *);
PyObject * PyObject_Bytes(PyObject *);

int PyObject_RichCompareBool(PyObject *, PyObject *, int);
#define _Py_INC_TPFREE(OP)
#define _Py_COUNT_ALLOCS_COMMA
#define _Py_DEC_REFTOTAL
#define _Py_REF_DEBUG_COMMA
#define _Py_CHECK_REFCNT(OP)

#define _Py_Dealloc(op) (   \
        _Py_INC_TPFREES(op) _Py_COUNT_ALLOCS_COMMA \
                (*Py_TYPE(op)->tp_dealloc)((PyObject *)(op)))

#define Py_INCREF(op) (  \
                _Py_INC_REFTOTAL _Py_REF_DEBUG_COMMA    \
                ((PyObject *)(op)) -> ob_refcnt++)
#define Py_DECREF(op) (     \
                do{         \
                PyObject *_py_decref_temp = (PyObject *)(op);   \
                if (_Py_DEC_REFTOTAL _Py_REF_DEBUG_COMMA        \
                        --(_py_decref_tmp) -> ob_refcnt !=0) \
                        _Py_CHECK_REFCNT(_py_decref_tmp)    \
                 else                                       \
                    _Py_Dealloc(_py_decref_tmp);        \
                }while(0)

#define Py_CLEAR(op) (       \
        do {                \
            PyObject *_py_tmp = (PyObject *) (op);  \
            if (_py_tmp != NULL) {  \
            (op) = NULL;        \
            Py_DECREF(_Py_tmp); \
            }           \
        }while(0)

// Macro to use in case the object pointer may be NULL:
#define Py_XINCREF(op)       \
        do {                \
            PyObject *_py_xincref_tmp = (PyObject *)(op);   \
            if (_py_xincref_tmp != NULL)        \
                Py_INCREF(_py_xincref_tmp);         \
        }while(0)

#define Py_XDECREF(op)      \      
        do {        \
            PyObject *_py_xdecref_tmp = (PyObject *) (op);  \
            if (_py_xdecref_tmp != NULL)    \
                    Py_DECREF(_py_xdecref_tmp); \
        }while(0)

// Safely decref op and set op to op2

#define Py_SETREF(op, op2)      \
        do {        \
                PyObject *py_tmp = (PyObject *)(op);    \
                (op) = (op2);                           \
                Py_DECREF(_py_tmp);                 \
        }while(0)

#define Py_XSETREF(op, op2)     \
        do {        \
                PyObject *py_tmp = (PyObject *)(op);    \
                (op) = (op2);                   \
                Py_XDECREF(_py_tmp);        \
        }while(0)
