/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:27:14 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/15 13:07:50 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*res;

	i = 0;
	if (!s1)
		return (0);
	res = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(res));
	if (!res)
		return (0);
	while (*s1)
	{
		res[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		res[i] = *s2;
		i++;
		s2++;
	}
	res[i] = '\0';
	return (res);
}
