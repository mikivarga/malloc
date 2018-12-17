/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:40:31 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/02 17:09:51 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc((size + 1) * sizeof(*ptr));
	if (ptr != NULL)
	{
		ft_bzero(ptr, size + 1);
	}
	return (ptr);
}
