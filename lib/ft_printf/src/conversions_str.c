/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:59:09 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 18:44:23 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strnlen(char *str, size_t len)
{
	size_t		n;

	n = 0;
	while (*str++ && (n < len))
		n++;
	return (n);
}

static void		ft_pr_left_right(char *str, size_t len)
{
	int			to_left;

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
			ft_pr(str, len);
			ft_pr_sp(' ', g_width - (int)len);
		}
		else
		{
			ft_pr_sp((g_zero ? '0' : ' '), g_width - (int)len);
			ft_pr(str, len);
		}
	}
	else
		ft_pr(str, len);
}

static void		ft_prstr(size_t len, char *str)
{
	if (g_point && g_prec <= 0)
		ft_pr_sp(g_zero ? '0' : ' ', g_width);
	else
	{
		len = (g_prec != -1 ? ft_strnlen(str, g_prec) : ft_strlen(str));
		if (!g_width)
		{
			g_width = (g_prec != -1 ? g_prec : (int)len);
			if (g_prec > (int)len)
				g_width = ft_strlen(str);
		}
		ft_pr_left_right(str, len);
	}
}

void			ft_str_null(char *str)
{
	size_t		len;

	len = (g_prec > 0 ? ft_strnlen(str, g_prec) : ft_strlen(str));
	if (!g_width)
		g_width = (g_prec > 0 ? g_prec : (int)len);
	if (*str)
		ft_pr_left_right(str, len);
}

void			ft_str(unsigned char c, va_list ap)
{
	size_t		len;
	char		*str;

	len = 0;
	if (g_size_type == 'l')
		ft_wstr(c, ap);
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL && !g_zero)
			ft_str_null("(null)");
		else
			ft_prstr(len, str);
	}
}
