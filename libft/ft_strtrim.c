/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:24:44 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:29:09 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	end(char const *s, int i)
{
	int		j;

	j = i;
	while (s[j] && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j++;
	if (s[j])
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	char	*cpy;
	char	*fin;

	k = 0;
	i = 0;
	if (!s || !(cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (0);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (end(s, i) == 1)
	{
		cpy[k] = s[i];
		k++;
		i++;
	}
	cpy[k] = '\0';
	if (!(fin = (char *)malloc((ft_strlen(cpy) + 1) * sizeof(char))))
		return (0);
	fin = cpy;
	return (fin);
}
