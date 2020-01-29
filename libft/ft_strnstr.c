/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:56:17 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:28:25 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (!len)
		return (0);
	while (haystack[i] && i + j < len)
	{
		while (haystack[i + j] == needle[j] && needle[j] != '\0' && i + j < len)
			j++;
		if (!needle[j] && i + j <= len)
			return ((char *)haystack + i);
		j = 0;
		i++;
	}
	return (0);
}
