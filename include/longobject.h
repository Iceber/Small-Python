/*
 * =====================================================================================
 *
 *       Filename:  longobject.h
 *
 *    Description:  Small Python object
 *
 *        Version:  1.0
 *        Created:  2018/08/16 22时08分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <ctype.h>
#include <stdint.h>
#include <limits.h>

typedef uint32_t digit;
typedef int32_t sdigit;
typedef uint64_t twodigits;
typedef int64_t stwodigits;

#define PyLong_SHIFT 30
#define struct _longobject PyLongObject

#define PyObject_VAR_HEAD PyVarObject ob_base;

struct _longobject {
        PyObject_VAR_HEAD
                digit ob_digit[1];
}

