/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:07:16 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 23:14:16 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	ptr = NULL;
	if (s && len)
	{
		ptr = (char *)malloc((len + 1) * sizeof(*ptr));
		if (ptr)
		{
			ft_strncpy(ptr, s + start, len + 1);
			*(ptr + len) = '\0';
		}
		return (ptr);
	}
	return (NULL);
}
