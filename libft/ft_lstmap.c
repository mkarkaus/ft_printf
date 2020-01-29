/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:08:11 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/08 12:18:15 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*templist;

	if (!lst)
		return (0);
	if (!(templist = f(lst)))
		return (NULL);
	new = templist;
	while (lst->next)
	{
		lst = lst->next;
		if (!(templist->next = f(lst)))
		{
			free(templist->next);
			return (0);
		}
		templist = templist->next;
	}
	return (new);
}
