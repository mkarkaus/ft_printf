/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:39:37 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/10 16:08:02 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	struct_clear(t_flag *f)
{
	ft_bzero(f->fmt, 20);
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

int		length_mod(t_flag *f, int i)
{
	if (f->fmt[i] == 'l' && f->fmt[i + 1] != 'l')
		f->l = 1;
	else if (f->fmt[i] == 'l' && f->fmt[i + 1] == 'l')
		f->ll = 1;
	else if (f->fmt[i] == 'h' && f->fmt[i + 1] != 'h')
		f->h = 1;
	else if (f->fmt[i] == 'h' && f->fmt[i + 1] == 'h')
		f->hh = 1;
	else if (f->fmt[i] == 'L' && f->fmt[i + 1] != 'L' && f->fmt[i + 1] != 'l')
		f->cap_l = 1;
	else if (f->fmt[i] == 'L')
		return (-1);
	return (0);
}

void	receive_prec_width(t_flag *f, int *i, va_list ap)
{
	int	val;

	if (f->fmt[*i] == '*' || f->fmt[*i + 1] == '*')
		val = va_arg(ap, int);
	else if (f->fmt[*i] == '.')
		val = ft_atoi(f->fmt + *i + 1);
	else
		val = ft_atoi(f->fmt + *i);
	if (f->fmt[*i] == '*' || ft_isdigit(f->fmt[*i]))
	{
		if (val < 0)
		{
			val *= -1;
			f->minus = 1;
		}
		f->width = val;
	}
	else
		f->pres = (val < 0) ? -1 : val;
	(f->fmt[*i + 1] == '*') ? (*i)++ : 0;
	while (ft_isdigit(f->fmt[*i + 1]) && f->fmt[*i] != '*')
		(*i)++;
}

int		receive_flags(t_flag *f, int i, va_list ap)
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
		else if (f->fmt[i] == '.' || f->fmt[i] == '*' || ft_isdigit(f->fmt[i]))
			receive_prec_width(f, &i, ap);
		i++;
	}
	return (length_mod(f, i));
}
