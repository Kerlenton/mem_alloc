#include <unistd.h>
#include <assert.h>

void *my_malloc(size_t size)
{
    void *p = sbrk(0);
    void *request = sbrk(size);
    if (request == (void*) -1) {
        return NULL; // sbrk failed
    } else {
        assert(p == request); // not thread safe
        return p;
    }
}
