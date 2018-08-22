/*
 * =====================================================================================
 *
 *       Filename:  dict-common.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/22 09时40分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

typedef struct {
    Py_hash_t me_hash;
    PyObject *me_key;
    PyObject *me_value;
}PyDictKeyEntry;

typedef Py_ssize_t (*dict_lookup_func)
        (PyDictObject *mp, PyObject *key, Py_hash_t hash, PyObject **value_addr);


struct _dictkeysobject{
        Py_ssize_t dk_refcnt;

        // size of the hash table (dk_indices) it must be power of 2
        Py_ssize_t dk_size;

        /* function to lookup in the has table (dk_Indices):*/
        dict_lookup_func dk_lookup;

        // number of usable entires in dk_entries
        Py_ssize_t dk_Usable;

        // number of used entires in dk_entries
        Py_ssize_t dk_nentries;

        char dk_indices[];

}
