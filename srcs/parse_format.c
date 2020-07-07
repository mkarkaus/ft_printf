/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:07:58 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/07 13:17:32 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int		receive_format(const char *format, t_flag *f, va_list ap)
{
	int		i;

	i = 0;
	while (valid_format(format[i]) && valid_format(format[i]) != 1)
	{
		f->fmt[i] = format[i];
		i++;
	}
	if (valid_format(format[i]))
	{
		f->fmt[i] = format[i];
		f->fmt[i + 1] = '\0';
		receive_flags(f, 0, ap);
		identify_conv(f, ap);
	}
	else if (format[i] == '%')
	{
		f->printed += write(f->fd, "%", 1);
		return (-1);
	}
	return (0);
}
