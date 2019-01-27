#include "../inc/alloc_in_heap.h"

int     main(void)
{
	write(1,"My mallock\n", 11);
	if (!ft_malloc(10))
	{ 
		return 1;
	}
	write(1,"My mallock\n", 11);
	if (!ft_malloc(100))
	{ 
		return 1;
	}
  
  return (0);
}

//gcc srcs/main.c -I includes/malloc.h libft_malloc.so