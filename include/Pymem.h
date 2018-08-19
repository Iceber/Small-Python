typedef struct{
	void *ctx;
	void * (*malloc)(void *ctx, size_t nelem, size_t elsize);
}PyMemAllocatorDomain;

