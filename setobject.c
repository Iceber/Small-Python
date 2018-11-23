/*
 * =====================================================================================
 *
 *       Filename:  setobject.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/11/23 20时15分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
static PyObject _dummy_struct;

#define dummy (&_dummy_struct)


static setentry * set_lookkey(PySetObject *so, PyObject *key, Py_hash_t hash){}
static int set_add_entry(PySetObject *so, PyObject *key, Py_hash_t hash){}
static void set_insert_clean(setentry *table, size_t mask, PyObject *key, Py_hash_t hash){}

/* restructure the table by allocating a new table and reinserting all keys again.
 * When entries have been deleted, the new table may actually be smaller than the old one.
 */
static int set_table_resize(PySetObject *so, Py_ssize_t minused){}
static int set_contains_entry(PySetObject *so, PyObject *key, Py_hash_t hash){}

static int set_discard_entry(PySetObject *so, PyObject *key, Py_hash_t hash){}

static int set_add_key(PySetObject *so, PyObject *key){}
static int set_contains_key(PySetObject *so, PyObject *key){}
static int set_discard_key(PySetObject *so, PyObject *key){}
static void set_empty_to_minsize(PySetObject *so){}
static int set_clear_internal(PySetObject *so){}

static int set_next(PySetObject *so, Py_ssize_t *pos_ptr, setentry **entry_ptr){}
static void set_dealloc(PySetObject *so){}
static PyObject * set_repr(PySetObject *so){}

static Py_ssize_t set_len(PyObject *so){}
static int set_merge(PySetObject *so, PyObject *otherset){}

static PyObject * set_pop(PySetObject *so, PyObject *Py_UNUSED(ignored)){}

static int set_update_internal(PySetObject *so, PyObject *other){}
static PyObject * set_update(PySetObject *so, PyObject *args){}

static PyObject * make_new_set(PyTypeObject *type, PyObject *iterable){}
static PyObject * make_new_set_basetype(PyTypeObject *type, PyObject *iterable){}
static PyObject * set_new(PyTypeObject *type, PyObject *args, PyObject *kwds){}

static void set_swap_bodies(PySetObject *a, PySetObject *b){}

static PyObject * set_copy(PySetObject *so, PyObject *Py_UNUSED(ignored)){}
static PyObject * set_clear(PySetObject *so, PyObject *Py_UNUSED(ignored)){}

static PyObject * set_union(PySetObject *so, PyObject *args){}
static PyObject * set_or(PySetObject *so, PyObject *other){}
static PyObject * set_ior(PySetObject *so, PyObject *other){}
static PyObject * set_intersection(PySetObject *so, PyObject *other){}

static PyObject * set_richcompare(PySetObject *v, PyObject *w, int op){}

static PyObject * set_add(PySetObject *so, PyObject *key){}
static PyObject * set_contains(PySetObject *so, PyObject *key){}
static PyObject * set_direct_contains(PySetObject *so, PyObject *key){}
static PyObject







PyObject *_PySet_Dummy = dummy;

PyObject * PySet_New(PyObject *iterable)
{
        return make_new_set(&PySet_Type, iterable);
}

Py_ssize_t PySet_Size(PyObject *anyset){}
int PySet_Clear(PyObject *set){}
int PySet_Contains(PyObject *anyset, PyObject *key){}

int PySet_Discard(PyObject *set, PyObject *key){}

int PySet_Add(PyObject *anyset, PyObject *key){}

int PySet_ClearFreeList(void){}
void PySet_Fini(void){}

int _PySet_NextEntry(PyObject *set, Py_ssize_t *pos, PyObject **key, Py_hash_t *hash){}
PyObject * PySetPop(PyObject *set){}
int _PySet_Update(PyObject *set, PyObject *iterable){}
