/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:25:01 by mvarga            #+#    #+#             */
/*   Updated: 2019/02/02 18:00:08 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alloc_in_heap.h"

int				main(void)
{
	write(1,"My mallock\n", 11);
	if (!ft_malloc(0))
	{ 
		return 1;
	}
	write(1,"My mallock\n", 11);
	if (!ft_malloc(100))
	{ 
		return 1;
	}
	return (0);
}
//gcc srcs/main.c -I includes/malloc.h libft_malloc.so
