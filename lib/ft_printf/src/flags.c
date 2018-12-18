/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:48:19 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 16:51:49 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*ft_get_nbr(int *n, const char *str)
{
	*n = 0;
	while (ft_isdigit(*str))
	{
		*n = *n * 10 + (*str - '0');
		str++;
	}
	return (str);
}

const char			*ft_flg_min_plus_space_zero_prefix(const char *str)
{
	if (*str == '-')
	{
		g_sign = -1;
		str++;
	}
	if (*str == '+' || *str == ' ')
	{
		if (g_plus_space < *str)
			g_plus_space = *str;
		str++;
	}
	if (*str == '#')
	{
		g_pref = 1;
		str++;
	}
	if (*str == '0')
	{
		g_zero = 1;
		str++;
	}
	return (str);
}

const char			*ft_flg_width(const char *str, va_list ap)
{
	int		n;

	if (*str == '*')
	{
		g_width = va_arg(ap, int);
		if (g_width < 0)
		{
			g_width = -g_width;
			g_sign = -g_sign;
			str++;
		}
	}
	else if (ft_isdigit(*str) && *str != '0')
	{
		str = ft_get_nbr(&n, str);
		{
			g_width = n;
			g_width *= g_sign;
		}
	}
	return (str);
}

const char			*ft_flg_precision(const char *str, va_list ap)
{
	if (*str == '.')
	{
		g_point = 1;
		if (*(++str) == '*')
		{
			g_prec = va_arg(ap, int);
			str++;
		}
		else if (ft_isdigit(*str))
			str = ft_get_nbr(&g_prec, str);
		else
			g_prec = -1;
	}
	else if (g_prec == -1)
		g_prec = -1;
	return (str);
}
