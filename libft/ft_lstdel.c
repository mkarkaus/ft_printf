/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:57:45 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:19:11 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxtlink;

	while (*alst)
	{
		nxtlink = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = nxtlink;
	}
	*alst = NULL;
}
