#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct s_block {
	size_t i;
	struct s_block *next;
	struct s_block *prev;
	int free;
}		t_block;


int     main(void)
{
	struct s_block *next;
	printf("sizeof(t_block) =  %zu\n", sizeof(t_block));
	printf("sizeof(size_t) %zu\n", sizeof(size_t));
		printf("sizeof(*next) %zu\n", sizeof(next));
	printf("sizeof(int) %zu\n", sizeof(int));
/*
	write(1,"My mallock\n", 11);
	if (!malloc(10))
	{ 
		return 1;
	}
	write(1,"My mallock\n", 11);
	if (!malloc(100))
	{ 
		return 1;
	}
  */
  return (0);
}

//gcc srcs/main.c -I includes/malloc.h libft_malloc.so