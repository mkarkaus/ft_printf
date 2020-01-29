/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:27:10 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:28:39 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	while (*s != c && len > 0)
	{
		len--;
		s--;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}
