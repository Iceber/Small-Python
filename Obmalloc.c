void * 
PyObject_Malloc(size_t size)
{
	if(size > (size_t)PY_SSIZE_T_MAX)
		return NULL;
	return _PyObject.malloc(_PyOjbect.ctx, size);
}

static PyMemAllocatorEx _PyMem_Raw = PYRAW_ALLOC;
static PyMemAllocatorEx _PyObject = PYOBJ_ALLOC;

#define PYOBJ_ALLOC PYMALLOC_ALLOC
#define PYMALLOC_ALLOC {NULL, _PyObject_Malloc, _PyObject_Calloc, _PyObject_Realloc, _PyObject_Free}

#define PYRAW_ALLOC MALLOC_ALLOC
#define MALLOC_ALLOC {NULL, _PyMem_RawMalloc, _PyMem_RawCalloc, _PyMem_RawRealloc, _PyMem_RawFree}

static void *
_PyObject_Malloc(void *ctx, size_t nbytes)
{
	void *ptr;
	if (pymalloc_alloc(ctx, &ptr, nbytes)){
		_Py_AllocatedBlocks++;
		return ptr;
	}

	ptr = PyMem_RawMalloc(nbytes);
	if (ptr !=NULL){
		_Py_AllocatedBlocks++;
	}
	return ptr;
}

static void *
_PyMem_RawMalloc(void *ctx, size_t size)
{
	if (size == 0)
		size = 1;
	return malloc(size)
}

void *
PyMem_RawMalloc(size_t size)
{

	if (size > (size_t)PY_SSIZE_T_MAX)
		return NULL
	return _PyMem_Raw.malloc(_PyMem_Raw.ctx, size);
}
