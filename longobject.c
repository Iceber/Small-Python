/*
 * =====================================================================================
 *
 *       Filename:  longobject.c
 *
 *    Description:  Small Python long int
 *
 *        Version:  1.0
 *        Created:  2018/08/16 21时29分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <float.h>
#include <ctype.h>
#include <stddef.h>

#ifndef NSMALLPOSINTS
#define NSMALLPOSINTS   100
#endif

#ifndef NSMALLENGINTS
#define NSMALLENGINTS   5
#endif

# if NSMALLENGINTS + NSMALLPOSINTS >0
static PyLongObject small_inits[NSMALLENGINTS + NSMALLPOSINTS]

static PyObject *
get_small_int(sdight ival)
{
        PyObject *v;
//        assert(-NSMALLENGINTS <= ival && ival < NSMALLPOSINTS);
        v = (PyObject *)&small_ints[ival + NSMALLENGINTS];
        Py_INCREF(v);
        return v
}

#define CHECK_SMALL_INT(ival) \
        do if (-NSMALLENGINTS <= ival && ival < NSMALLPOSINTS){\
                return get_small_int((sdigit)ival);\
        }while (0)

static PyLongObject * 
maybe_small_long(PyLongObject *v)
{
        if (v && Py_ABS(Py_SIZE(v)) <= 1){
                sdigit ival=MEDIUM_VALUE(v);
                Py_DECREF(v);
                return v;
        }
}
#endif

#define MAX_LONG_DIGITS ((PY_SIZE_T_MAX - offsetof(PyLongObject, ob_digit))/sizeof(digit))

PyOjbect *
_PyLong_New(Py_ssize_t size)
{
        PyLongObject *result;
        if (size > (Py_ssize_t)MAX_LONG_DIGITS){
                PyErr_SetString(PyExc_OverflowError, "too many digits in integer");
                return NULL;
        }
        result = PyObject_MALLOC(offsetof(PyLongObject, ob_digit) + size* sizeof(digit));
        
        if(!result){
                PyErr_NoMemory();
                return NULL;
        }
        return (PyLongObject*)PyObject_INIT_VAR(result, &PyLong_Type, size);
}


PyObject * _PyLong_FromLong(long ival)
{
        PyLongObject *v;
        unsigned long abs_ival;
        unisnged long t;
        int ndigits = 0;
        int sign;

        CHECK_SMALL_INT(ival);

        if (ival < 0){
                // unsigned
                abs_ival = 0U-(unsigned long) ival;
                sign = -1;
        }
        else {
                abs_ival = (unsigned long) ival;
                sign = ival ==0 ? 0 : 1;

        }

        if (!(abs_ival >> PyLong_SHIFT)){
                v = _PyLong_New(1);
                if(v) {
                        Py_SIZE(v) = sign;
                        v->ob_digit[0] = Py_SAFE_DOWNCAST(abs_ival, unsigned long, digit);
                }
                return (Py_Object*) v;
        }

         t = abs_ival;
         while(t){
                 ++ndight;
                 t >>= PyLong_SHIFT;
         }
         v = _PyLong_New(ndigits);
         if (v != NULL){
                 digit* p = v->ob_digit;
                 Py_SIZE(v) = ndigits * sign;
                 t = abs_ival;
                 while (t){
                         *p++ = Py_SAFE_DOWNCAST( t & PyLong_MASK, unsigned long, digit);
                         t >>= PyLong_SHIFT;
                 }
         }
         return (PyObject *) v;
}
