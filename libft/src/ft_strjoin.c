/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:24:10 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 23:18:04 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		ptr = (char *)malloc(len + 1);
		if (ptr)
		{
			ft_strcpy(ptr, s1);
			ft_strcat(ptr, s2);
			return (ptr);
		}
	}
	return (NULL);
}
