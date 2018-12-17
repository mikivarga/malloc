/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:05:13 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/03 14:24:13 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_tmp;
	t_list		*new_list;
	t_list		*tmp;

	new_list = (t_list *)malloc(sizeof(t_list));
	new_tmp = new_list;
	while (lst)
	{
		tmp = f(lst);
		new_tmp->content = tmp->content;
		new_tmp->content_size = tmp->content_size;
		if (lst->next == NULL)
			break ;
		new_tmp->next = (t_list *)malloc(sizeof(t_list));
		new_tmp = new_tmp->next;
		new_tmp->next = NULL;
		lst = lst->next;
	}
	return (new_list);
}
