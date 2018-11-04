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
static int d ictresize(PyDictObject *mp, Py_ssize_t minued);

int PyDict_ClearFreeList(void){}
void PyDict_Fini(void){}

static inline Py_ssize_t dk_get_index(PyDictKeysobject *keys, Py_ssize_t i){}
static inline vvoid dk_set_index{}

static PyDictKeysObject empty_keys_struct = {
	1 //  dk_refcnt

