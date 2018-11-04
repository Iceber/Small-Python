/*
 * =====================================================================================
 *
 *       Filename:  dictobject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/22 09时36分05秒
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

	Py_ssize_t ma_used;
	uint64_t ma_version_tag;
	PyDictKeyObject *ma_keys;

	PyObject **ma_values;
}PyDictObject;

typedef struct {
	PyObject_HEAD
		PyDictObject *dv_dict;
} _PyDictViewObject;

PyTypeObject PyDict_Type;
PyTypeObject PyDictKeys_Type;
PyTypeObject PyDictValues_Type;

#define PyDict_Check(op) \
	PyType_FastSubclass(Py_TYPE(op), Py_TPFLAGS_DICT_SUBCLASS)
#define PyDict_CheckExact(op) (Py_TYPE(op) == &PyDict_Type)
#define PyDictKeys_Check(op) PyObject_TypeCheck(op, &PyDictKeys_Type)
#define PyDictItems_Check(op) PyObject_TypeCheck(op, &PyDictItems_Type)
#define PyDictValues_Check(op) PyObject_TypeCheck(op, &PyDictValues_Type)
#define PyDictViewSet_Check(op) \
	(PyDictKeys_Check(op) || DickItems_Check(op))


PyObject * PyDict_New(void);
PyObject * PyDict_GetItem(PyObject *mp, PyObject *key);
PyObject * _PyDict_GetItem_KnowHash(PyObject *mp, PyObject *key, Py_hash_t hash);
PyObject * PyDict_GetItemWithError(PyObject *mp, PyObject *key);
PyObject * _PyDict_GetItemIdWithError(PyObject *dp, struct _Py_Identifier *key);
PyObject * PyDict_SetDefault(PyObject *mp, PyObject *key, PyObject *defaultobj);
int PyDict_SetItem(PyObject *mp, PyObjcet *key, PyObject *item);
int _PyDict_SetItem_KnowHash(PyObject *mp, PyObject *kwy, PyObject *item, Py_hash_t hash);
int PyDict_DelItem(PyObject *mp, PyObject *key);
int _PyDict_DelItem_KnowHash(PyObject *mp, PyObject *key, Py_hash_t hash);
int _PyDict_DelItemIf(PyObject *mp, PyObject *key, int (*predicate)(PyObject *value));

void PyDict_Clear(PyObject *mp);
int PyDict_Next(PyObject *mp, Py_ssize_t *pos, PyObject **key, PyObject **value);

PyDictKeysObject *_PyDict_NewKeysForClass(void);
PyObject * PyObject_GenericGetDict(PyObject *, void *);
int _PyDict_Next(PyObject *mp, Py_ssize_t *pos, PyObject **key, PyObject **value, Py_hash_t *hash);
PyObject *_PyDictView_New(PyObject *, PyTypeObject *);
PyObject *PyDict_Keys(PyObject *mp);
PyObject *PyDict_Values(PyObject *mp);
PyObject *PyDict_Items(PyObject *mp);
PyObject *PyDict_Size(PyObject *mp);
PyObject *PyDict_Copy(PyObject *mp);
int PyDict_Contains(PyObject *mp, PyObject *key);

#define PyDict_GET_SIZE(mp) (assert(PyDict_Check(mp)), ((PyDIctObject *)mp)->ma_used)

int _PyDict_Contains(PyObject *mp, PyObject *key, Py_hash_t hash);
PyObjec * _PyDict_NewPresized(Py_ssize_t minused);
void _PyDict_MaybeUntrack(PyObject *mp);
int _PyDict_HashOnlyStringKeys(PyObject *mp);
Py_ssize_t _PyDict_KeysSize(PyDictKeysObject *keys);
Py_ssize_t _PyDict_Sizeof(PyDictObject *);
PyObject * _PyDict_Pop(PyObject *, PyObject *, PyObject *);
PyObject * _PyDict_Pop_KnowHash(PyObject *, PyObject *, Py_hash_t, PyObject *);
PyObject * _PyDict_FromKeys(PyObject *, PyObject *, PyObject *);

int PyDict_ClearFreeList(void);
int PyDict_Update(PyObject *mp, PyObject *other);
int PyDict_Merge(PyObject *mp, PyObject *other, int override);

int _PyDict_MergeEx(PyObject *mp, PyObject *other, int override);
PyObject * _PyDictView_Intersect(PyObject *self, PyObject *other);
int PyDict_MergeFromSeq2(PyObject *d, PyObject *seq2, int override);
PyObject * PyDict_GetItemString(PyObject *dp, const char *key);
PyObject * _PyDict_GetItemId(PyObject *dp, struct _PyIdentfier *key);
int PyDict_SetItemString(PyObject *dp, const char *key, PyObject *item);
int _PyDict_SetItemId(PyObject *dp, struct _Py_Identifier *key, PyObject *item);
int PyDict_DelItemString(PyObject *dp, const char *key);
int _PyDict_DebugMallocStats(FILE *out);
int _PyObjectDict_SetItem(PyTypeObject *tp, PyObject **dictptr, Pyobject *name, PyObject *value);
PyObject *_PyDict_LoadGlobal(PyDictObject *, PyDictObject *, PyObject *);
