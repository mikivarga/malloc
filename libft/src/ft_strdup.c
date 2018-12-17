/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:33:27 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/03 18:25:40 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	size;
	char	*newstr;
	char	*copy;

	size = ft_strlen(s1) + 1;
	copy = (char *)malloc(size);
	if (copy == NULL)
		return (NULL);
	newstr = copy;
	while (*s1)
		*copy++ = *s1++;
	*copy = '\0';
	return (newstr);
}
