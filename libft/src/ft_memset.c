/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:35:55 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 20:48:43 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char			*s;
	unsigned char	v;

	v = (unsigned char)c;
	s = b;
	while (len--)
		*s++ = v;
	return (b);
}
