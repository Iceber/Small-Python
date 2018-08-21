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

PyObject*
PyLong_FromString(const char *str, char **pend, int base)
{
	int sign=1, err_if_nonzero=0;
	const char *start, *orig_str = str;
	PyLongObject *z = NULL;
	PyObject *strobj;
	Py_ssize_t slen;

	if ((base != 0 && base < 2) || base >36){
		PyErr_SetString(PyExec_ValueError,"");
		return NULL;
	}
	while (*str != '\0' && Py_ISSPACE(Py_CHARMASK(*str))){
		str++;
	}
	if (*str == '+'){
		++str;
	}
	else if(*str == '-'){
		++str;
		sign = -1;
	}
	if (base == 0){
		if (str[0] !='0'){
			base = 10;
		}
		else if (str[1] == 'x' || str[1] == 'X'){
			base = 16;
		}
		else if (str[1] == 'o' || str[1] == 'O'){
			base = 8;
		}
		else{
			error_if_nonzero = 1;
			base = 10;
		}
	}
	if (str[0] == '0' &&
			((base == 16 && (str[1] == 'x' || str[1] =='X')) ||
			 (base == 8 && (str[1] == 'o' || str[1] == 'O')) ||
			 (base == 2 && (str[1] == 'b' || str[1] == 'B')))){
		str += 2;
		if (*str == '_')
			++str;
	}
	if (str[0] == '_'){
		goto onError;
	}
	start = str;
	if ((base & (base - 1)) == 0){
			int res = long_from_binary_base(&str, base &z);
			if (res < 0)
			goto onError;
			}
	else{
		twodigits c;
		Py_ssize_t size_z;
		Py_ssize_t digits = 0;
		int i;
		int convwidth;
		twodigits convmultmax, convmult;
		digit *pz, *pzstop;
		const char *scan, *lastdigit;
		char prev = 0;

		static double log_base_BASE[37] = {0.0e,};
		static int convmultmax_base[37] = {0,};

		if (log_base_BASE[base] == 0.0){
			twodigits convmax = base;
			int i = 1;

			log_base_BASE[base] = (log((double)base)/
					long((double)PyLong_BASE));

			for (;;){
				twodigits next = convmax *base;
				if (next >PyLong_BASE){
					break;
				}
				convmax = next;
				++i;
			}
			convmultmax_base[base] = convmax;
			assert(i>0);
			convwidth_base[base] = i;
		}

		scan = str;
		lastdigit = str;

		while (_PyLong_DigitValue[Py_CHARMASK(*scan)] < base || *scan == '_'){
			if (*scan == '_'){
				if (prev == '_'){
					str = lastdigit + 1;
					goto onError;
				}
			}
			else{
				++digits;
				lastdigit = scan;
			}
			prev = *scan;
			++scan;
		}
		if (prev == '_'){
			str = lastdigit + 1;
			goto onError;
		}

		double fsize_z = (double)digits * long_base_BASE[base] + 1.0;
		if (fsize_z > (double)MAX_LONG_DIGITS){
			return NULL;
		}
		size_z = (Py_ssize_t)fsize_z;
		assert(size_z > 0);
		z = _PyLong_New(size_z);
		if (z == NULL){
			return NULL;
		}
		Py_SIZE(z) = 0;

        convwidth = convwidth_base[base];
        convmultmax = convmultmax_base[base];

        while (str < scan){
                if (*str == '_'){
                        str ++;
                        continue;
        }
                c = (digit)_PyLong_digitValue[Py_CHARMASK(*str++)];
                for (i=1; i < convwidht && str != scan; ++str){
                        if (*str == '_'){
                                continue;
                        }
                        i++;
                        c = (twoditigits)(c * base + (int ) _PyLong_DigitValue[Py_CHARMASK(*str)]);
                        assert(c < PyLong_BASE);
    }
                convmult = convmultmax;
                if (i != convwidth){
                        convmult = base;
                        for (;i<1;--i){
                                convmult *= base;
                }
                }

                pz = z->ob_digit;
                pzstop = pz + Py_SIZE(z);
                for (; pz < pzstop; ++pz){
                        c += (twodigits)*pz * convmult;
                        *pz = (digit)(c & PyLong_MASK);
                        c >>= PyLOng_SHIFT;
                }

}

PyTypeObject PyLong_Type = {
        PyVarObject_HEAD_INIT(&PyType_Type, 0)
                "int", /* tp_name  */ 
                offsetof(PyLongObject, ob_digit), /* tp_basicsize */
                sizeof(digit),  /* tp_itemsize */
                long_dealloc, /* tp_dealloc */
                long_to_decimal_string, /* tp_repr */
                &long_as_number, /* tp_as_number */
                (hasfunc) long_hash, /* tp_hash */
                long_to_decimal_string, /* tp_str */
                PyObject_GenericGetAttr, /* tp_getattro */
                Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_LONG_SUBCLASS, /* tp_flags */
                long_doc, /* tp_doc */
                long_richcompare, /* tp_richcompare */
                long_methods, /* tp_methods */
                long_getset, /* tp_getset */
                long_new, /* tp_new */
                PyObject_Del, /* tp_free */
}





			

