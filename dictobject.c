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

static uint64_t pydict_global_version = 0;
#define DICT_NEXT_VERSION() (++pydict_global_version)

static PyDicktKeysObjectempty_keys_struct = {
        1, //dk_refcnt
        1, //dk_size
        lookdict_split, //dk_lookup
        0, // dk_usable (immutable)
        0, // dk_nentries
        {DKIX_EMPTY, DKIX_EMPTY, DKIX_EMPTY, DKIX_EMPTY,
                DKIX_EMPTY, DKIX_EMPTY, DKIX_EMPTY, EKIX_EMPTY}, 
}

static PyObject *
new_dict(PyDictKeysObject *keys, PyObject **values)
{
        PyDictObject *mp;
        if(numfree){
                mp = free_lsit[--numfree];
                _Py_NewReference((PyObject *)mp);
        }
        else{
                mp = PyObject_GC_New(PyDictObject , &PyDict_Type);
                if (mp == NULL){
                        DK_DECREF(keys);
                        free_values(values);
                        return NULL:
                }
        }
        mp->ma_keys = keys;
        mp->ma_values = values;
        mp->ma_used = 0;
        mp->ma_version_tag = DICT_NEXT_VERSION();
        return (PyObject *)mp;
}

#define USABLE_FRACTION(n) (((n) << 1) / 3)

static PyDictKeysObject **new_keys_object(Py_ssize_t size)
{
        PyDictKeysObject *dk;
        Py_ssize_t es, usable;

        usable = USABLE_FRATION(size);
        if (size <= 0xff){
                es = 1;
        }
        else if(size <= 0xffff){
                es = 2;
        }
        else{
                es = sizeof(Py_ssize_t);
        }
        if (size == PyDict_MINSIZE && numfreekeys > 0){
                dk = keys_free_list[--numfreekeys];
        }
        else{
                dk = PyObject_MALLOC(sizeof(PyDictKeysObject) + es *size + sizeof(PyDictKeyEntry) * usable);
                if (dk == NULL){
                        PyErr_NoMemory();
                        return NULL;
                }
        }

        DK_DEBUG_INCREF dk->dk_refcnt = 1;
        dk->dk_size = size;
        dk->dk_usable = usable;
        dk->dk_lookup = lookdict_unicode_nodummy;
        dk->dk_nentries = 0;
        memset(&dk->dk_indices[0], 0xff, es*size);
        memset(DK_ENTRIES(dk), 0,sizeof(PyDictKeyEntry) * usable);
        return dk;
}

PyObject * 
PyDict_New(void)
{
        PyDictKeysObject *keys = new_keys_object(PyDict_MINSIZE);
        if(keys == NULL)
                return NULL;
        return new_dict(keys, NULL)
}

PyObject *
PyDict_GetItem(PyObject *op, PyObject *key)
{
        Py_hash_t hash;
        Py_ssize_t ix;
        PyDictObject *mp = (PyDictObject *)op;
        PyThreadState *tstate;
        PyObject *value;

        if (!PyDict_Check(op))
                return NULL;
        if (!PyUnicode_CheckExact(key) ||
                        (hash = ((PyASCIIObject *) key) -> hash) == -1)
        {
                hash = PyObject_Hash(key);
                if (hash == -1){
                        PyErr_Clear();
                        return NULL;
                }
        }

        tstate = PyThreadState_GET();
        if (tstate != NULL && tstate->curexc_type != NULL){
                PyObject *err_type, *err_value, *err_tb;
                PyErr_Fetch(&err_type, &err_value, &err_tb);

        }

}

static inline Py_ssize_t
dk_get_index(PyDictKeysObject *keys, Py_ssize_t i)
{
        Py_ssize_t s = DK_SIZE(keys);
        Py_ssize_t ix;

        if(s <= 0xff){
                int8_t *indices = (int8_t*)(keys->dk_indices);
                ix = indices[i];
        }
        else if (s <= 0xffff){
                int16_t *indices = (int16_t*)(keys->dk_indices);
                ix = indices[i];
        }
        else {
                int32_t *indices = (int32_t*)(keys->dk_indices);
                ix=indices[i];
        }
        return ix;
}

static Py_ssize_t _Py_HOT_FUNCTION
lookdict_unicode_nodummy(PyDictObject *mp, PyObject *key, PY_hash_t has, PyObject **value_addr)
{
        if (!PyUnicode_CheckExact(key)){
                mp->ma_keys->dk_lookup = lookdict;
                return lookdict(mp, key, hash, value_addr);
        }

        PyDictKeyEntry *ep0 = DK_ENTRIES(mp->ma_keys);
        size_t mask = DK_MASK(mp->ma_keys);
        size_t perturb = (size_t)hash;
        size_t i = (size_t) hash & mask;

        for (;;){
                Py_ssize_t ix = dk_get_index(mp_>ma_keys, i);
                if 

}
