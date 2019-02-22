#include "alloc_in_heap.h"

void	ft_putaddrr(unsigned long long ptr)
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

void *ft_malloc(size_t size)
{
	return (malloc(size));
}

static void ft_find_free_block(t_lst_block *blk, size_t size)
{
    blk->ptr = blk->start;
    while (lst_move_ptr_right(blk))
    {
        //ft_putchar('l');
        //ft_putchar('\n');
        if (blk->ptr->free && blk->ptr->size >= size)
        {
            ft_putstr("lst_fragment(blk, size);\n");
            lst_fragment(blk, size);
            return ;
        }
    }
    blk->ptr = blk->end->prev;
    lst_put_post(blk, size);
    blk->ptr = blk->end->prev;
}

static void	ft_select_zone(size_t size, t_heap_zones *zone_type, size_t *zone_size)
{
    static int init[ZONES_TYPE] = {FALSE, FALSE, FALSE};

    if (size < SIZE_TINY_BLK)
	{
		*zone_type = TINY_BLK;
		*zone_size = getpagesize();
	}
	else if (size < SIZE_SMALL_BLK)
	{
		*zone_type = SMALL_BLK;
		*zone_size = getpagesize();
	}
	else
	{
		*zone_type = LARGE_BLK;
		*zone_size = getpagesize() * 3;
    }
    if (init[*zone_type] == FALSE)
    {
        //ft_putstr("INIT_ZONE\n");
        if (lst_init_block(&(g_heap[*zone_type]), *zone_size) == FALSE)
        {
            ft_putstr("can't init zone");
        }
        init[*zone_type] = TRUE;
    }    
}

void *malloc(size_t size)
{
    t_lst_block *new_blk;
    t_heap_zones zone_type;
    size_t zone_size;

    //ft_printf("\nCALL malloc\n");
    ft_select_zone(size, &zone_type, &zone_size);
    new_blk = &(g_heap[zone_type]);
    ft_find_free_block(new_blk, size);
    return (new_blk->ptr + 1);    
}
