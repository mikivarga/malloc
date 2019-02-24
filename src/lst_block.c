/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:15:07 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/24 14:35:12 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_in_heap.h"

int			lst_init_block(
t_lst_block *lst, size_t size)
{
	lst->start = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC,
MAP_PRIVATE | MAP_ANON, -1, 0);
	if (lst->start == MAP_FAILED)
	{
		return (FALSE);
	}
	lst->end = (void *)lst->start + size - sizeof(t_lst_block);
	lst->start->next = lst->end;
	lst->start->prev = NULL;
	lst->end->next = NULL;
	lst->end->prev = lst->start;
	lst->ptr = lst->start;
	return (TRUE);
}

void		lst_fragment(
t_lst_block *lst, size_t size, size_t zone_size)
{
	t_element_block	*begin;
	t_element_block	*end;
	size_t			size_tmp;

	begin = lst->start;
	while (lst_move_ptr_left(lst))
		if (lst->ptr->free == FALSE)
		{
			begin = lst->ptr;
			break ;
		}
	while (lst_move_ptr_right(lst))
		if (lst->ptr->free == FALSE)
			break ;
	end = lst->ptr;
	size_tmp = (void *)(lst->end ?
(void *)begin->next + end->size : end->next) - (void *)begin->next;
	lst->ptr = begin;
	lst->ptr->next = end->next;
	lst_put_post(lst, size, zone_size);
	lst->ptr = lst->ptr->next;
	if ((int)(size_tmp - size - sizeof(t_element_block)) < 0)
		return ;
	lst_put_post(lst, size_tmp - size - sizeof(t_element_block), zone_size);
	lst->ptr->next->free = TRUE;
}

int			lst_put_post(t_lst_block *lst, size_t size, size_t zone_size)
{
	t_element_block	*tmp;

	if (lst->ptr == lst->end)
		return (FALSE);
	if (((void *)lst->end -
((void *)(lst->ptr + 1) + lst->ptr->size)) >= (int)size)
		tmp = (lst->ptr == lst->start ?
(lst->ptr + 1) : (void *)(lst->ptr + 1) + lst->ptr->size);
	else
	{
		tmp = mmap(lst->end, zone_size,
PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0);
		if (tmp == MAP_FAILED)
			return (FALSE);
		lst->end = (void *)tmp + zone_size - sizeof(t_lst_block);
		lst->ptr->next = lst->end;
		lst->end->prev = lst->ptr;
	}
	tmp->size = size;
	tmp->free = FALSE;
	tmp->next = lst->ptr->next;
	tmp->prev = lst->ptr;
	lst->ptr->next->prev = tmp;
	lst->ptr->next = tmp;
	return (TRUE);
}

int			lst_move_ptr_left(t_lst_block *lst)
{
	if (lst->ptr == lst->start)
		return (FALSE);
	lst->ptr = lst->ptr->prev;
	return (TRUE);
}

int			lst_move_ptr_right(t_lst_block *lst)
{
	if (lst->ptr->next == lst->end)
		return (FALSE);
	lst->ptr = lst->ptr->next;
	return (TRUE);
}
