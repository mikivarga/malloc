/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_in_heap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:22:02 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/02 18:08:24 by mvarga           ###   ########.fr       */
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

# define TINY_BLOCK_SIZE 512
# define SMALL_BLOCK_SIZE 4096

typedef enum			e_heap_zones
{
	TINY,
	SMALL,
	LARGE
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

void					*malloc(size_t size);
void					*ft_malloc(size_t size);

#endif
