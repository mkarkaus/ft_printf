/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 22:27:15 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/08 11:39:49 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*bin_conv(char *addr, int j, int k)
{
	char	*str;
	char	c;
	int		bin;

	str = ft_memalloc((ft_strlen(addr) + 1) * 8);
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

void	pointer_conv(struct s_flag *f, va_list ap, char chr)
{
	f->addr = va_arg(ap, void *);
	if (f->addr == NULL)
		f->res = f->addr;
	else if (chr == 'c')
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
	if (f->res == NULL && chr == 'p')
		f->res = ft_strdup("(nil)");
}
