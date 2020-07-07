/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:25:19 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/07 15:12:30 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

	str = ft_memalloc((ft_strlen(f->res) + 3));
	if (chr == 'o')
	{
		if (f->res[0] != '0')
		{
			str[0] = '0';
			ft_strcpy(str + 1, f->res);
		}
		else
			ft_strcpy(str, f->res);
	}
	else if ((chr == 'x' || chr == 'X') && ft_strcmp(f->res, "0"))
	{
		if (chr == 'x')
			f->res = ft_strjoin("x", f->res, 2);
		if (chr == 'X')
			f->res = ft_strjoin("X", f->res, 2);
		f->res = ft_strjoin("0", f->res, 2);
		ft_strcpy(str, f->res);
	}
	if (chr == 'f' || chr == 'e' || chr == 'g')
		double_hash(f, str);
	free(f->res);
	return (str);
}

void	zero_flag(t_flag *f)
{
	int		i;

	i = f->space;
	while (f->res[i])
	{
		if ((f->res[i] == '+' || f->res[i] == '-') && i != 0 && \
			f->res[i - 1] != 'e')
		{
			f->res[0] = f->res[i];
			f->res[i] = '0';
		}
		else if (f->res[i] == ' ')
			f->res[i] = '0';
		i++;
	}
}

void	minus_flag(t_flag *f)
{
	char	*temp;
	int		spaces;
	int		i;

	spaces = 0;
	while (f->res[spaces] == ' ')
		spaces++;
	temp = ft_memalloc(ft_strlen(f->res) + 1 - (spaces - f->space));
	i = ft_strlen(f->res) - (spaces - f->space);
	ft_strcpy(temp, (f->res + (spaces - f->space)));
	ft_strcpy(f->res, temp);
	while ((spaces - f->space) > 0)
	{
		f->res[i] = ' ';
		spaces--;
		i++;
	}
	free(temp);
	f->res[i] = '\0';
}

void	apply_width_pres_flags(t_flag *f, char chr)
{
	if (f->pres != -1 && (chr == 'd' || chr == 'i' || chr == 'o' || chr == 'u'\
		 || chr == 'x' || chr == 'X'))
		f->zero = 0;
	if ((f->pres >= 6 || f->pres == -1) && f->res == NULL)
		f->res = ft_strdup("(null)");
	if (f->pres >= 0 && chr != 'f' && chr != 'g' && chr != 'e' \
			&& f->res != NULL)
		apply_prec(f, chr);
	if (f->space && !f->plus && f->res[0] != '-')
		f->res = ft_strjoin(" ", f->res, 2);
	if (f->plus && (chr == 'd' || chr == 'i' || chr == 'f' || chr == 'e' || \
			chr == 'g') && *f->res != '-')
		f->res = ft_strjoin("+", f->res, 2);
	if (f->hash && (chr == 'o' || chr == 'x' || chr == 'X' || chr == 'f' || \
			chr == 'e' || chr == 'g'))
		f->res = hash_flag(f, chr);
	if (f->width && f->width > (int)ft_strlen(f->res))
		apply_width(f, ((f->hash == 1 && f->zero == 1) && \
			(chr == 'x' || chr == 'X')));
	if (f->zero && !f->minus && (chr != 's' && chr != 'c' && chr != 'p' && \
		chr != 'b'))
		zero_flag(f);
	if (f->minus)
		minus_flag(f);
}
