/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:18:05 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 22:16:12 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2++ && n--)
	{
		if (*s1++ == '\0' || !n)
			return (0);
	}
	s2--;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
