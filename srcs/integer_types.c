/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:51:20 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/06 12:17:16 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	uitoabase(t_flag *f, unsigned long long num, int i, unsigned int base)
{
	char	hex[17];
	char	hex_u[17];
	int		upper;

	ft_strcpy(hex, "0123456789abcdef");
	ft_strcpy(hex_u, "0123456789ABCDEF");
	if (base == 17)
		upper = 1;
	else
		upper = 0;
	if (num > base - upper - 1)
		uitoabase(f, num / (base - upper), i + 1, base);
	if (base >= 16)
	{
		if (base == 16)
			f->res[i] = hex[num % 16];
		else
			f->res[i] = hex_u[num % 16];
	}
	else
		f->res[i] = '0' + (num % base);
}

void	shift_memcpy(t_flag *f, int bytes, int negative, char chr)
{
	char	*str;
	int		i;
	int		j;

	i = bytes;
	j = (bytes - 1) * 8;
	str = ft_memalloc(bytes + 4);
	while (0 < i)
	{
		str[i - 1] = ((long)f->addr >> j) & 0xFF;
		i--;
		j -= 8;
	}
	while (0 < bytes && negative == 1 && (chr == 'd' || chr == 'i'))
	{
		str[bytes - 1] = ~(str[bytes - 1]);
		bytes--;
	}
	f->num = (void *)str;
	if (negative == 1 && (chr == 'd' || chr == 'i'))
		*f->num = (*f->num + 1) * -1;
}

void	apply_length_mod(t_flag *f, char chr)
{
	int		int_negative;
	short	short_negative;
	char	char_negative;

	int_negative = (long)f->addr | (0 << ((sizeof(int) * 8) - 1));
	short_negative = (long)f->addr | (0 << ((sizeof(short) * 8) - 1));
	char_negative = (long)f->addr | (0 << ((sizeof(char) * 8) - 1));
	if (f->l)
		shift_memcpy(f, sizeof(long), (long)f->addr < 0, chr);
	else if (f->ll)
		shift_memcpy(f, sizeof(long long), (long long)f->addr < 0, chr);
	else if (f->h)
		shift_memcpy(f, sizeof(short), short_negative < 0, chr);
	else if (f->hh)
		shift_memcpy(f, sizeof(char), char_negative < 0, chr);
	else
		shift_memcpy(f, sizeof(int), int_negative < 0, chr);
}

void	int_conv(t_flag *f, va_list ap, char chr)
{
	f->addr = va_arg(ap, void *);
	if (chr == 'd' || chr == 'i')
	{
		apply_length_mod(f, chr);
		if (f->l == 1 || f->ll == 1)
			f->res = ft_itoa_llong(*f->num);
		else
			f->res = ft_itoa(*f->num);
		free(f->num);
	}
	else
	{
		f->res = ft_memalloc(ft_intlen((unsigned long)f->addr) + 1);
		if (chr == 'o')
			uitoabase(f, (unsigned long)f->addr, 0, 8);
		if (chr == 'u')
			uitoabase(f, (unsigned long)f->addr, 0, 10);
		if (chr == 'x' || chr == 'X')
			uitoabase(f, (unsigned long)f->addr, 0, 16 + (chr == 'X'));
		f->res = ft_strrev(f->res, 1);
	}
}
