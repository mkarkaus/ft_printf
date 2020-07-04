/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:45:07 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/03 12:45:58 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str, int free_str)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	i = ft_strlen(str) - 1;
	if (!(res = (char *)malloc((i + 2) * sizeof(char))))
		return (0);
	while (i >= 0)
	{
		res[j] = str[i];
		i--;
		j++;
	}
	res[j] = '\0';
	if (free_str)
		free(str);
	return (res);
}
