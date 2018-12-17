/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:35:29 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/02 22:59:54 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char		*ptr;
	const char	*se;
	size_t		len;

	if (s)
	{
		len = ft_strlen(s);
		while ((*s == ' ' || *s == '\n' || *s == '\t') && len--)
			s++;
		if (len)
		{
			se = (s + (len - 1));
			while ((*se == ' ' || *se == '\n' || *se == '\t') && len--)
				se--;
		}
		if ((ptr = (char *)malloc((len + 1) * sizeof(*ptr))))
		{
			ptr = ft_strncpy(ptr, s, len);
			*(ptr + len) = '\0';
			return (ptr);
		}
	}
	return (NULL);
}
