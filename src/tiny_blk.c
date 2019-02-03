/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_blk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:31:55 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/03 18:15:05 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alloc_in_heap.h"

static size_t		ft_align_size(size_t size, size_t multiple)
{
	if (size == 0)
		return (multiple);
	return (((((size) - 1) / multiple) * multiple) + multiple);
}

static size_t		ft_header_size(void)
{
	return (ft_align_size(sizeof(t_lst_block), 16));
}

t_lst_block             *ft_tiny_blk(size_t size)
{
	size_t			i;
	size_t			page;
	t_lst_block		*block = NULL;

	i = 0;
	if ((block = g_heap[TINY_BLK].free))
	{
		while (block)
		{
			if (++i && block->size >= size)
			{
				ft_printf("ft_mode_stat() ? ft_stat_malloc(i) : 0\n");
				return (block);
			}
			block = block->next;
		}
		ft_printf("ft_mode_stat() ? ft_stat_malloc(i) : 0\n");
		ft_printf("block->last\n");
	}
	page = ft_align_size((SIZE_TINY_BLK + ft_header_size() * NB_BLOCKS), getpagesize());
	if ((block = mmap(block, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
	{
		block = NULL;
	}
	ft_printf("first allocations\n");
	return (g_heap[TINY_BLK].free);
}
