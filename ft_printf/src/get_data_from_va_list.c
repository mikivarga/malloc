/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_va_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:31:37 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/02 16:47:00 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ft_get_unsigned_from_va_list(unsigned char c, va_list ap)
{
	uintmax_t	data;

	if (c == HH)
		data = (unsigned char)va_arg(ap, unsigned int);
	else if (c == 'h')
		data = (unsigned short int)va_arg(ap, unsigned int);
	else if (c == LL)
		data = (unsigned long long int)va_arg(ap, unsigned long long);
	else if (c == 'l')
		data = (unsigned long int)va_arg(ap, unsigned long long);
	else if (c == 'j')
		data = (uintmax_t)va_arg(ap, uintmax_t);
	else if (c == 'z')
		data = (size_t)va_arg(ap, size_t);
	else if (ft_flg_check(c, 17, SIZE) && g_convers)
		data = (unsigned int)va_arg(ap, int);
	else
		data = c;
	return (data);
}

int64_t			ft_get_signed_from_va_list(unsigned char c, va_list ap)
{
	int64_t		data;

	if (c == HH)
		data = (char)va_arg(ap, unsigned int);
	else if (c == 'h')
		data = (short int)va_arg(ap, unsigned int);
	else if (c == LL)
		data = (long long int)va_arg(ap, unsigned long long);
	else if (c == 'l')
		data = (long int)va_arg(ap, unsigned long long);
	else if (c == 'j')
		data = (int64_t)va_arg(ap, uintmax_t);
	else if (c == 'z')
		data = (int64_t)va_arg(ap, size_t);
	else if (ft_flg_check(c, 17, SIZE) && g_convers)
		data = (int)va_arg(ap, int);
	else
		data = c;
	return (data);
}
