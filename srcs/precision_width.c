/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 22:03:28 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/07 15:17:40 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_width(t_flag *f, int edge_case)
{
	char	*spaces;
	char	prefix[2];
	int		num;

	num = f->width - ft_strlen(f->res);
	spaces = ft_memalloc(num + 1);
	spaces[num] = '\0';
	if (f->res != NULL)
		ft_strncpy(prefix, f->res, 2);
	num -= 1;
	if (edge_case)
		f->res = ft_strcut(f->res, 2, 0, 1);
	while (num >= 0)
	{
		spaces[num] = ' ';
		num--;
	}
	f->res = ft_strjoin(spaces, f->res, 3);
	if (edge_case)
		f->res = ft_strjoin(prefix, f->res, 2);
}

void	apply_prec(t_flag *f, char chr)
{
	int		i;
	int		minus;

	if (f->res[0] == '0' && ft_strlen(f->res) == 1)
		ft_bzero(f->res, 1);
	minus = (f->res[0] == '-');
	if (minus)
		f->res[0] = '0';
	i = f->pres - ft_strlen(f->res) + minus;
	if (chr == 's' && (int)ft_strlen(f->res) >= f->pres)
		ft_strclr(f->res + f->pres);
	else if (chr != 's')
	{
		while (i > 0)
		{
			f->res = ft_strjoin("0", f->res, 2);
			i--;
		}
		if (minus)
			f->res[0] = '-';
	}
}
