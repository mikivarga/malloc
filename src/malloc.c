/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:26:22 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/03 16:59:18 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_in_heap.h"

#define MULTIPLE 16

#define DEBUG 1

void		*ft_malloc(size_t size)
{
	return (malloc(size));
}


static void	ft_select_pool(size_t size, t_lst_block *new_memory_blk)
{
	t_heap_zones	zone_type;

	if (size < SIZE_TINY_BLK)
	{
		zone_type = TINY_BLK;
		new_memory_blk =  ft_tiny_blk(size);
	}
	else if (size < SIZE_SMALL_BLK)
		zone_type = SMALL_BLK;
	else
		zone_type = LARGE_BLK;
#if DEBUG
	ft_printf(RED"ZONE_TYPE = ");
	ft_putnbr(zone_type);
	ft_printf("\n"RESET);
#endif

	if (!g_heap[zone_type].free)
#if DEBUG
		ft_printf(YELLOW"!g_heeap\n"RESET);
#endif
	
	new_memory_blk = NULL;
}

void		*malloc(size_t size)
{
	t_lst_block		*new_memory_blk = NULL;

#if DEBUG
	ft_printf(BLUE"Malloc\n"RESET);
#endif
	size = (size ? ((((size) - 1) / MULTIPLE) * MULTIPLE) + MULTIPLE : MULTIPLE);
#if DEBUG
	ft_printf(RED"size after aling = ");
	ft_putnbr(size);
	ft_printf("\n"RESET);
#endif	
	ft_select_pool(size, new_memory_blk);
	ft_printf("sizeof : ");
	ft_putnbr(sizeof(size_t));
	ft_printf("\n");
	ft_printf("sizeof t_lst_blk: ");
	ft_putnbr(sizeof(t_lst_block));
	ft_printf("\n");
	return (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

}
