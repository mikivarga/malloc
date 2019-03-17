/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_in_heap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:56:55 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/24 14:14:29 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_IN_HEAP_H
# define ALLOC_IN_HEAP_H

# include <unistd.h>
# include <sys/mman.h>
# include "../lib/ft_printf/inc/ft_printf.h"
# include "../lib/libft/inc/libft.h"

# define NB_BLOCKS 100
# define SIZE_TINY_BLK 513
# define SIZE_SMALL_BLK 1025
# define ZONES_TYPE 3

typedef enum				e_zones_heap
{
	TINY_BLK,
	SMALL_BLK,
	LARGE_BLK
}							t_heap_zones;

typedef struct				s_element_block
{
	size_t					size;
	struct s_element_block	*prev;
	struct s_element_block	*next;
	size_t					free;
}							t_element_block;

typedef struct				s_lst_block
{
	t_element_block			*start;
	t_element_block			*end;
	t_element_block			*ptr;
	t_element_block			*padding;
}							t_lst_block;

t_lst_block					g_heap[ZONES_TYPE];

void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);
void						free(void *ptr);

void						show_alloc_mem(void);
void						show_alloc_mem_ex(void);

int							lst_init_block(t_lst_block *lst, size_t size);
int							lst_put_post
(t_lst_block *lst, size_t size, size_t zone_size);
void						lst_fragment
(t_lst_block *lst, size_t size, size_t zone_size);
int							lst_move_ptr_left(t_lst_block *lst);
int							lst_move_ptr_right(t_lst_block *lst);

int							ft_make_free(void *ptr);
#endif
