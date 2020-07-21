/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 22:07:07 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/21 17:31:16 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	round_up(t_flag *f, int *i, int j)
{
	while (f->res[j] == '9' || f->res[j] == '.')
	{
		if (f->res[j] == '9')
		{
			if (f->res[j - 1] == '-' || j == 0)
			{
				f->res = (j == 0) ? ft_strjoin("0", f->res, 2) : f->res;
				if (f->res[j - 1] == '-')
				{
					f->res[j - 1] = '0';
					f->res = ft_strjoin("-", f->res, 2);
				}
				(*i)++;
				j++;
			}
			f->res[j] = '0';
		}
		if (j != 0)
			j--;
	}
	f->res[j] += 1;
}

void	float_fraction(t_flag *f, long double *nbr, int *i)
{
	int			j;
	int			k;
	__int128_t	temp;
	__int128_t	chunk;

	k = 0;
	j = 0;
	chunk = 1;
	while (j++ <= f->pres && f->res[(*i)] != '-')
	{
		if (chunk == 1)
		{
			while (k++ < 2)
				chunk *= 1000000000000000000;
			temp = *nbr * chunk;
			*nbr = (*nbr * chunk) - temp;
		}
		chunk /= 10;
		f->res[(*i)++] = (temp / chunk) + '0';
		temp -= (temp / chunk) * chunk;
	}
	j = *i - 1;
	if (f->res[j] >= '5' && f->res[j] <= '9')
		round_up(f, i, j - 1);
	f->res[*i - 1] = '\0';
}

void	float_integer(t_flag *f, long double *nbr, int *i)
{
	__int128_t	num;
	__int128_t	tens;
	__int128_t	calc;

	num = *nbr;
	calc = *nbr;
	tens = 1;
	*nbr -= num;
	while ((calc /= 10) != 0)
		tens *= 10;
	while ((*f->num)-- > 0)
	{
		f->res[(*i)++] = (num / tens) + '0';
		num -= (num / tens) * tens;
		tens /= 10;
	}
	if (f->pres)
		f->res[(*i)++] = '.';
	float_fraction(f, nbr, i);
}

void	find_size(t_flag *f, long double nb)
{
	while ((long)(nb /= 10) != 0)
		(*f->num)++;
}

void	float_conv(t_flag *f, va_list ap, int i, char chr)
{
	long double	nbr;
	int			g_exc;

	g_exc = 0;
	*f->num = 1;
	(f->pres == -1) ? f->pres = 6 : 0;
	if (f->cap_l)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	f->res = ft_memalloc(ft_intlen((long)nbr) + f->pres + 3);
	if (nbr < 0 && (nbr *= -1) > 0)
		f->res[i++] = '-';
	if (chr != 'f')
		g_exc = other_float_types(f, &nbr, chr);
	find_size(f, nbr);
	if (!g_exc && chr == 'g')
		g_adjust_pres(f, nbr, 0);
	float_integer(f, &nbr, &i);
	if (g_exc)
		insert_exp(f);
	(chr == 'g' && !f->hash) ? f->res = rm_trailing_zeros(f->res) : 0;
}
