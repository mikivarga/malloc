/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:50:29 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/03 17:18:26 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr;

	ptr = s;
	while (n--)
	{
		if (*ptr++ == (unsigned char)c)
			return ((void *)(ptr - 1));
	}
	return (NULL);
}
