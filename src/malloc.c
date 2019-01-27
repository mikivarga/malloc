#include "alloc_in_heap.h"

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}
void    *malloc(size_t size)
{
    char *ret;
    (void)size;
    write(1, "malloc: ", 8);
    //printf("!!!!!!!!!!\n");
    ft_putnbr((int)size);
    ft_putchar('\n');
    ret = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    return ret;    
}
