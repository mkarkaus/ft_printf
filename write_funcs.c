/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:46:42 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/04/28 11:05:59 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_shift_memcpy(struct s_flag *f, int bytes, int negative, char chr)
{
	char	*str;
	int		i;
	int		j;

	i = bytes;
	j = (bytes - 1) * 8;
	str = (char *)malloc(bytes);
	while (0 < i)
	{
		str[i - 1] = ((long)f->addr >> j) & 0xFF;
		i--;
		j -= 8;
	}
	print_memory(str, 16);
	while (0 < bytes && negative == 1 && (chr == 'd' || chr == 'i'))
	{
		str[bytes - 1] = ~(str[bytes - 1]);
		bytes--;
	}
	f->num = (void *)str;
	if (negative == 1 && (chr == 'd' || chr == 'i'))
		*f->num = (*f->num + 1) * -1;
	print_memory(str, 16);
}

void	ft_flag_type(struct s_flag *f, char chr)
{
	int		int_negative;
	short	short_negative;
	char	char_negative;

	int_negative = (long)f->addr | (0 << ((sizeof(int) * 8) - 1));
	short_negative = (long)f->addr | (0 << ((sizeof(short) * 8) - 1));
	char_negative = (long)f->addr | (0 << ((sizeof(char) * 8) - 1));
	if (f->l)
		ft_shift_memcpy(f, sizeof(long), (long)f->addr < 0, chr);
	else if (f->ll || f->cap_l)
		ft_shift_memcpy(f, 16, (long long)f->addr < 0, chr);
	else if (f->h)
		ft_shift_memcpy(f, sizeof(short), short_negative < 0, chr);
	else if (f->hh)
		ft_shift_memcpy(f, sizeof(char), char_negative < 0, chr);
	else
		ft_shift_memcpy(f, sizeof(int), int_negative < 0, chr);
}

void	uitoabase(struct s_flag *f, uintmax_t num, int i, unsigned int base)
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
