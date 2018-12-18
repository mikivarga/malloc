/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:33:21 by mvarga            #+#    #+#             */
/*   Updated: 2017/02/28 18:20:49 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print(char c)
{
	ft_putchar(c);
	g_cnt++;
}

void			ft_pr_sp(char c, size_t len)
{
	while (len--)
		ft_print(c);
}

void			ft_pr(char *str, size_t len)
{
	while (len--)
	{
		ft_putchar(*str++);
		g_cnt++;
	}
}
