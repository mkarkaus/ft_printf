/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:52:41 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/04 18:50:15 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		j = 0;
		i++;
	}
	return (0);
}
