/*
 * =====================================================================================
 *
 *       Filename:  dictobject.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/22 09时24分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

static Py_ssize_t lookdict(PyDictObject *mp, PyObject *key, Py_hash_t hash, PyObject **value_addr);
static Py_ssize_t lookdict_unicode(PyDictOject *mp, PyObject *key, Py_hash_t hash, PyObject **value_addr);
static Py_ssize_t lookdict_unicode_nodummy(PyDictObjecct *mp, PyObjecct *key, Py_hash_t hash, PyObject **value_addr);
static Py_ssize_t lookdict_split(PyDictObject *mp, PyObject *key, Py_hash_t hash, PyObject **value_addr);
static int dictresize(PyDictObject *mp, Py_ssize_t minued);

int PyDict_ClearFreeList(void){}
void PyDict_Fini(void){}

static inline Py_ssize_t dk_get_index(PyDictKeysobject *keys, Py_ssize_t i){}
static inline void dk_set_index(PyDictKeysObject *keys, Py_ssize_t i, Py_ssize_t ix){}

static PyDictKeysObject empty_keys_struct = {
	1,  // dk_refcnt
    1,  // dk_size
    lookdict_split, //dk_lookup
    0,  // dk_usable
    0,  // dk_nentries
    {DKIX_EMPTY, DKIX_EMPTY, DKIX_EMPTY,DKIX_EMPTY,
            DKIX_EMPTY, DKIX_EMPTY, DKIX_EMPTY, DKIX_EMPTY} // dk_indices
};

static PyObject *empty_values[1] = {NULL};

static Py_EMPTY_KEYS &empty_keys_struct

static PyDictKeysObject *new_keys_object(Py_ssize_t size){}
static void free_keys_object(PyDictKeysObject *keys){}

#define new_values(size) PyMem_NEW(PyObject *, size)
#define free_values(values) PyMem_FREE(values)

static PyObejct * new_dict(PyDictKeysObject *keys, PyObject **values){}
static PyObject * new_dict_with_shared_keys(PyDictKeysObject *keys){}
static PyObject * clone_combined_dict(PyDictObject *orig){}
PyObject *PyDict_New(void){}
static Py_ssize_t lookdict_index(PyDictKeysObject *k, Py_hash_t hash, Py_ssize_t index){}

static Py_ssize_t _Py_HOT_FUNCTION lookdict(PyDictObject *mp, PyObject *key, Py_hash_t hash, PyObect **value_addr){}
static Py_ssize_t _Py_HOT_FUNCTION lookdict_unicode(PyDictObject *mp, PyObject *key, Py_hash_t hash, PyObject **value_addr){}
static Py_ssize_t _Py_HOT_FUNCTION lookdict_unicode_nodummy(PyDictObject *mp, PyObject *key, Py_hash_t hash, PyObject **value_addr){}
static Py_ssize_t _Py_HOT_FUNCTION lookdict_split(PyDictObject *mp, PyObject *key, Py_hash_t hash, PyObject **value_addr){}
int _PyDict_HashOnlyStringKeys(PyObject *dict){}

void _PyDict_MaybeUntrack(PyObject *op){}
static Py_ssize_t find_empty_slot(PYDictKeysObject *keys, Py_hash_t hash){}
static int insertion_resize(PyDictObject *mp){}

static int insertdict(PYDictObject *mp, PyObject *key, Py_hash_t hash, PyObject *value){}

static void build_indices(PyDictKeysObject *keys, PyDictKeyEntry *ep, Py_ssize_t n){}

static int dictresize(PyDictObject *mp, Py_ssize_t minsize){}

static PyDictKeysObject * make_keys_shared(PyObject *op){}
PyObject * _PyDict_NewPresized(Py_ssize_t minused){}
PyObject *PyDict_GetItem(PYObject *op, PyObject *key){}
PyObject * _PyDict_GetItem_KnowHash(PyObject *op, PyObject *key, Py_hash_t hash){}
PyObject * PyDict_GetItemWithError(PyObject *op, PyObject *key){}
PyObject * _PyDict_GetItemIdWithError(PyObject *dp, struct _Py_Identifier *key){}

PyObject * _PyDict_LoadGlobal(PYDictObject *globals, PyDictObject *builtins, PyObject *key){}

int PyDict_SetItem(PyObject *op, PyObject *key, PyObject *value){}
int _PyDict_SetItem_KnownHash(PyObject *op, PyObject *key, PyObject *value, Py_hash_t hash){}

static int delitem_common(PyDictObject *mp, Py_hash_t hash, Py_ssize_t ix, PyObject *old_value){}
int PyDict_DelItem(PyObject *op, PyObject *key){}
int _PyDict_DelItem_KnownHash(PyObject *op, PyObject *key, Py_hash_t hash){}
int _PyDict_DelItemIf(PyObject *op, PyObject *key, int (*predicate)(PyObject *value)){}
void PyDict_Clear(PyObject *op){}

int _PyDict_Next(PyObject *op, Py_ssize_t *ppos, PyObject **pkey, PyObject **pvalue, Py_hash_t *phash){}
int Py_dict_Next(PyObject *op, Py_ssize_t *ppos, PyObject **pkey, PyObject **pvalue){}

PyObject * _PyDict_Pop_KnownHash(PyObject *dict, PyObject *key, Py_hash_t hash, PyObject *deflt){}
PyObject * _PyDict_Pop(PyObject *dict, PyObject *key, PyObject *deflt){}
PyObject * _PyDict_FromKeys(PyObject *cls, PyObject *iterable, PyObject *value){}

static void dict_dealloc(PyDictObject *mp){}

static PyObject * dict_repr(PyDictObject *mp){}

static Py_ssize_t dict_length(PyDictObject *mp){}

static PyObject * dict_keys(PyDictObject *mp){}
static PyObject * dict_values(PyDictObject *mp){}
static PyObject * dict_items(PyDictObject *mp){}

// [clinic input]
// @classmethod
// dict.fromkeys
//      iterable:object 
//      value: object=None
//  Create a new dictionary with keys form iterable and values set to value
static PyObject *dict_fromkeys_impl(PyTypeObject *type, PyObject *iteralbe, PyObject *value){}

static int dict_update_common(PyObject *self, PyObject *args, PyObject *kwds, const char *methname){}

static PyObject *dict_update(PYObject *self, PyObject *args, PyObject *kwds){}

int PyDict_MergeFromSeq2(PyObject 8d, PyObject *seq2, int override){}
static int dict_merge(PyObject *a, PyObject *b, int override){}

int PyDict_Update(PyObject *a, PyObject *b){}
int PyDict_Merge(PyObject *a, PyObject 8b, int override){}
int _PyDict_MergeEx(PyObject *a, PyObject *b, int override){}
static PyObject * dict_copy(PyDIctObject *mp, PyObject *Py_UNUSED(ignored)){}
PyObject * PyDict_Copy(PyObject *o){}
Py_ssize_t PyDict_Size(PyObject *mp){}

PYObject *PyDict_keys(PyObject *mp){}
PyObject * PyDict_Values(PyObject *mp){}
PyObject * PyDict_Items(PyObject *mp){}

static int dict_equal(PyDictObject 8a, PyDictObject *b){}
static PyObject * dict_richcompare(PyObject *v, PyObject *w, int op){}

// @coexist
// dict.__contains__
//      key: object
static PyObject * dict___contains__(PyDictObject *self, PyObject *key){}

// dict.get
//      key: object
//      default: object = None
static PyObject * dict_get_impl(PyDictObject *self, PyObject *key, PyObject *default_value){}

// dict.setdefault
//      key: object
//      default: object=None
PyObject * PyDict_SetDefault(PyObject *d, PyObject *key, PyObject *defaultobj){}

static PyObject * dict_setdefault_impl(PyDictObject *self, PyObject *key, PyObject *default_value){}

static PyObject * dict_clear(PyDictObject *mp, PyObject *Py_UNUSED(ignored)){}

static PyObject * dict_pop(PyDictObject *mp, PyObject *args){}

static PyObject * dict_popitem(PyDictObject *mp, PyObject *Py_UNUSED(ignored)){}

static int dict_traverse(PyObject *op, visitproc visit, void *arg){}

static int dict_tp_clear(PyObject *op){}
static PyObject *dictiter_new(PyDictObject *, PyTypeObject *);

Py_ssize_t _PyDict_SizeOf(PyDictObject *mp){}
Py_ssize_t _PyDict_KeysSize(PyDictKeysObject *keys){}
static PyObject * dict_sizeof(PyDictObject *mp, PyObject *Py_UNUSED(ignored)){}

static PyObject * dictkeys_new(PyObject *, PyObject *);
static PyObject * dictitems_new(PyObject *, PyObject *);
static PyObject * dictvalues_new(PyObject *, PyObject *);

int PyDict_Contains(PyObject *op, PyObject *key){}
int _PyDict_contains(PyObject *op, PyObject *key, Py_hash_t hash){}

static PyObject * dict_new(PyTypeObject *type, PyObject *args, PyObject *kwds){}

static int dict_init(PyObject *self, PyObject *args, PyObject *kwds){}

PyTypeObject PyDict_Type={
        PyVarObject_HEAD_INIT(&PyType_Type, 0)
                "dict",
        sizeof(PyDictObject),
        0,
        (destructor)dict_dealloc,   // tp_dealloc
        0,      // tp_print
        0,      // tp_getattr
        0,      // tp_setattr
        0,      // tp_reserved
        (reprfunc)dict_repr,    // tp_repr
        0,      // tp_as_number
        &dict_as_sequence,  // tp_as_sequence
        &dict_as_mapping,   // tp_as_mapping
        PyObject_HashNotImplemented,    // tp_hash
        0,      // tp_call
        0,      // tp_str
        PyObject_GenericGetAttr,     // tp_getattro
        0,      // tp_setattro
        0,      // tp_as_buffer
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | 
                Py_TPFLAGS_BASETYPE | Py_TPFLAGS_DICT_SUBCLASS,     // tp_flags
        dictionary_doc,     // tp_doc
        dict_traverse,      // tp_traverse
        dict_tp_clear,      // tp_clear
        dict_richcompare,   // tp_richcompare
        0,      // tp_weaklistoffset
        (getiterfunc)dict_iter,     // tp_iter
        0,      // tp_iternext
        mapp_methods,   //tp_methods
        0,      // tp_members
        0,      // tp_getset
        0,      // tp_base
        0,      // tp_dict
        0,      // tp_descr_get
        0,      // tp_descr_set
        0,      // tp_dictoffset
        dict_init,  // tp_init
        PyType_GenericAlloc,    // tp_alloc
        dict_new,   // tp_new
        PyObject_GC_Del,    //tp_free
};

PyObject * _PyDict_GetItemId(PyObject *dp, struct _Py_Identifier *key){}
PyObject * PyDict_GetItemString(PyObject *v, const char *key){}

int _PyDict_SetItemId(PyObject *v, struct _PyIdentifier *key, PyObject *item){}
int PyDict_SetItemString(PyObject *v, const char *key, PyObject *item){}

int _PyDict_DelItemId(PyObject *v, _Py_Identifier *key){}
int PyDict_DelItemString(PyObject *v, const char *key){}


static PyObject * dictkeys_iter(_PyDictViewObject *dv){}
static int dictkeys_contains(_PYDictViewObject *dv, PyObject *obj){}

PyTypeObject PyDictKeys_Type={
        PyVarObject_HEAD_INIT(&PyType_Type, 0)
                "dict_keys",    // tp_name
        sizeof(_PyDictViewObject),  //tp_basicsize
        0,  // tp_itemsize

        (destructor)dictview_dealloc,   // tp_dealloc
        0,  // tp_print
        0,  // tp_getattr
        0,  // tp_setattr
        0,  // tp_reserved
        (reprfunc)dictview_repr,    // tp_repr
        &dictviews_as_number,   // tp_as_number
        &dictkeys_as_sequence,  // tp_as_sequence
        0,  // tp_as_mapping
        0,  // tp_hash
        0,  // tp_call
        0,  // tp_str
        PyObject_GenericGetAttr,    // tp_getattro
        0,  // tp_setattro
        0,  // tp_as_buffer
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC, // tp_flags
        0,  // tp_doc
        (traverseproc)dictview_traverse,    // tp_traverse
        0,  // tp_clear
        dictview_richcompare,   // tp_richcompare
        0,  // tp_weaklistoffset
        (getiterfunc)dictkeys_iter, // tp_iter
        0,  // tp_iternext
        dictkeys_methods,   // tp_methods
        0,
};

static PyObject * dictkeys_new(PyObject *dict, PyObject *Py_UNUSED(ignored)){}

static PyObject * dictitems_iter(_PyDiceViewObject *dv){}
static int dictitems_contains(_PyDictNewObject *dv, PyObject *obj){}
