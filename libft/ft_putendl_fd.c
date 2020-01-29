/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:33:12 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:22:16 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	ft_putchar_fd('\n', fd);
}
