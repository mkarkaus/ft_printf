/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:19:40 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/15 16:54:49 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*fre;

	i = 0;
	if (!s)
		return (0);
	if (!(fre = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	while (s[start] && i < len)
	{
		fre[i] = s[start];
		start++;
		i++;
	}
	fre[i] = '\0';
	return (fre);
}
