/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:26:22 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/09 16:56:22 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_in_heap.h"

#define MULTIPLE 16

#define DEBUG 1


void	ft_addr(unsigned long long ptr)
{
	const char	hex[16] = "0123456789abcdef";
	char	s[16];
	int	i;

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

void		*ft_malloc(size_t size)
{
	return (malloc(size));
}


static void	ft_select_pool(size_t size, t_lst_block **new_memory_blk)
{
	t_heap_zones	zone_type;
	size_t			zone_size;

	if (size < SIZE_TINY_BLK)
	{
		zone_type = TINY_BLK;
		zone_size = SIZE_TINY_BLK;
	}
	else if (size < SIZE_SMALL_BLK)
	{
		zone_type = SMALL_BLK;
		zone_size = SIZE_SMALL_BLK;
	}
	else
	{
		zone_type = LARGE_BLK;
		zone_size = 77777;//need to correct
	}
	*new_memory_blk = ft_find_ts_blk(size, zone_type, zone_size);
	if (new_memory_blk == NULL)
		return (NULL);
#if DEBUG
	ft_printf(RED"ZONE_TYPE = ");
	ft_putnbr(zone_type);
	ft_printf("\n"RESET);
#endif

	if (!g_heap[zone_type].free)
#if DEBUG
		ft_printf(YELLOW"!g_heeap\n"RESET);
#endif
}

void		*malloc(size_t size)
{
	t_lst_block		*new_block = NULL;

#if DEBUG
	ft_printf(BLUE"Malloc\n"RESET);
#endif
	

	size = (size ? ((((size) - 1) / MULTIPLE) * MULTIPLE) + MULTIPLE : MULTIPLE);


#if DEBUG
	ft_printf(RED"size after aling = ");
	ft_putnbr(size);
	ft_printf("\n"RESET);
#endif

	ft_select_pool(size, &new_block);
	return (new_block);
}
