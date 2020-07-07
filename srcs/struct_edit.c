/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:39:37 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/07 13:16:06 by mkarkaus         ###   ########.fr       */
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

void	receive_prec_width(t_flag *f, int *i, va_list ap)
{
	if (f->fmt[*i] == '.' && f->fmt[*i + 1] == '*')
	{
		f->pres = va_arg(ap, int);
		(*i)++;
	}
	else if (f->fmt[*i] == '.' && f->fmt[*i + 1] != '*')
	{
		f->pres = ft_atoi(f->fmt + *i + 1);
		while (ft_isdigit(f->fmt[*i + 1]))
			(*i)++;
	}
	else if (f->fmt[*i] == '*')
		f->width = va_arg(ap, int);
	else if (ft_isdigit(f->fmt[*i]))
	{
		f->width = ft_atoi(f->fmt + *i);
		*i += ft_intlen(f->width) - 1;
	}
}

void	receive_flags(t_flag *f, int i, va_list ap)
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
	length_mod(f, i);
}
