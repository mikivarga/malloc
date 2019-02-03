/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:26:22 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/02 18:13:58 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_in_heap.h"

#define MULTIPLE 16

void		*ft_malloc(size_t size)
{
	return (malloc(size));
}

void		*malloc(size_t size)
{
	t_heap_zones	type_zones;
	//t_block			*block;

	ft_printf(BLUE"Malloc\n"RESET);
	size = (size ? ((((size) - 1) / MULTIPLE) * MULTIPLE) + MULTIPLE : MULTIPLE);

	ft_printf(RED"size after aling = ");
	ft_putnbr(size);
	ft_printf("\n"RESET);

	type_zones = (size <= TINY_BLOCK_SIZE ? TINY : SMALL);
	type_zones = (size <= TINY_BLOCK_SIZE ? TINY : SMALL);

	
	
	return (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}
