/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:27:14 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/07 11:55:54 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int free_int)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	i = 0;
	if (!s1)
		return (0);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	while (s1 != NULL && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	if (free_int == 1 || free_int == 3)
		free((char *)s1);
	if (free_int == 2 || free_int == 3)
		free((char *)s2);
	return (res);
}
