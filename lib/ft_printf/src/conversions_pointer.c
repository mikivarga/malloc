/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:36:01 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 16:37:15 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void			ft_pointer(unsigned char c, va_list ap)
{
	uint64_t	data;
	int			base;
	char		*prefix;

	base = 16;
	g_achar = 'a';
	if (!c)
		return ;
	data = (uint64_t)va_arg(ap, void *);
	prefix = ft_strdup("0x");
	if (!data && g_prec <= 0 && g_point)
	{
		if (g_width > 2)
			ft_pr_sp(g_zero ? '0' : ' ', g_width - (int)ft_strlen(prefix));
		ft_pr(prefix, ft_strlen(prefix));
	}
	else
		ft_pr_point(prefix, data, base);
	free(prefix);
}
