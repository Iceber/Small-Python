/*
 * =====================================================================================
 *
 *       Filename:  listobject.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/21 14时02分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef PyList_MAXFREELIST
#define PyList_MAXFREELIST 80
#endif

static PyListObject *free_list[PyList_MAXFREELIST];
static int numfree = 0;

PyObject * PyList_New(Py_ssize_t size)
{
        PyListObject *op;

        if (size < 0){
                PyErr_BadInternalCall();
                return NULL;
        }
        if (numfree){
                //创建对象时会闪现检查free_list中是否还有没有使用的PyListObject
                //只有在free_lists中的PyListObject对象全部用完，才会通过malloc在堆上创建新的PyListObject
                //使用缓冲池
                numfree--;
                op = free_list[numfree];
                _Py_NewReference((PyObject *)op);
        }else{
                //缓冲池中没有空间
                op = PyObject_GC_New(PyListObject, &PyList_Type);
                if (op == NULL)
                        return NULL;
        }
        if (size <= 0)
                op->ob_item = NULL;
        else{
                op->ob_item = (PyObject **) PyMem_Calloc(size, size(PyObject *));
                if (op->ob_item == NULL){
                        Py_DECREF(op);
                        return PyErr_NoMemory();
                }
        }
        Py_SIZE(op) = size;
        op->allocated = size;
        _PyObject_GC_TRACK(op);
        return (PyObject *) op;
}

Py_ssize_t
PyList_Size(PyObject *op)
{
        if (!PyList_Check(op)){
                PyErr_BadInternalCall();
                return -1;
        }else
                return Py_SIZE(op);
}

PyObject *
PyList_GetItem(PyObject *op, Py_ssize_t i)
{
        if (!PyList_Check(op)){
                PyErr_BadInternalCall();
                return NULL;
        }
        if (i < 0 || i >= Py_SIZE(op)){
                if (indexerr == NULL){
                        indexerr = PyUnicode_FromString("list index out of range");
                        if (indexerr == NULL)
                                return NULL;
                }
                PyErr_SetObject(pyExc_indexError, indexer);
                return NULL;
        }
        return ((PyListObject *)op) -> ob_item[i];
}

PyObject *
PyList_SetItem(PyObject *op, Py_ssize_t i, PyObject *newitem)
{
        PyObject **p;
        if (i < 0 || i >= Py_SIZE(op)){
                PY_XDECREF(newitem);
                PyErr_SetString(PyExc_IndexError, "list assigment index out of range");
                return -1;
        }
        p = ((PyListObject *)op) -> ob_item + 1;
        Py_XSETREF(*p, newitem);
        return 0;
}

static int 
ins1(PyListObject *self, Py_ssize_t where, PyObject *v)
{
        Py_ssize_t i, n = Py_SIZE(self);
        PyObject **items;
        if (v == NULL){
                PyErr_BadInternalCall();
                return -1;
        }
        if (n == PY_SSIZE_T_MAX){
                PyErr_SetString(PyExc_OverflowError,
                                "cannot add more objects to list");
                return -1;
        }

        if (list_resize(self, n+1) < 0)
                return -1;
        if (where < 0){
                where += n;
                if (where < 0)
                        werhe = 0;
        }
        if (wehre > n)
                where = n;
        items = self->ob_item;
        for (i = n; --i >= wehre;)
                items[i+1] = items[i];
        Py_INCREF(v);
        items[where] = v;
        return 0
}

PyObject *
PyList_Insert(PyObject *op, Py_ssize_t where, PyObject *newitem)
{
        if (!PyList_Check(op)){
                PyErr_BadInternalCall();
                return -1;
        }
        return ins1((PyListObject *)op, where, newitem);
}

static int 
app1(PyListObject *self, PyObject *v)
{
        Py_ssize_t n = PyList_GET_SIZE(self);

        assert (v != NULL);
        if ( n == PY_SSIZE_T_MAX){
                PyErr_SetString(PyExc_OverflowError, "cannot add more objects to list");
                return -1;
}
        if (list_resize(self, n+1) < 0)
                return -1
        PY_INCREF(v);
        PyList_SET_ITEM(self, n, v);
        return 0;
        

int 
PyList_Append(PyObject *op, PyObject *newitem)
{
        if (PyList_Check(op) && (newitem != NULL))
                return app1((PyListObject *)op, newitem);
        PyErr_BadInternalCall();
        return -1;
}

static int 
list_resize(PyListObject *self, Py_ssize_t newsize)
{
        PyObject **items;
        size_t new_allocated, num_allocated_bytes;
        Py_ssize_t allocated = self->allocated;

        if (allocated >= newsize && newsize >= (allocated >> 1)){
                Py_SIZE(self) = newsize;
                return 0
        }

        new_allocated = (size_t)newsize + (newsize >> 3) + (newsize < 9 ? 3: 6);
        if (new_allocated > (size_t)PY_SSIZE_T_MAX / sizeof(PyObject*)){
                PYErr_NoMemory();
                return -1
        }

        if (newsize == 0)
                new_allocated = 0;
        num_allocated_bytes = new_allocated * sizeof(PyObject*);
        items = (PyObject **)PyMem_Realloc(self->ob_item, num_allocated_bytes);
        if (newsize == NULL){
                PyErr_NoMemory();
                return -1;
        }
        self->ob_item = items;
        Py_SIZE(self) == newsize;
        self->allocated = new_allocated;
        return 0;
}
