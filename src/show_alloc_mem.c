/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:20:06 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/24 17:48:22 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_in_heap.h"

static void	ft_show_heap(t_lst_block *blk)
{
	t_element_block *tmp;

	blk->ptr = blk->start;
	while (lst_move_ptr_right(blk))
	{
		tmp = blk->ptr;
		if (tmp->free == FALSE)
		{
			ft_printf("%p - %p : %zu bytes\n"
, (void *)(tmp + 1)
, (void *)(tmp + 1) + tmp->size
, tmp->size);
		}
		blk->ptr = tmp;
	}
}

void		show_alloc_mem(void)
{
	ft_printf("TINY : %p\n", (void *)g_heap[TINY_BLK].start);
	if (g_heap[TINY_BLK].start)
		ft_show_heap(&g_heap[TINY_BLK]);
	ft_printf("SMALL : %p\n", (void *)g_heap[SMALL_BLK].start);
	if (g_heap[SMALL_BLK].start)
		ft_show_heap(&g_heap[SMALL_BLK]);
	ft_printf("LARGE : %p\n", (void *)g_heap[LARGE_BLK].start);
	if (g_heap[LARGE_BLK].start)
		ft_show_heap(&g_heap[LARGE_BLK]);
}
