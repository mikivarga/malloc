/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:35:23 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 16:51:10 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char		*g_str;
static char		*g_tmp;

static void		ft_pr_left_right(char *pref, char *str, size_t len, int toleft)
{
	if (g_width > (int)len)
	{
		if (toleft)
		{
			ft_pr(str, len);
			ft_pr_sp(' ', g_width - (int)(len + ft_strlen(pref)));
		}
		else
		{
			ft_pr_sp(g_zero ? '0' : ' ', g_width - (int)len);
			ft_pr(str, len - ft_strlen(pref));
		}
	}
	else
		ft_pr(str, len - ft_strlen(pref));
}

static void		ft_lr_pref(char *pref, char *str, size_t len, int toleft)
{
	if ((g_width + (int)ft_strlen(pref)) > (int)len)
	{
		if (toleft)
		{
			ft_pr(pref, ft_strlen(pref));
			ft_pr_left_right(pref, str, len - ft_strlen(pref), toleft);
		}
		else
		{
			if (!g_zero)
			{
				ft_pr_sp(' ', g_width - (int)len);
				ft_pr(pref, ft_strlen(pref));
				ft_pr(str, ft_strlen(str));
			}
			else
			{
				ft_pr(pref, ft_strlen(pref));
				ft_pr_left_right(pref, str, len, toleft);
			}
		}
		return ;
	}
	ft_pr(pref, ft_strlen(pref));
	ft_pr(str, ft_strlen(str));
}

static void		ft_dig_to_str(uintmax_t n, int base)
{
	uintmax_t	asign;

	if ((asign = n / base) > 0)
		ft_dig_to_str(asign, base);
	asign = n % base;
	*g_str++ = (asign < 10 ? '0' + asign : g_achar + (asign - 10));
}

static int		ft_prec_more_len(char *pref, char *str, size_t len, int toleft)
{
	char		*pstr;

	if ((g_pref || g_sign || g_point || g_plus_space) && !*str)
		g_zero = 0;
	if (g_prec > (int)len)
	{
		if (g_width > g_prec)
			g_width -= ft_strlen(pref);
		g_tmp = ft_strnew(g_prec - (int)len + ft_strlen(pref));
		ft_memset((void *)g_tmp, '0', g_prec - (int)len + ft_strlen(pref));
		pstr = ft_strjoin(g_tmp, str);
		free(g_tmp);
		len = ft_strlen(pstr);
		if (*pref == '\0')
			ft_pr_left_right(pref, pstr, len, toleft);
		else
			ft_lr_pref(pref, pstr, len, toleft);
		free(pstr);
		return (TRUE);
	}
	return (FALSE);
}

void			ft_pr_point(char *prefix, uintmax_t nbr, int base)
{
	char		str[128];
	size_t		len;
	int			toleft;

	toleft = 0;
	g_str = str;
	ft_dig_to_str(nbr, base);
	*g_str = '\0';
	len = ft_strlen(str) + ft_strlen(prefix);
	if (g_width < 0)
	{
		g_width = -g_width;
		toleft = 1;
	}
	if (g_width == 0 || (g_width < (int)len && g_prec <= 0 && g_width))
		g_width = len;
	if (g_width < g_prec)
		g_width = g_prec;
	if (ft_prec_more_len(prefix, str, len, toleft))
		return ;
	if (*prefix == '\0')
		ft_pr_left_right(prefix, str, len, toleft);
	else
		ft_lr_pref(prefix, str, len, toleft);
}
