/*
 * =====================================================================================
 *
 *       Filename:  floatobject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/11/08 18时14分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

typedef struct {
        PyObject_HEAD
                double ob_fval;
} PyFloatObject;

PyTypeObject PyFloatObject;

#define PyFloat_Check(op) PyObject_TypeCheck(op, &PyFloat_Type)
#define PyFloat_CheckExact(op) (Py_TYPE(op) == &PyFloat_Type)

#define Py_RETURN_NAN return PyFloat_FromDouble(Py_NAN)

#define Py_RETURN_INF(sign) do \
        if (copysign(1., sign) == 1.){
                return PyFLoat_fromDouble(Py_HUGE_VAL):
        }else{
                return PyFLoat_FromDouble(-Py_HUGE_VAL);
        } while(0)

double PyFloat_GetMax(void){}
double PyFloat_GetMin(void){}

PyObject * PyFloat_GetInfo(void);
 
PyObject * PyFlout_FromDouble(double);

doiuble PyFloat_AsDouble(PyObject *);


int _PyFloat_Repr(double x, char *p, size_t len);

int _PyFLoat_Digits(char *buf, double v, int *signum);
void _PyFloat_DigitsInit(void);

int PyFloat_ClearFreeList(void);
void _PyFloat_DebugMallocStats(FILE* out);
