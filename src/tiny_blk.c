/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_blk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:31:55 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/09 16:53:32 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alloc_in_heap.h"

void	ft_putaddr(unsigned long long ptr)
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


static size_t			ft_check_free_block(t_lst_block **blk, size_t size)
{
	size_t i;

	i = 0;
	while (*blk)
	{
		printf("if ((block = g_heap[TINY_BLK].free) != NULL)\n");
		i++;
		if ((*blk)->size >= size)
		{
			ft_printf("ft_mode_stat() ? ft_stat_malloc(i) : 0\n");
			break ;
		}
		*blk = (*blk)->next;
	}
	return (i);
}

t_lst_block             *ft_find_ts_blk(size_t size, t_heap_zones zone_type, size_t zone_size)
{
	size_t			i;
	size_t			page;
	t_lst_block		*block = NULL;
	t_lst_block		*free_blk;

	free_blk = g_heap[zone_type].free;
	i = ft_check_free_block(&free_blk, size);
	if (free_blk)
		return (free_blk);
	ft_printf("ft_mode_stat() ? ft_stat_malloc(i++) : 0 LAST\n");
	page = ft_align_size((zone_size + ft_header_size() * NB_BLOCKS), getpagesize());
	ft_printf(CYAN"first allocations\n");
	if ((block = mmap(free_blk, page, PROT_READ | PROT_WRITE | PROT_EXEC, \
					  MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		block = NULL;
	if (g_heap[zone_type].free)
		free_blk = block;
	else
		g_heap[zone_type].free = block;
	block->size = page;
	block->next = NULL;
	block->prev = free_blk;
/*	ft_printf("add = ");
	ft_putaddr((unsigned long long)tmp);	
	ft_printf("\n"RESET);
	ft_printf("add = ");
	ft_putaddr((unsigned long long)block);	
	ft_printf("\n"RESET);*/
	return (block);
}