/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:36:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/03 12:44:46 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int vol, int dir, int free_str)
{
	char	*new;
	int		i;
	int		start;
	int		end;
	int		len;

	end = 0;
	start = 0;
	i = 0;
	if (dir == 0)
		start += vol;
	else if (dir == 1)
		end += vol;
	len = ft_strlen(str);
	new = ft_memalloc(len - vol + 1);
	while (i + start < len - end)
	{
		new[i] = str[i + start];
		i++;
	}
	new[i] = '\0';
	if (free_str)
		free(str);
	return (new);
}
