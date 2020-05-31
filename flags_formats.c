/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:47:08 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/05/29 18:24:49 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_chars(struct s_flag *f, char chr)
{
	if (f->space && !f->plus && (chr == 'd' || chr == 'i'))
		f->res = ft_strjoin(" ", f->res);
	if (f->plus && (chr == 'd' || chr == 'i' || chr == 'f') && *f->res != '-')
		f->res = ft_strjoin("+", f->res);
	if (f->hash && (chr == 'o' || chr == 'x' || chr == 'X' || chr == 'f'))
		f->res = ft_hash(f, chr);
	if (f->width && f->width > (int)ft_strlen(f->res))
		ft_width(f);
	if (f->zero && !f->minus)
		ft_zero(f);
	if (f->minus)
		f->res = ft_minus(f);
}

void	struct_clear(struct s_flag *f)
{
	ft_strclr(f->fmt);
	f->num = 0;
	f->l = 0;
	f->ll = 0;
	f->h = 0;
	f->hh = 0;
	f->cap_l = 0;
	f->hash = 0;
	f->plus = 0;
	f->minus = 0;
	f->space = 0;
	f->zero = 0;
	f->pres = 6;
	f->width = 0;
}

int		valid_format(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
		c == 'X' || c == 'c' || c == 'p' || c == 'f' || c == 'g' || c == 'e')
		return (1);
	else if (c == 'l' || c == 'h' || c == 'L')
		return (2);
	else if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '.' \
		|| c == '*' || (c >= '0' && c <= '9'))
		return (3);
	return (0);
}

void	length_mod(struct s_flag *f, int i)
{
	if (f->fmt[i] == 'l' && f->fmt[i + 1] != 'l')
		f->l = 1;
	else if (f->fmt[i] == 'l' && f->fmt[i + 1] == 'l')
		f->ll = 1;
	else if (f->fmt[i] == 'h' && f->fmt[i + 1] != 'h')
		f->h = 1;
	else if (f->fmt[i] == 'h' && f->fmt[i + 1] == 'h')
		f->hh = 1;
	else if (f->fmt[i] == 'L')
		f->cap_l = 1;
}

void	flags_fill(struct s_flag *f, int i)
{
	while (valid_format(f->fmt[i]) == 3)
	{
		if (f->fmt[i] == '0' && f->zero == 0)
			f->zero = 1;
		else if (f->fmt[i] == '#')
			f->hash = 1;
		else if (f->fmt[i] == '+')
			f->plus = 1;
		else if (f->fmt[i] == '-')
			f->minus = 1;
		else if (f->fmt[i] == ' ')
			f->space = 1;
		else if (f->fmt[i] == '.' && (f->pres = ft_atoi(f->fmt + i + 1)) != -1)
			while (ft_isdigit(f->fmt[i + 1]))
				i++;
		else if (f->fmt[i] >= '1' && f->fmt[i] <= '9')
		{
			f->width = ft_atoi(f->fmt + i);
			i += ft_intlen(f->width) - 1;
		}
		i++;
	}
	length_mod(f, i);
}
