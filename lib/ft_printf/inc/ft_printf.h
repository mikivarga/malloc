/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:13:05 by mvarga            #+#    #+#             */
/*   Updated: 2017/03/11 18:38:29 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/inc/libft.h"
# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>

# define BYTE_ASCII 0x7F
# define BYTE_UTF2 0x7FF
# define BYTE_UTF3 0xFFFF
# define BYTE_UTF4 0x10FFFF
# define TRUE 1
# define FALSE 0
# define SIZE 31
# define HH 208
# define LL 216

int				g_width;
int				g_prec;
int				g_sign;
int				g_zero;
int				g_pref;
int				g_cnt;
int				g_plus_space;
int				g_convers;
int				g_point;
unsigned char	g_size_type;
char			g_achar;

int			ft_printf(const char *format, ...);
void		ft_print(char c);
void		ft_pr_sp(char c, size_t len);
void		ft_pr(char *str, size_t len);
void		ft_print_digit(char *prefix, uintmax_t n, int base, int neg);
void		ft_pr_point(char *prefix, uintmax_t nbr, int base);
uintmax_t	ft_get_unsigned_from_va_list(unsigned char c, va_list ap);
int64_t		ft_get_signed_from_va_list(unsigned char c, va_list ap);
int			ft_flg_check(char c, int start, int end);
const char	*ft_flg_min_plus_space_zero_prefix(const char *str);
const char	*ft_flg_width(const char *str, va_list ap);
const char	*ft_flg_precision(const char *str, va_list ap);
void		ft_char(unsigned char c, va_list ap);
void		ft_no_conversion(char c);
void		ft_str(unsigned char c, va_list ap);
void		ft_wstr(unsigned char c, va_list ap);
void		ft_str_null(char *str);
void		ft_signed_digit(unsigned char c, va_list ap);
void		ft_unsigned_digit(unsigned char c, va_list ap);
void		ft_o_digit(unsigned char c, va_list ap);
void		ft_big_o_digit(unsigned char c, va_list ap);
void		ft_x_digit(unsigned char c, va_list ap);
void		ft_big_x_digit(unsigned char c, va_list ap);
void		ft_pointer(unsigned char c, va_list ap);
#endif
