/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:41:50 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 21:43:56 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*newstr;

	newstr = dst;
	while (len && *src)
	{
		*newstr++ = *src++;
		len--;
	}
	while (len--)
		*newstr++ = '\0';
	return (dst);
}
