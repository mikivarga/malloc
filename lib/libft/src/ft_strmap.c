/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:57:46 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 22:52:35 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
			{
				*ptr++ = (*f)(*s++);
				cnt++;
			}
			*ptr = '\0';
		}
		else
			return (NULL);
	}
	return (ptr - cnt);
}
