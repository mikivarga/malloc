/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:12:56 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 22:12:46 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		size;

	size = ft_strlen(little);
	if (!(*little))
		return ((char *)big);
	while (len && *big)
	{
		if (len < size)
			break ;
		if (!ft_strncmp(big, little, size))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
