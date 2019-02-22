#include "alloc_in_heap.h"
#include <stdlib.h>

static int ft_search_heap(t_lst_block *lst, t_element_block *blk)
{
    lst->ptr = lst->start;
    while (lst_move_ptr_right(lst))
    {
        if (lst->ptr == blk)
        {
            if(lst->ptr->free) //double free
            {
                return (FALSE);
            }
            blk->free = TRUE;
            //defragmentation?
            return (TRUE);
        }
    }
    return (FALSE);
}

void			free(void *ptr)
{
    t_element_block *blk;

    if (ptr == NULL)
    {
        return ;
    }
    blk = ((t_element_block *)(ptr)) - 1;
    if (g_heap[TINY_BLK].start < blk && g_heap[TINY_BLK].end > blk)
    {
        if (ft_search_heap(&(g_heap[TINY_BLK]), blk))
        {
            return ;
        }
        ft_printf("tiny_zone\n");
    }
    else if (g_heap[SMALL_BLK].start < blk && g_heap[SMALL_BLK].end > blk)
    {
        if (ft_search_heap(&(g_heap[SMALL_BLK]), blk))
        {
            return ;
        }
        ft_printf("small_zone\n");
    }
    else //if (g_heap[LARGE_BLK].start <= blk && g_heap[LARGE_BLK].end >= blk)
    {
        if (ft_search_heap(&(g_heap[LARGE_BLK]), blk))
        {
        ////munmap_large
        //delete blk
        /*if ((munmap(blk, blk->size + sizeof(t_element_block))) != 0)
        {
		    ft_putstr_fd(2, "munmap error\n");
        }*/
            return ;
        }
    }
    
    ft_putstr_fd("free(): invalid pointer\nAborted (core dumped)\n", 2);
    exit(1);
}