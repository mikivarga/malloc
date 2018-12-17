/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:35:02 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/02 13:42:48 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	char		*p_big;
	int			size;

	size = ft_strlen(little);
	p_big = (char *)big;
	if (!(*little))
		return (p_big);
	while (*p_big)
	{
		if (!ft_strncmp(p_big, little, size))
			return (p_big);
		p_big++;
	}
	return (NULL);
}
