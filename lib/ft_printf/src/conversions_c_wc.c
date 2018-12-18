/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_c_wc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 21:33:02 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 19:04:08 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static void		ft_ascii_utf(uintmax_t c)
{
	if (c <= 0xFF)
		ft_print(c);
	else
	{
		if (c <= BYTE_UTF2)
			ft_print((c >> 6) + 192);
		else if (c <= BYTE_UTF3)
		{
			ft_print((c >> 12) + 224);
			ft_print(((c >> 6) & 63) + 128);
		}
		else if (c <= BYTE_UTF4)
		{
			ft_print((c >> 18) + 240);
			ft_print(((c >> 12) & 63) + 128);
			ft_print(((c >> 6) & 63) + 128);
		}
		else
			return ;
		ft_print((c & 63) + 128);
	}
}

static void		ft_pr_left_right(uintmax_t c, size_t len)
{
	int		to_left;

	to_left = 0;
	if (g_width < 0)
	{
		g_width = -g_width;
		to_left = 1;
	}
	if (g_width > (int)len)
	{
		if (to_left)
		{
			ft_ascii_utf(c);
			ft_pr_sp(' ', g_width - (int)len);
		}
		else
		{
			ft_pr_sp((g_zero ? '0' : ' '), g_width - (int)len);
			ft_ascii_utf(c);
		}
	}
	else
		ft_ascii_utf(c);
}

static size_t	ft_wchar(uintmax_t data)
{
	size_t len;

	len = 1;
	if (data <= BYTE_ASCII)
		len = 1;
	else if (data <= BYTE_UTF2)
		len = 2;
	else if (data <= BYTE_UTF3)
		len = 3;
	else if (data <= BYTE_UTF4)
		len = 4;
	return (len);
}

void			ft_char(unsigned char c, va_list ap)
{
	uintmax_t	data;
	char		*str;

	if (!c)
		return ;
	data = va_arg(ap, int);
	if (data > BYTE_ASCII)
	{
		str = ft_strnew(1);
		*str = data;
		ft_str_null(str);
		free(str);
	}
	else
		ft_pr_left_right(data, ft_wchar(data));
}

void			ft_no_conversion(char c)
{
	size_t	len;

	len = 1;
	ft_pr_left_right(c, len);
}
