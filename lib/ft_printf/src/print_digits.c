/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:32:41 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/08 18:31:37 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char		*g_str;
static char		*g_tmp;

static void		ft_pr_left_right(char *s, size_t len, int toleft)
{
	if (g_width > (int)len)
	{
		if (toleft)
		{
			ft_pr(s, len);
			ft_pr_sp(' ', g_width - (int)len);
		}
		else
		{
			ft_pr_sp((g_zero ? '0' : ' '), g_width - (int)len);
			ft_pr(s, len);
		}
	}
	else
		ft_pr(s, len);
}

static void		ft_pr_left_right_minus(char *s, size_t len, int toleft, int neg)
{
	if (g_width-- > (int)len)
	{
		if (toleft)
		{
			ft_print(neg);
			ft_pr_left_right(s, len, toleft);
		}
		else
		{
			if (!g_zero)
			{
				ft_pr_sp(' ', g_width - (int)len);
				ft_print(neg);
				ft_pr(s, len);
			}
			else
			{
				ft_print(neg);
				ft_pr_left_right(s, len, toleft);
			}
		}
		return ;
	}
	ft_print(neg);
	ft_pr(s, len);
}

static void		ft_print_int_str(char *s, int neg)
{
	size_t		len;
	int			toleft;

	toleft = 0;
	len = ft_strlen(s);
	if (g_zero && g_point)
		g_zero = 0;
	if (!g_width)
		g_width = (int)len;
	if (g_sign == -1)
		toleft = 1;
	if (g_width < 0)
	{
		g_width = -g_width;
		toleft = 1;
	}
	if (!neg)
		ft_pr_left_right(s, len, toleft);
	else
		ft_pr_left_right_minus(s, len, toleft, neg);
}

static void		ft_dig_to_str(uintmax_t n, int base)
{
	uintmax_t asign;

	if ((asign = n / base) > 0)
		ft_dig_to_str(asign, base);
	asign = n % base;
	*g_str++ = (asign < 10 ? '0' + asign : g_achar + (asign - 10));
}

void			ft_print_digit(char *pr, uintmax_t n, int base, int neg)
{
	char		s[128];
	char		*pstr;
	size_t		l;

	g_str = s;
	ft_dig_to_str(n, base);
	*g_str = '\0';
	l = (ft_strlen(pr) == 1 ? ft_strlen(s) + ft_strlen(pr) : ft_strlen(s));
	if ((g_prec > (int)l && !g_zero) || (g_prec > (int)l && g_pref))
	{
		g_tmp = ft_strnew(g_prec - l);
		(void)ft_memset((void *)g_tmp, '0', g_prec - l);
		pstr = ft_strjoin(g_tmp, s);
		free(g_tmp);
		g_tmp = pstr;
		g_tmp = ft_strjoin(pr, pstr);
		ft_print_int_str(g_tmp, neg);
	}
	else
	{
		pstr = ft_strjoin(pr, s);
		ft_print_int_str(pstr, neg);
	}
	free(pstr);
}
