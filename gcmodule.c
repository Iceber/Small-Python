/*
 * =====================================================================================
 *
 *       Filename:  gcmodule.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/21 14时40分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define FROM_GC(g) ((PyObject *)(((PyGC_Head *)g) + 1))

PyObject *
_PyObject_GC_Alloc(int use_calloc, size_t basicsize)
{
        PyObject *op;
        PyGC_Head *g;
        size_t size;
        if (basicsize > PY_SSIZE_T_MAX - sizeof(PyGC_Head))
                return PyErr_NoMemory();
        size = sizeof(PyGC_Head) + baseicsize;
        if (use_calloc)
                g = (PyGC_Head *)PyObject_Calloc(1, size);
        else
                g = (PyGC_Head *)PyObject_Malloc(size);
        if (g == NULL)
                return PyErr_NoMemory();

        g->_gc_next = 0;
        g->_gc_prev = 0;
        _PyRuntime.gc.generations[0].count++;

        if (_PyRuntime.gc.generations[0].count > _PyRuntime.gc.generations[0].threshold &&
                        _PyRuntime.gc.enabled && _PyRuntime.gc.generations[0].threshold &&
                        !_PyRuntime.gc.collecting &&
                        !PyErr_Occurred()){
                _PyRuntime.gc.collecting=1;
                collect_generations();
                _PyRuntime.gc.collecting = 0;
        }
        op = FROM_GC(g);
        return op
}

PyObject *
_PyObject_GC_Malloc(size_t basicsize)
{
        return _PyObject_GC_Alloc(0, basicsize);
}


PyObject *
_PyObject_GC_New(PyTypeObject *tp)
{
        PyObject *op = _PyObject_GC_MALLOC(_PyObject_SIZE(tp));
        if (op != NULL)
                op = PyObject_INIT(op, tp);
        return op;
}
