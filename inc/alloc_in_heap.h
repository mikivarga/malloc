/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_in_heap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:22:02 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/03 18:15:20 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_IN_HEAP_H
# define ALLOC_IN_HEAP_H

# include <unistd.h>
# include <sys/mman.h>
# include "../lib/ft_printf/inc/ft_printf.h"

# define RED	"\033[01;31m"
# define GREEN	"\033[01;32m"
# define YELLOW	"\033[01;33m"
# define BLUE	"\033[01;34m"
# define PINK	"\033[01;35m"
# define CYAN	"\033[01;36m"
# define WHITE	"\033[01;37m"
# define RESET	"\033[00m"

#define NB_BLOCKS 100
# define SIZE_TINY_BLK 257
# define SIZE_SMALL_BLK 4097
# define CNT_TYPE_ZONES 3

typedef enum			e_heap_zones
{
	TINY_BLK,
	SMALL_BLK,
	LARGE_BLK
}						t_heap_zones;

typedef struct			s_lst_block
{
	size_t				size;
	struct s_lst_block	*prev;
	struct s_lst_block	*next;
}						t_lst_block;


typedef struct			s_heap
{
	t_lst_block			*free;
	t_lst_block			*booked;
}						t_heap;

t_heap  g_heap[CNT_TYPE_ZONES];

void					*malloc(size_t size);
void					*ft_malloc(size_t size);
t_lst_block				*ft_tiny_blk(size_t size);
#endif
