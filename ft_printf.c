/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:47:20 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/04/28 13:40:58 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_which_format(struct s_flag *f, va_list ap)
{
	int		i;

	i = 0;
	while (f->fmt[i + 1] != '\0')
		i++;
	if (f->fmt[i] == 's' || f->fmt[i] == 'c' || f->fmt[i] == 'p')
		ft_csp_conv(f, ap, f->fmt[i]);
	else if (f->fmt[i] == 'd' || f->fmt[i] == 'i' || f->fmt[i] == 'o' || \
				f->fmt[i] == 'u' || f->fmt[i] == 'x' || f->fmt[i] == 'X')
		ft_int_conv(f, ap, f->fmt[i]);
	else if (f->fmt[i] == 'f' || f->fmt[i] == 'g' || f->fmt[i] == 'e')
		ft_double_conv(f, ap, f->fmt[i]);
	ft_flags_chars(f, f->fmt[i]);
	f->printed += ft_putstr(f->res);
}

int		ft_format_check(const char *format, struct s_flag *f, va_list ap)
{
	int		i;

	i = 0;
	struct_clear(f);
	while (valid_format(format[i]) && valid_format(format[i]) != 1)
	{
		f->fmt[i] = format[i];
		i++;
	}
	if (valid_format(format[i]))
	{
		f->fmt[i] = format[i];
		f->fmt[i + 1] = '\0';
		flags_fill(f, 0);
		ft_which_format(f, ap);
	}
	else
	{
		f->printed += write(1, "%", 1);
		return (-1);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	struct s_flag	flag;
	struct s_flag	*f;

	f = &flag;
	flag.printed = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
			format++;
		else if (*format == '%' && *(format + 1) != '%')
		{
			// double value;
			// flag.addr = va_arg(ap, void *);

			// printf("--%lf--\n", value);
			if (ft_format_check(format + 1, f, ap) == 0)
				format += ft_strlen(flag.fmt) + 1;
			else
				format += 2;
		}
		flag.printed += write(1, &(*format), 1);
		format++;
	}
	va_end(ap);
	return (flag.printed);
}
