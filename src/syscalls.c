#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#undef errno
extern int errno;

extern uint32_t _bss_end;
register uint32_t *stack_ptr asm("sp");

caddr_t __attribute__ ((weak)) _sbrk(int incr)
{
    static uint32_t *heap_end = &_bss_end;
    uint32_t *prev_heap_end;

    prev_heap_end = heap_end;

    if (heap_end + incr > stack_ptr)
    {
        errno = ENOMEM;
        return (caddr_t) -1;
    }

    heap_end += incr;
    return (caddr_t) prev_heap_end;
}

int __attribute__ ((weak)) _close(int file)
{
    return -1;
}

int __attribute__ ((weak)) _fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int __attribute__ ((weak)) _isatty(int file)
{
    return 1;
}

int __attribute__ ((weak)) _lseek(int file, int ptr, int dir)
{
    return 0;
}

int __attribute__ ((weak)) _read(int file, char *ptr, int len)
{
    return 0;
}

int __attribute__ ((weak)) _write(int file, char *ptr, int len)
{
	return 0;
}
