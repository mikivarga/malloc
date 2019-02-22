#include "alloc_in_heap.h"

static void		ft_dump_hexa(const void *addr)
{
	const char	hex[16] = "0123456789abcdef";
	int			temp;

	temp = *(char*)addr >> 4 & 0x0F;
	write(1, &hex[temp], 1);
	temp = *(char*)addr & 0x0F;
	write(1, &hex[temp], 1);
}

static void		ft_print_last_line(int i, char s[16])
{
	size_t	a;

	if (i % 16 != 0)
	{
		a = i;
		while (a % 16 != 0)
		{
			write(1, "  ", 2);
			if (a % 2 == 0)
				write(1, " ", 1);
			a++;
		}
		if (i % 2 == 1)
			write(1, " ", 1);
		write(1, s, i % 16);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

static void			ft_print_memory(const void *addr, size_t size)
{
	char	s[16];
	size_t	i;

	ft_bzero(s, 16);
	i = 0;
	while (i < size)
	{
		ft_dump_hexa(addr);
		s[i % 16] = *(char*)addr;
		if (s[i % 16] < 32 || s[i % 16] > 126)
			s[i % 16] = '.';
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
		{
			write(1, s, 16);
			write(1, "\n", 1);
			ft_bzero(s, 16);
		}
		addr++;
	}
	ft_print_last_line(i, s);
}

static void ft_show_heap(t_lst_block *blk)
{
    t_element_block *tmp;

    blk->ptr = blk->start;
    tmp = blk->ptr;
    while (lst_move_ptr_right(blk))
    {
        tmp = blk->ptr;
        if (blk->ptr->free == FALSE)
        {
            ft_printf("%p - %p : ", (void *)blk->ptr, (void *)blk ->ptr + blk->ptr->size);
            ft_print_memory((void *)blk->ptr, blk->ptr->size);
        }
        blk->ptr = tmp;
    }
    sleep(3);
}

void    show_alloc_mem_ex(void)
{
    ft_printf("TINY : %p\n", (void *)g_heap[TINY_BLK].start);
    ft_show_heap(&g_heap[TINY_BLK]);
    ft_printf("SMALL : %p\n", (void *)g_heap[SMALL_BLK].start);
    ft_show_heap(&g_heap[SMALL_BLK]);
    ft_printf("LARGE : %p\n"), (void *)g_heap[LARGE_BLK].start;
    ft_show_heap(&g_heap[LARGE_BLK]);
}