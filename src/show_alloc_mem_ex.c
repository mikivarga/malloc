/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:10:31 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/02 14:34:06 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_in_heap.h"

static void	ft_dump_hexa(const void *addr)
{
	const char	hex[16] = "0123456789abcdef";
	int			tmp;

	tmp = *(char*)addr >> 4 & 0x0F;
	write(1, &hex[tmp], 1);
	tmp = *(char*)addr & 0x0F;
	write(1, &hex[tmp], 1);
}

static void	ft_print_last_line(int i, char str[16])
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
		write(1, str, i % 16);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

static void	ft_print_memory(const void *addr, size_t size)
{
	char	str[16];
	size_t	i;

	ft_bzero(str, 16);
	i = 0;
	while (i < size)
	{
		ft_dump_hexa(addr);
		str[i % 16] = *(char*)addr;
		if (str[i % 16] < 32 || str[i % 16] > 126)
			str[i % 16] = '.';
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
		{
			write(1, str, 16);
			write(1, "\n", 1);
			ft_bzero(str, 16);
		}
		addr++;
	}
	ft_print_last_line(i, str);
}

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
			ft_print_memory((void *)(tmp + 1), tmp->size);
		}
		blk->ptr = tmp;
	}
}

void		show_alloc_mem_ex(void)
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
