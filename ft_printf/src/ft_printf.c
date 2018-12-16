/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:15:58 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 18:18:06 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			g_arr_flags[SIZE] = {
	',', ';', ':', '_', '.', '-', '+', ' ', '#', '0',
	'h', 'j', 'l', 'L', 't', 'z', '*', 'c', 'C', 's',
	'S', 'd', 'D', 'i', 'u', 'U', 'o', 'O', 'x', 'X',
	'p'
};

void			(*g_pf[14])(unsigned char, va_list) = {
	ft_char, ft_char, ft_str, ft_wstr, ft_signed_digit, ft_signed_digit,
	ft_signed_digit, ft_unsigned_digit, ft_unsigned_digit, ft_o_digit,
	ft_o_digit, ft_x_digit, ft_big_x_digit, ft_pointer
};

static int			ft_funct_arr(char c, va_list ap)
{
	int		i;
	int		j;

	i = 17;
	j = 17;
	while (i < SIZE)
	{
		if (c == g_arr_flags[i])
		{
			if (c == 'D' || c == 'O' || c == 'U' || c == 'C')
				g_pf[i - j](c, ap);
			else if (g_size_type)
				g_pf[i - j](g_size_type, ap);
			else
				g_pf[i - j](c, ap);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int					ft_flg_check(char c, int start, int end)
{
	while (start < end)
		if (g_arr_flags[start++] == c)
			return (TRUE);
	return (FALSE);
}

static const char	*ft_flags(const char *str, va_list ap)
{
	while ((ft_flg_check(*str, 0, 16) || ft_isdigit(*str)) && *str)
	{
		str = ft_flg_min_plus_space_zero_prefix(str);
		str = ft_flg_width(str, ap);
		str = ft_flg_precision(str, ap);
		if (ft_flg_check(*str, 10, 16) && *str)
		{
			if (g_size_type < *str)
				g_size_type = *str;
			else if (g_size_type == *str && *str == 'h')
				g_size_type += *str;
			else if ((g_size_type / 2) == *str && *str == 'h')
				g_size_type -= *str;
			else if (g_size_type == *str && *str == 'l')
				g_size_type += *str;
			else if ((g_size_type / 2) < *str && ft_flg_check(*str, 11, 16))
				g_size_type = *str;
			str++;
		}
	}
	if (!*str && ft_flg_check(*(str - 1), 0, 16))
		--str;
	if (!ft_funct_arr(*str, ap) && !ft_flg_check(*str, 0, 16))
		ft_no_conversion(*str);
	return (++str);
}

static void			ft_init_g_variable(void)
{
	g_sign = 1;
	g_zero = 0;
	g_plus_space = 0;
	g_size_type = 0;
	g_convers = 0;
	g_width = 0;
	g_prec = -1;
	g_point = 0;
	g_pref = 0;
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;

	g_cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			ft_print(*format++);
		ft_init_g_variable();
		if (*format == '%')
		{
			g_convers = 1;
			if (*(format + 1) != '\0')
				format = ft_flags(format + 1, ap);
			else
				break ;
		}
	}
	va_end(ap);
	return (g_cnt);
}
