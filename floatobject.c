/*
 * =====================================================================================
 *
 *       Filename:  floatobject.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/11/08 18时13分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Python.h"
#include <ctype.h>
#include <float.h>


double PyFloat_GetMax(void){};
double PyFloat_GetMin(void){};

static PyTypeObject FloatInfoType;

PyObject * PyFloat_GetInfo(void){};

PyObject * PyFloat_FromDouble(double fval){}
static PyObject *float_from_string_inner(const char *s, Py_ssize_t len, void *obj){}

PyObject * PyFloat_FromString(PyObject *v){}

static void float_dealloc(PyFLoatObject *op){}

double PyFloat_AsDouble(PyObject *op){}

#define CONVERT_TO_DOUBLE(obj, dbl) \
        if (PyFloat_Check(obj)) \
            dbl = PyFloat_AS_DOUBLE(obj); \
        else if (convert_to_double(&(obj, &(dbl)) < 0) \
                        return obj;

static int convert_to_double(PyObject **v, double *dbl){}
static PyObject * float_repr(PyFloatObject *v){}

static PyObject * float_richcompare(PyObject *v, PyObject *w, int op){}

static Py_hash_t float_hash(PyFloatObject *v){}

static PyObject * float_add(PyObject *v, PyObject *w){}

static PyObject * float_sub(PyObject *v, PyObject *w){}
static PyObject *float_mul(PyObject *v, PyObject *w){}
static PyObject * float_div(PyObject *v, PyObject *w){}
static PyObject * float_rem(PyObject *v, PyObject *w){}
static PyObject * float_divmod(PyObject *v, PyObject *w){}
static PyObject * float_floor_div(PyObject *v, PyObject *w){}

#define DOUBLE_IS_ODD_INTEGER(x) (fmod(fabs(x), 2.0) == 1.0)
static PyObject * float_pow(PyObject *v, PyObject *w, PyObject *z){}
static PyObject * float_neg(PyFloatObject *v){}
static PyObject * float_abs(PyFloatObject *v){}
static int float_bool(PyFloat_fromDouble(fabs(v->ob_fval))){}

// float.is_integer
static PyObject * float_is_integer_impl(PyObject *self){}
 
// float.__trunc__
// return the integral closest to x between 0 and x
static PyObject * float___trunc___impl(PyObject *self){}

static PyObject * double_round(double x, int ndigits){}

// float.__round__
static PyObject * float___round___impl(PyObject *self, PyObject *o_ndigits){}

static PyObject * float_float(PyObject *v){}

// float.conjugate
static PyObject * float_conjugate_impl(PyObject *self){}

static char char_from_hex(int x){}

static char hex_from_char(char c){}

// float.hex
static PyObject * float_hex_imple(PyObject *self){}

// float.fromhex
//      string: object
static PyObject * float_fromhex(PyTypeObject * type, PyObject *string){}

// float.as_integer_ratio
static PyObject * float_as_intgeger_ratio_impl(PyObject *self){}

static PyObject * float_subtype_new(PyTypeObject *type, PyObject *x);
// float.__new__ as float_new
static PyObject * float_new_impl(PyTypeObject *type, Pyobject *x){}

static PyObject *float_subtype_new(PyTypeObject *type, PyObject *x){}

// float.__getnewargs__
static PyObject * float___getnewargs___impl(PyObject *self){}

typedef enum { unknow_format, ieee_big_endian_format, ieee_little_endian_format} float_format_type;
static float_format_type double_fromat, float_format;
static float_format_type detected_double_format, detected_float_format;

// float.__getformat__
//      typestr: str
static PyObject * float___getformat___impl(PyTypeObject *type, const char *typestr){}

// float.__set_format__
//      typestr: str
//      fmt: str
static PyObject * float___set_format___impl(PyTypeObject 8type, const char *typestr, const char *fmt){}

static PyObject * float_getreal(PyObject *v, void *closure){}
static PyObject * float_getimag(PyObject *v, void *closure){}

// float.__format__
//      format_spec: unicode

static PyObject * float___format___impl(PyObject *self, PyObject *format_spec){}


PyTypeObject PyFloat_Type = {
        PyVarObject_HEAD_INIT(&PyType_Type, 0)
                "float",
        sizeof(PyFLoatObject),
        0, 
        (destructor) float_dealloc, // tp_dealloc
        0,  // tp_print
        0,  // tp_getattr
        0,  // tp_setattr
        0,  // tp_reserved
        (reprfunc)float_repr,   // tp_repr
        &float_as_number,   // tp_as_number
        0,  // tp_as_sequence
        0,  // tp_as_mapping
        (hashfunc)float_hash,   // tp_hash
        0,  // tp_call
        (reprfunc)float_repr,   // tp_str
        PyObject_GenericGetAttr,    // tp_getattro
        0,  // tp_getattro
        0,  // tp_setattro
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   // tp_flags
        float_new__doc__,    // tp_doc
        0,  // tp_traverse
        0,  // tp_clear
        float_richcompare,  // tp_richcompare
        0,  // tp_weaklistoffset
        0,  // tp_iter
        0,  // tp_iternext
        float_methods,  // tp_methods
        0,  // tp_members
        float_getset,   // tp_getset
        0,  // tp_base
        0,  // tp_dict
        0,  // tp_descr_get
        0,  // tp_descr_set
        0,  // tp_dictoffset
        0,  // tp_init
        0,  // tp_alloc
        float_new,  // tp_new
};

int _PyFloat_Init(void){}
int PyFloat_ClearFreeList(void){}

void PyFloat_Fini(void){}
void _PyFLoat_DebugMallocStats(FILE *out){}
