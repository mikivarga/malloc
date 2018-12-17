/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:33:51 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 22:40:06 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * sizeof(*ptr));
	if (ptr != NULL)
		ft_bzero(ptr, size);
	return (ptr);
}
