#include "../inc/alloc_in_heap.h"
#include <stdio.h>
#include <string.h>

void	ft_putad(unsigned long long ptr)
{
	const char	hex[16] = "0123456789abcdef";
	char		s[16];
	int			i;

	i = 0;
	if (ptr == 0)
		s[i++] = '0';
	while (ptr != 0)
	{
		s[i++] = hex[ptr % 16];
		ptr /= 16;
	}
	write(1, "0x", 2);
	while (i--)
		ft_putchar(s[i]);
}
/*
int     main(void)
{
	char *str1, *str2, *str3, *str4, *str5;

	ft_putstr("MALLOC\n");
	if (!(str1 = ft_malloc(10)))
	{ 
		
		return 1;
	}
	ft_putstr("main - add1 = ");
	ft_putad((unsigned long long)str1);
	ft_putstr("\n\n\n");
	ft_putstr("MALLOC\n");
	free(str1);
	if (!(str2 = ft_malloc(100)))
	{ 

		return 1;
	}
	ft_putstr("main - add2 = ");
	ft_putad((unsigned long long)str2);
	ft_putstr("\n\n\n");
	free((void *)str2);
	ft_putstr("MALLOC\n");
	if (!(str3 = ft_malloc(1000)))
	{ 
		return 1;
	}
	ft_putstr("main - add3 = ");
  	ft_putad((unsigned long long)str3);
	ft_putstr("\n\n\n");
	free(str3);


	ft_putstr("MALLOC\n");
	if (!(str5 = ft_malloc(10)))
	{ 
		return 1;
	}
	ft_putstr("main - add5 = ");
  	ft_putad((unsigned long long)str5);
	ft_putstr("\n\n\n");
	free(str5);

	ft_putstr("MALLOC\n");
	if (!(str4 = ft_malloc(10)))
	{ 
		return 1;
	}
	ft_putstr("main - add4 = ");
  ft_putad((unsigned long long)str4);
	ft_putstr("\n\n\n");

	(void)str5;
  return (0);
}*/
/*
#define M (1024 * 1024)

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr1;
	char *addr2;
	char *addr3;

	addr1 = (char*)malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = (char*)malloc(16*M);
	strcpy(addr2, "Bonjours\n");
	print(addr2);
	addr3 = (char*)realloc(addr1, 128*M);
	addr3[127*M] = 42;
	print(addr3);
	return (0);
}*/

/*
int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	return (0);
}
*/

/*
#define M (1024 * 1024)

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr1;
	char *addr3;

	addr1 = (char*)malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = (char*)realloc(addr1, 128*M);
	addr3[127*M] = 42;
	print(addr3);
	return 0;
}
*/


int main()
{
	malloc(42);
	malloc(84);
	malloc(102);
	malloc(208);
	malloc(3725);
	malloc(48847);
	show_alloc_mem();
	return (0);
}





/*#include <unistd.h>

int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = i;
		ft_printf("main addr = %p = %d\n", (void *)addr, addr[0]);
		free(addr);
		i++;
	}
	return (0);
}*/


//gcc src/main.c -I inc/malloc.h libft_malloc.so