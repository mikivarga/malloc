/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:30:08 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/24 14:31:40 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_in_heap.h"

void		*realloc(void *ptr, size_t size)
{
	void			*new_data;
	t_element_block	*old_data;

	if (!ptr)
		return (malloc(size));
	old_data = (t_element_block *)(ptr) - 1;
	if (ft_make_free(ptr) == FALSE)
		return (NULL);
	if (size <= old_data->size)
	{
		old_data->free = FALSE;
		return (ptr);
	}
	new_data = malloc(size);
	ft_memmove(new_data, ptr, old_data->size);
	return (new_data);
}
