/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:52:15 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/02 17:39:54 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_in_heap.h"

static void		ft_delete_blk(t_lst_block *lst)
{
	if (lst->start->next != lst->end && lst->ptr->next == lst->end)
	{
		while (((void *)lst->ptr + sizeof(t_element_block)) <
((void *)lst->end - getpagesize() * 3))
		{
			lst->end = (void *)lst->end - getpagesize();
			if ((munmap((void *)lst->end +
sizeof(t_element_block), getpagesize())) != 0)
				ft_putstr_fd("munmap error\n", 2);
		}
		lst->ptr->next = lst->end;
		lst->end->prev = lst->ptr;
	}
}

static int		ft_search_heap(t_lst_block *lst, t_element_block *blk)
{
	lst->ptr = lst->start;
	while (lst_move_ptr_right(lst))
	{
		if (lst->ptr == blk)
		{
			if (lst->ptr->free)
			{
				return (FALSE);
			}
			blk->free = TRUE;
			return (TRUE);
		}
	}
	return (FALSE);
}

int				ft_make_free(void *ptr)
{
	t_element_block *blk;

	blk = ((t_element_block *)(ptr)) - 1;
	if (g_heap[TINY_BLK].start < blk && g_heap[TINY_BLK].end > blk)
	{
		if (ft_search_heap(&(g_heap[TINY_BLK]), blk))
			return (TRUE);
	}
	else if (g_heap[SMALL_BLK].start < blk && g_heap[SMALL_BLK].end > blk)
	{
		if (ft_search_heap(&(g_heap[SMALL_BLK]), blk))
			return (TRUE);
	}
	else if (g_heap[LARGE_BLK].start <= blk && g_heap[LARGE_BLK].end >= blk)
	{
		if (ft_search_heap(&(g_heap[LARGE_BLK]), blk))
		{
			ft_delete_blk(&(g_heap[LARGE_BLK]));
			return (TRUE);
		}
	}
	return (FALSE);
}

void			free(void *ptr)
{
	if (ptr == NULL)
	{
		return ;
	}
	ft_make_free(ptr);
}
