/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:44:29 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/02 13:37:31 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*old_dst;
	const char	*old_src;
	size_t		cnt;
	size_t		dlen;

	old_dst = dst;
	old_src = src;
	cnt = size;
	while (cnt-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - old_dst;
	cnt = size - dlen;
	if (cnt-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (cnt != 0)
		{
			*dst++ = *src;
			cnt--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - old_src));
}
