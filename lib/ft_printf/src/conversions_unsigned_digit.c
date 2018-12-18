/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_unsigned_digit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:15:51 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 16:47:16 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static void		ft_prefix(char **prefix, int64_t data, char *pr)
{
	if (g_pref && data)
	{
		*prefix = ft_strdup(pr);
		if (g_zero && g_pref && g_prec == -1)
			g_prec = g_width - ft_strlen(*prefix);
	}
	else if (g_pref || g_sign || g_prec >= 0 || g_plus_space)
	{
		*prefix = ft_strdup("\0");
		g_pref = 1;
	}
	else if (g_zero)
		*prefix = ft_strdup("0");
	else
		*prefix = ft_strdup("\0");
}

void			ft_o_digit(unsigned char c, va_list ap)
{
	uint64_t	data;
	int			neg;
	char		*prefix;

	neg = 0;
	g_achar = 'a';
	if (c == 'O')
		c = 'l';
	data = ft_get_unsigned_from_va_list(c, ap);
	if (g_pref)
		prefix = ft_strdup("0");
	else
		prefix = ft_strdup("\0");
	if (data == 0 && g_prec <= 0 && g_point && !g_pref)
	{
		ft_pr_sp(' ', g_width);
		return ;
	}
	else if (data == 0 && g_pref)
	{
		prefix = ft_strdup("\0");
	}
	ft_print_digit(prefix, data, 8, neg);
	free(prefix);
}

void			ft_x_digit(unsigned char c, va_list ap)
{
	uint64_t	data;
	int			neg;
	int			base;
	char		*prefix;

	base = 16;
	neg = 0;
	g_achar = 'a';
	data = ft_get_unsigned_from_va_list(c, ap);
	ft_prefix(&prefix, data, "0x");
	if (data == 0 && g_prec <= 0 && g_point)
	{
		ft_pr_sp(' ', g_width);
		return ;
	}
	ft_print_digit(prefix, data, base, neg);
	free(prefix);
}

void			ft_big_x_digit(unsigned char c, va_list ap)
{
	uint64_t	data;
	int			neg;
	int			base;
	char		*prefix;

	base = 16;
	neg = 0;
	g_achar = 'A';
	data = ft_get_unsigned_from_va_list(c, ap);
	ft_prefix(&prefix, data, "0X");
	if (data == 0 && g_prec <= 0 && g_point)
	{
		ft_pr_sp(' ', g_width);
		return ;
	}
	ft_print_digit(prefix, data, base, neg);
	free(prefix);
}

void			ft_unsigned_digit(unsigned char c, va_list ap)
{
	uint64_t	data;
	int			neg;
	char		*prefix;

	neg = 0;
	g_achar = 'a';
	if (c == 'U')
		c = 'l';
	data = ft_get_unsigned_from_va_list(c, ap);
	if (g_pref || g_width || g_prec >= 0 || g_plus_space || data)
	{
		prefix = ft_strdup("\0");
		g_pref = 1;
	}
	else if (g_zero)
		prefix = ft_strdup("\0");
	else
		prefix = ft_strdup("\0");
	if (data == 0 && g_prec <= 0 && g_point)
	{
		ft_pr_sp(' ', g_width);
		return ;
	}
	ft_print_digit(prefix, data, 10, neg);
	free(prefix);
}
