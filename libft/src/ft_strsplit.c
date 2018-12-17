/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:29:58 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/02 21:41:14 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t		ft_nw(char const *s, char c)
{
	size_t		nw;
	int			state;
	int			in;
	int			out;

	in = 1;
	out = 0;
	state = out;
	nw = 0;
	while (*s)
	{
		if (*s == c)
			state = out;
		else if (state == out)
		{
			state = in;
			++nw;
		}
		s++;
	}
	return (nw);
}

static	size_t		ft_copy_character(char **pp, char const *s, char c)
{
	size_t		nc;

	nc = 0;
	while (*s != c && *s)
	{
		nc++;
		s++;
	}
	*pp = ft_strnew(nc);
	s -= nc;
	*pp = ft_strncpy(*pp, s, nc);
	return (nc);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**pp;
	size_t	size;

	if (s)
	{
		size = ft_nw((char *)s, c);
		pp = (char **)malloc(sizeof(char *) * (size + 1));
		if (!pp)
			return (NULL);
		while (*s)
		{
			if (*s != c && *s)
				s += ft_copy_character(pp++, s, c);
			if (!*s)
				break ;
			s++;
		}
		*pp = 0;
		return (pp - size);
	}
	return (NULL);
}
