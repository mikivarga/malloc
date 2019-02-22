#include "alloc_in_heap.h"

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
            ft_printf("%p - %p : %zu bytes\n", (void *)blk->ptr, (void *)blk ->ptr + blk->ptr->size, blk->ptr->size);
        }
        blk->ptr = tmp;
    }
}

void    show_alloc_mem(void)
{
    ft_printf("TINY : %p\n", (void *)g_heap[TINY_BLK].start);
    ft_show_heap(&g_heap[TINY_BLK]);
    ft_printf("SMALL : %p\n", (void *)g_heap[SMALL_BLK].start);
    ft_show_heap(&g_heap[SMALL_BLK]);
    ft_printf("LARGE : %p\n"), (void *)g_heap[LARGE_BLK].start;
    ft_show_heap(&g_heap[LARGE_BLK]);
}