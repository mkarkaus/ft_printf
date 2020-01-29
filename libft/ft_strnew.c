/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:46:51 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:28:16 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char *)malloc((size + 1) * sizeof(char))))
		return (0);
	new[size] = '\0';
	while (size--)
		new[size] = '\0';
	return (new);
}
