/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:40:48 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:19:53 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	if (!(temp = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content == 0)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		if (!(temp->content = malloc(content_size)))
			return (0);
		ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	temp->next = NULL;
	return (temp);
}
