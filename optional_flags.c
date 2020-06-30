/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:25:19 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/06/30 20:35:33 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pres_flag(t_flag *f, char chr)
{
	int		i;
	int		minus;

	minus = (f->res[0] == '-');
	if (minus)
		f->res[0] = '0';
	i = f->pres - ft_strlen(f->res);
	if (chr == 's' && ft_strlen(f->res) >= f->pres)
		ft_strclr(f->res + f->pres);
	else if (chr != 's')
	{
		while (i > 0)
		{
			f->res = ft_strjoin("0", f->res, 2);
			i--;
		}
		if (minus)
			f->res = ft_strjoin("-", f->res, 2);
	}
}

char	*double_hash(t_flag *f, char *str)
{
	int		i;
	char	*exp;

	i = 0;
	while (f->res[i] != '.' && f->res[i] != '\0' && f->res[i] != 'e')
	{
		str[i] = f->res[i];
		i++;
	}
	exp = ft_memalloc(ft_strlen(f->res + i) + 2);
	ft_strncpy(exp, f->res + i, ft_strlen(f->res + i));
	if (!f->res[i])
	{
		str[i] = '.';
		str[i + 1] = '\0';
	}
	else if (f->res[i] == 'e' || f->res[i] == '.')
	{
		if (f->res[i] == 'e')
			str[i++] = '.';
		ft_strncpy(str + i, exp, ft_strlen(exp));
	}
	free(exp);
	return (str);
}

char	*hash_flag(t_flag *f, char chr)
{
	char	*str;

	str = (char *)malloc((ft_strlen(f->res) + 3) * sizeof(char));
	if (chr == 'o')
	{
		str[0] = '0';
		ft_strcpy(str + 1, f->res);
	}
	else if ((chr == 'x' || chr == 'X') && ft_strcmp(f->res, "0"))
	{
		if (chr == 'x')
			f->res = ft_strjoin("x", f->res, 2);
		if (chr == 'X')
			f->res = ft_strjoin("X", f->res, 2);
		f->res = ft_strjoin("0", f->res, 2);
	}
	if (chr == 'f' || chr == 'e' || chr == 'g')
		str = double_hash(f, str);
	else
		ft_strcpy(str, f->res);
	free(f->res);
	return (str);
}

void	width_flag(t_flag *f)
{
	char	*spaces;
	int		num;

	num = f->width - ft_strlen(f->res);
	spaces = ft_memalloc(num + 1);
	spaces[num] = '\0';
	num -= 1;
	while (num >= 0)
	{
		spaces[num] = ' ';
		num--;
	}
	f->res = ft_strjoin(spaces, f->res, 3);
}

void	zero_flag(t_flag *f)
{
	int		i;

	i = f->space;
	while (f->res[i] == ' ' || f->res[i] == '-' || f->res[i] == '+')
	{
		if (f->res[i] != ' ')
		{
			f->res[0] = f->res[i];
			if (i != 0)
				f->res[i] = '0';
		}
		else
			f->res[i] = '0';
		i++;
	}
}

char	*minus_flag(t_flag *f)
{
	char	*str;
	int		spaces;
	int		i;

	spaces = 0;
	str = (char *)malloc((ft_strlen(f->res) + 1) * sizeof(char));
	while (f->res[spaces] == ' ')
		spaces++;
	i = ft_strlen(f->res) - spaces + f->space;
	str = ft_strncpy(str, f->res + spaces - f->space, i);
	while (spaces - f->space > 0)
	{
		str[i] = ' ';
		spaces--;
		i++;
	}
	str[i] = '\0';
	free(f->res);
	return (str);
}
