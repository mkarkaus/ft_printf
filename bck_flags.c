/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:47:14 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/06/30 15:11:23 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		int_conv(t_flag *f, va_list ap, char chr)
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
		// printf("!!! %lu !!!", (long unsigned int)f->num);
		if (chr == 'o')
			uitoabase(f, *f->num, 0, 8);
		if (chr == 'u')
			uitoabase(f, *f->num, 0, 10);
		if (chr == 'x' || chr == 'X')
			uitoabase(f, *f->num, 0, 16 + (chr == 'X'));
		f->res = ft_strrev(f->res, 1);
	}
}

void	round_up(t_flag *f, long double *nbr, int *i, int j)
{
	j--;
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

void		float_fraction(t_flag *f, long double *nbr, int *i, int j)
{
	while (j <= f->pres && f->res[(*i)] != '-')
	{
		f->res[(*i)++] = (long)(*nbr * 10) + '0';
		*nbr = *nbr * 10 - ((long)(*nbr * 10));
		j++;
	}
	j = *i - 1;
	if (f->res[j] >= '5' && f->res[j] <= '9')
		round_up(f, nbr, i, j);
	f->res[*i - 1] = '\0';
}

void		float_integer(t_flag *f, long double *nbr, int *i)
{
	long double	tens;
	long double	calc;

	calc = *nbr;
	tens = 1;
	while ((long)(calc /= 10) != 0)
		tens *= 10;
	while ((*f->num)-- > 0)
	{
		f->res[(*i)++] = (long)((*nbr / tens) + '0');
		*nbr -= (long)(*nbr / tens) * tens;
		tens /= 10;
	}
}

void		find_size(t_flag *f, long double nb)
{
	while ((long)(nb /= 10) != 0)
		(*f->num)++;
}	

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

int			other_float_convs(t_flag *f, long double *nbr, char chr)
{
	long double	temp;

	temp = *nbr;
	if (chr == 'g' && f->pres == 0)
		f->pres = 1;
	while (temp >= 10 || temp < 1)
	{
		if (temp >= 10 && ++f->exp)
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
	temp = (char *)malloc(6);
	while (str[i] && str[i] != 'e')
		i++;
	temp = ft_strcpy(temp, str + i);
	i -= 1;
	while (str[i] == '0')
		i--;
	if (str[i] != '.')
		i++;
	ft_bzero(str + i, ft_strlen(str + i));
	str = ft_strjoin(str, temp, 3);
	return (str);
}

void		g_adjust_pres(t_flag *f, long double nbr, int k)
{
	int		m;

	if (f->pres == ft_intlen_long(nbr) && (long)nbr != 0)
		f->pres = 0;
	else if (ft_intlen_long(nbr) < f->pres || (long)nbr == 0)
	{
		if ((long)nbr != 0 && (f->pres -= ft_intlen_long(nbr)))
			nbr -= (long)nbr;
		else
			while ((long)nbr == 0 && ++k)
				nbr *= 10;
		m = f->pres;
		while (m != 0 && m--)
			nbr *= 10;
		if ((long)nbr == 0)
			f->pres = 0;
		else
			f->pres += k;
	}
}

void		float_conv(t_flag *f, va_list ap, int i, char chr)
{
	long double	nbr;
	int			g_exc;

	g_exc = 0;
	*f->num = 1;
	if (f->cap_l)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	f->res = (char *)malloc((*f->num + f->pres + 3) * sizeof(char));
	if (nbr < 0 && (nbr *= -1) > 0)
		f->res[i++] = '-';
	if (chr != 'f')
		g_exc = other_float_convs(f, &nbr, chr);
	find_size(f, nbr);
	if (!g_exc && chr == 'g')
		g_adjust_pres(f, nbr, 0);
	float_integer(f, &nbr, &i);
	if (f->pres)
		f->res[i++] = '.';
	float_fraction(f, &nbr, &i, 0);
	if (g_exc)
		insert_exp(f);
	(chr == 'g' && !f->hash) ? f->res = rm_trailing_zeros(f->res) : 0;
}

char		*bin_conv(char *addr, int j, int k)
{
	char	*str;
	char	c;
	int		bin;

    str = (char *)malloc((ft_strlen(addr) + 1) * 8);
    while (addr[j])
    {
        bin = 128;
        if (j % 8 == 0 && j != 0)
            str[k++] = '\n';
		c = addr[j];
        while (bin != 0)
        {
            if (c >= bin && (c -= bin))
                str[k++] = '1';
            else
                str[k++] = '0';
            bin /= 2;
        }
        j++;
        str[k++] = ' ';
    }
    str[k] = '\0';
	return (str);
}

void		cspb_conv(struct s_flag *f, va_list ap, char chr)
{
	f->addr = va_arg(ap, void *);
	if (chr == 'c')
	{
		f->res = ft_memalloc(2);
		f->res = ft_memset(f->res, *((char *)&f->addr), 1);
		f->res[1] = '\0';
	}
	else if (chr == 's')
		f->res = ft_strdup((char *)f->addr);
	else if (chr == 'p')
	{
		f->res = ft_memalloc(13);
		uitoabase(f, (long)f->addr, 0, 16);
		f->res = ft_strrev(f->res, 1);
		f->res = ft_strjoin("0x", f->res, 2);
	}
	else if (chr == 'b')
		f->res = bin_conv(f->addr, 0, 0);
}
