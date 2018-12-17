/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:35:10 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 22:57:18 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ptr;
	size_t		cnt;

	ptr = NULL;
	cnt = 0;
	if (s)
	{
		ptr = (char *)malloc((ft_strlen(s) + 1) * sizeof(*ptr));
		if (ptr != NULL)
		{
			while (*s)
				*ptr++ = (*f)(cnt++, *s++);
			*ptr = '\0';
		}
		else
			return (NULL);
	}
	return (ptr - cnt);
}
