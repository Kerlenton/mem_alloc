/* An horrible dummy malloc */

#include <unistd.h>
#include <assert.h>
#include <sys/types.h>

void *malloc(size_t size)
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
