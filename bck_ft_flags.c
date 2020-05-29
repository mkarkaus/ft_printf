/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:47:14 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/05/28 13:52:25 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_conv(struct s_flag *f, va_list ap, char chr)
{
	f->addr = va_arg(ap, void *);
	ft_flag_type(f, chr);
	if (chr == 'd' || chr == 'i')
	{
		if (f->l == 1 || f->ll == 1)
			f->res = ft_itoa_long(*f->num);
		else
			f->res = ft_itoa(*f->num);
	}
	else
	{
		f->res = ft_memalloc(ft_intlen((long long)f->addr + 2));
		if (chr == 'o')
			uitoabase(f, *f->num, 0, 8);
		if (chr == 'u')
			uitoabase(f, *f->num, 0, 10);
		if (chr == 'x' || chr == 'X')
			uitoabase(f, *f->num, 0, 16 + (chr == 'X'));
		f->res = ft_strrev(f->res);
	}
}

void	ft_float_fraction(struct s_flag *f, long double *nbr, int *i, int j)
{
	while (j <= f->pres && f->res[(*i)] != '-')
	{
		f->res[(*i)++] = (long)(*nbr * 10) + '0';
		*nbr = *nbr * 10 - ((long)(*nbr * 10));
		j++;
	}
	j = *i - 1;
	if (f->res[j] >= '5' && f->res[j] <= '9')
	{
		j--;
		while (f->res[j] == '9' || f->res[j] == '.')
		{
			if (f->res[j] == '9')
				f->res[j] = '0';
			if (j != 0)
				j--;
		}
		if (f->res[j] == '-' && (*i)++ && ++j == 1)
			f->res = ft_strjoin("-0", f->res + 1);
		else if (f->res[j] == '0' && j == 0 && (*i)++)
			f->res = ft_strjoin("0", f->res);
		f->res[j] += 1;
	}
	f->res[*i - 1] = '\0';
}

void	ft_float_integer(struct s_flag *f, long double *nbr, long double tens, int *i)
{
	if ((long)*nbr == 0)
		f->res[(*i)++] = '0';
	while ((long)*nbr != 0)
	{
		f->res[(*i)++] = (long)((*nbr / tens) + '0');
		*nbr -= (long)(*nbr / tens) * tens;
		tens /= 10;
		printf("^^^^str: %s^^^^\n", f->res);
	}
}

void	ft_find_tens(long double nb, long double *tens, int *size)
{
	while ((long)(nb /= 10) != 0 && (*size)++)
		*tens *= 10;
}

void	ft_double_conv(struct s_flag *f, va_list ap, int i) //, char chr)
{
	int			size;
	long double	tens;
	long double	nbr;

	tens = 1;
	size = 1;
	// printf("??? %.50f ???\n", 0.000000000000000000000000000000000000000001);
	if (f->cap_l)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	ft_find_tens(nbr, &tens, &size);
	f->res = (char *)malloc((size + f->pres + 3) * sizeof(char));
	if (nbr < 0 && (nbr *= -1) > 0)
		f->res[i++] = '-';
	ft_float_integer(f, &nbr, tens, &i);
	if (f->pres)
		f->res[i++] = '.';
	ft_float_fraction(f, &nbr, &i, 0);
}

void	ft_csp_conv(struct s_flag *f, va_list ap, char chr)
{
	f->addr = va_arg(ap, void *);
	if (chr == 'c')
		f->printed += write(1, &(f->addr), 1);
	else if (chr == 's')
		f->res = (char *)f->addr;
	else if (chr == 'p')
	{
		f->res = ft_memalloc(13);
		uitoabase(f, (long)f->addr, 0, 16);
		f->res = ft_strrev(f->res);
		f->res = ft_strjoin("0x", f->res);
	}
}
