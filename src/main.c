/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:25:01 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/09 15:04:52 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alloc_in_heap.h"

void	ft_putaddr(unsigned long long ptr)
{
	const char	hex[16] = "0123456789abcdef";
	char	s[16];
	int	i;

	i = 0;
	if (ptr == 0)
		s[i++] = '0';
	while (ptr != 0)
	{
		s[i++] = hex[ptr % 16];
		ptr /= 16;
	}
	write(1, "0x", 2);
	while (i--)
		ft_putchar(s[i]);
}

int				main(void)
{
	char *str1, *str2;
	write(1,"My mallock1\n", 10);
	if (!(str1 = (char *)ft_malloc(100))){ 
		return 1;
		}
	ft_printf("add = ");
	ft_putaddr((unsigned long long)str1);
	ft_printf("\n");
	write(1,"My mallock2\n", 10);
	if (!(str2 = (char *)ft_malloc(100)))
	{ 
		return 1;
	}
	ft_printf("add = ");
	ft_putaddr((unsigned long long)str2);
	ft_printf("\n");
	return (0);
}
//gcc src/main.c -I includes/malloc.h libft_malloc.so
