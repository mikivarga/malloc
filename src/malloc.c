#include "alloc_in_heap.h"

void    *malloc(size_t size)
{
    char *ret;
    (void)size;
    write(1, "mall0c!\n", 8);
    // /ft_printf("IDIOT1\n"); //will work just afrer realization of malloc 
    ft_putstr("MIKI IDIOT\n");
    ret = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    return ret;    
}
