/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:47:08 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/06/30 20:38:36 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_chars(t_flag *f, char chr)
{
	if (f->pres >= 0 && chr != 'f' && chr != 'g' && chr != 'e' && chr != 'p')
		pres_flag(f, chr);
	if (f->space && !f->plus && f->res[0] != '-' && (chr == 'd' || chr == 'i'))
		f->res = ft_strjoin(" ", f->res, 2);
	if (f->plus && (chr == 'd' || chr == 'i' || chr == 'f' || chr == 'e' || \
			chr == 'g') && *f->res != '-')
		f->res = ft_strjoin("+", f->res, 2);
	if (f->hash && (chr == 'o' || chr == 'x' || chr == 'X' || chr == 'f' || \
			chr == 'e' || chr == 'g'))
		f->res = hash_flag(f, chr);
	if (f->width && f->width > (int)ft_strlen(f->res))
		width_flag(f);
	if (f->zero && !f->minus)
		zero_flag(f);
	if (f->minus)
		f->res = minus_flag(f);
}

void	struct_clear(t_flag *f)
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
	f->pres = -1;
	f->width = 0;
	f->exp = 0;
}

int		valid_format(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
		c == 'X' || c == 'c' || c == 'p' || c == 'f' || c == 'g' || c == 'e' ||
		c == 'b')
		return (1);
	else if (c == 'l' || c == 'h' || c == 'L')
		return (2);
	else if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '.' \
		|| c == '*' || c == '$' || (c >= '0' && c <= '9'))
		return (3);
	return (0);
}

void	length_mod(t_flag *f, int i)
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

void	flags_fill(t_flag *f, int i)
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
