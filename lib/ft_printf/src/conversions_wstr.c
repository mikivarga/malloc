/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_wstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:58:29 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 16:57:36 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_wstrnlen(wchar_t *wstr, size_t len)
{
	size_t		n;

	n = 0;
	if (len == 0)
	{
		while (*wstr++)
			n++;
	}
	else
	{
		while (*wstr++ && (n < len))
			n++;
	}
	return (n);
}

static void			ft_ascii_utf(wchar_t *c, size_t len)
{
	while (len--)
	{
		if (*c <= BYTE_ASCII)
			ft_print(*c);
		else
		{
			if (*c <= BYTE_UTF2)
				ft_print((*c >> 6) + 192);
			else if (*c <= BYTE_UTF3)
			{
				ft_print((*c >> 12) + 224);
				ft_print(((*c >> 6) & 63) + 128);
			}
			else if (*c <= BYTE_UTF4)
			{
				ft_print((*c >> 18) + 240);
				ft_print(((*c >> 12) & 63) + 128);
				ft_print(((*c >> 6) & 63) + 128);
			}
			else
				return ;
			ft_print((*c & 63) + 128);
		}
		c++;
	}
}

static void			ft_pr_left_right(wchar_t *c, size_t len, size_t pr)
{
	int			to_left;

	to_left = 0;
	if (g_width < 0)
	{
		g_width = -g_width;
		to_left = 1;
	}
	if (g_width > (int)(len * pr))
	{
		if (to_left)
		{
			ft_ascii_utf(c, len);
			ft_pr_sp(' ', g_width - (int)(len * pr));
		}
		else
		{
			ft_pr_sp((g_zero ? '0' : ' '), g_width - (int)(len * pr));
			ft_ascii_utf(c, len);
		}
	}
	else
		ft_ascii_utf(c, len);
}

static size_t		ft_size_wch(wchar_t wstr)
{
	size_t		size;

	size = 1;
	if (wstr <= BYTE_ASCII)
		size = 1;
	else if (wstr <= BYTE_UTF2)
		size = 2;
	else if (wstr <= BYTE_UTF3)
		size = 3;
	else if (wstr <= BYTE_UTF4)
		size = 4;
	while (g_prec > 0)
	{
		if ((g_prec % size) != 0)
			g_prec -= 1;
		else
		{
			g_prec /= size;
			break ;
		}
		if (g_prec < (int)size)
			g_prec = 0;
	}
	return (size);
}

void				ft_wstr(unsigned char c, va_list ap)
{
	size_t		len;
	size_t		sizewch;
	wchar_t		*wstr;

	if (!c)
		return ;
	wstr = va_arg(ap, wchar_t *);
	if (wstr == NULL && !g_zero)
	{
		ft_str_null("(null)");
		return ;
	}
	if (g_point && g_prec <= 0)
		ft_pr_sp(g_zero ? '0' : ' ', g_width);
	else
	{
		sizewch = ft_size_wch(*wstr);
		len = (g_prec != -1 ? ft_wstrnlen(wstr, g_prec) : ft_wstrnlen(wstr, 0));
		if (!g_width)
		{
			g_width = (g_prec != -1 ? g_prec : (int)len);
			g_width = (g_prec > (int)len ? (int)ft_wstrnlen(wstr, 0) : g_width);
		}
		ft_pr_left_right(wstr, len, sizewch);
	}
}
