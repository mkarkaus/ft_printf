/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:36:48 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:26:15 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] && i < size)
		i++;
	j = 0;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
