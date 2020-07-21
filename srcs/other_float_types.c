/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_float_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 22:24:06 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/21 17:35:09 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		insert_exp(t_flag *f)
{
	char	*exp_str;
	int		k;

	k = 0;
	exp_str = ft_memalloc(6);
	exp_str[k++] = 'e';
	if (f->exp < 0)
	{
		exp_str[k++] = '-';
		f->exp *= -1;
	}
	else
		exp_str[k++] = '+';
	if (f->exp >= 0 && f->exp <= 9)
		exp_str[k++] = '0';
	k += ft_intlen(f->exp);
	exp_str = ft_strjoin(exp_str, ft_itoa(f->exp), 3);
	exp_str[k] = '\0';
	f->res = ft_strjoin(f->res, exp_str, 3);
}

int			round_up_case(t_flag *f, long double nbr, int chr_g)
{
	int		i;

	i = 0;
	if (nbr < 1)
		nbr *= 10;
	while (i != f->pres + 1 - chr_g && (long)nbr == 9)
	{
		nbr -= (long)nbr;
		nbr *= 10;
		i++;
	}
	if ((long)nbr >= 5 && i == f->pres + 1 - chr_g)
		return (1);
	return (0);
}

int			other_float_types(t_flag *f, long double *nbr, char chr)
{
	long double	temp;
	int			exit_int;

	exit_int = 0;
	temp = *nbr;
	if (chr == 'g' && f->pres == 0)
		f->pres = 1;
	while ((temp >= 9.5 || temp < 1) && temp && !exit_int)
	{
		if ((temp < 10 && temp >= 9.5 && !round_up_case(f, temp, chr == 'g'))\
			|| (temp < 1 && temp >= 0.9 && round_up_case(f, temp, chr == 'g')))
			exit_int = 1;
		else if (temp >= 9.5 && ++f->exp)
			temp /= 10;
		else if (temp < 1 && --f->exp)
			temp *= 10;
	}
	if (chr == 'e' || (chr == 'g' && (f->exp < -4 || f->exp >= f->pres)))
	{
		*nbr = temp;
		if (f->pres != 0 && chr == 'g')
			f->pres -= 1;
		return (1);
	}
	return (0);
}

char		*rm_trailing_zeros(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_memalloc(6);
	while (str[i] && str[i] != 'e')
		i++;
	temp = ft_strcpy(temp, str + i);
	i -= 1;
	while (str[i] == '0' && ft_strchr(str, '.'))
		i--;
	if (str[i] != '.')
		i++;
	ft_bzero(str + i, ft_strlen(str + i));
	if (temp[0] == 'e')
		str = ft_strjoin(str, temp, 3);
	return (str);
}

void		g_adjust_pres(t_flag *f, long double nbr, int k)
{
	int		m;

	if (nbr == 0)
		f->pres -= 1;
	else if (f->pres == ft_intlen_llong(nbr) && (long)nbr != 0)
		f->pres = 0;
	else if (ft_intlen_llong(nbr) < f->pres || (long)nbr == 0)
	{
		if ((long)nbr != 0 && (f->pres -= ft_intlen_llong(nbr)))
			nbr -= (long)nbr;
		else
		{
			while ((long)nbr == 0 && ++k)
				nbr *= 10;
			k--;
		}
		m = f->pres + 1;
		while (m--)
			nbr *= 10;
		if ((long)nbr == 0)
			f->pres = 0;
		else
			f->pres += k;
	}
}
