/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:00:29 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/02 21:42:41 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_count_nb(int n)
{
	int		cnt;

	cnt = 1;
	if (n < 0)
		cnt++;
	while (n / 10)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

static	char	*ft_nb_str(char *p, long n)
{
	*p-- = '\0';
	while (n / 10)
	{
		*p-- = n % 10 + '0';
		n /= 10;
	}
	*p = n + '0';
	return (p);
}

char			*ft_itoa(int n)
{
	int		sign;
	int		cnt;
	char	*rez;
	long	number;

	number = n;
	cnt = ft_count_nb(n);
	sign = (n >= 0) ? 0 : 1;
	rez = (char*)malloc(sizeof(char) * ((cnt + 1)));
	if (!rez)
		return (NULL);
	if (!sign)
		rez = ft_nb_str(rez += cnt, number);
	else
	{
		number *= -1;
		rez = ft_nb_str(rez += cnt, number);
		*(--rez) = '-';
	}
	return (rez);
}
