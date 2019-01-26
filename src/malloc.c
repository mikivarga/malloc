#include "alloc_in_heap.h"

void    *malloc(size_t size)
{
    char *ret;
    (void)size;
     write(1, "mall0c!\n", 8);
    //printf("!!!!!!!!!! %zu\n", size);
    ft_putnbr((int)size); //will work just afrer realization of malloc 
    ret = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    return ret;    
}
