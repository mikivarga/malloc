/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_signed_digit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:17:45 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/07 20:18:38 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int64_t		ft_prefix(char **prefix, int64_t data, int *neg)
{
	if (g_pref || g_sign || g_prec >= 0 || g_plus_space)
	{
		*prefix = ft_strdup("\0");
		g_pref = 1;
	}
	else if (g_zero)
		*prefix = ft_strdup("0");
	else
		*prefix = ft_strdup("\0");
	if (data < 0)
	{
		*neg = '-';
		data = -data;
	}
	return (data);
}

void				ft_signed_digit(unsigned char c, va_list ap)
{
	int64_t		data;
	int			neg;
	int			base;
	char		*prefix;

	base = 10;
	neg = 0;
	g_achar = 'a';
	if (c == 'D')
		c = 'l';
	data = ft_get_signed_from_va_list(c, ap);
	if (g_plus_space == ' ' && data >= 0)
		neg = ' ';
	else if (g_plus_space == '+' && data >= 0)
		neg = '+';
	data = ft_prefix(&prefix, data, &neg);
	if (data == 0 && g_prec <= 0 && g_point)
	{
		ft_pr_sp(' ', g_width);
		return ;
	}
	ft_print_digit(prefix, data, base, neg);
	free(prefix);
}
