/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:47:20 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/06/30 16:20:09 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "ft_printf.h"

int		colcheck(t_flag *f, const char *format)
{
	int		i;

	i = 0;
	while (g_cname[i] && ft_strncmp(g_cname[i], format, ft_strlen(g_cname[i])))
		i++;
	if (g_cname[i])
	{
		ft_putstr_fd(g_ccode[i], f->fd);
		return (ft_strlen(g_cname[i]));
	}
	return (0);
}

void	which_conv(t_flag *f, va_list ap)
{
	int		i;

	i = 0;
	while (f->fmt[i + 1] != '\0')
		i++;
	if (f->fmt[i] == 's' || f->fmt[i] == 'c' || f->fmt[i] == 'p' || \
				f->fmt[i] == 'b')
		cspb_conv(f, ap, f->fmt[i]);
	else if (f->fmt[i] == 'd' || f->fmt[i] == 'i' || f->fmt[i] == 'o' || \
				f->fmt[i] == 'u' || f->fmt[i] == 'x' || f->fmt[i] == 'X')
		int_conv(f, ap, f->fmt[i]);
	else if (f->fmt[i] == 'f' || f->fmt[i] == 'g' || f->fmt[i] == 'e')
	{
		f->num = ft_memalloc(8);
		float_conv(f, ap, 0, f->fmt[i]);
		free(f->num);
	}
	ft_flags_chars(f, f->fmt[i]);
	f->printed += ft_putstr_fd(f->res, f->fd);
	ft_strclr(f->res);
	free(f->res);
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
		flags_fill(f, 0);
		which_conv(f, ap);
	}
	else
	{
		f->printed += write(f->fd, "%", 1);
		return (-1);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	flag;
	t_flag	*f;

	f = &flag;
	flag.printed = 0;
	va_start(ap, format);
	f->fd = (!ft_strncmp(format, "{fd}", 4)) ? va_arg(ap, int) : 1;
	format += (!ft_strncmp(format, "{fd}", 4)) ? 4 : 0;
	while (*format)
	{
		(*format == '%' && *(format + 1) != '%') ? struct_clear(f) : 0 ;
		if (*format == '%' && *(format + 1) == '%')
			format++;
		else if (*format == '%' && *(format + 1) != '%')
			format += (receive_format(format + 1, f, ap) == 0) \
				? ft_strlen(flag.fmt) + 1 : 2;
		else if (*format == '{')
			(colcheck(f, format)) ? ((format += colcheck(f, format)) != NULL)\
				: (flag.printed += write(f->fd, &(*format++), 1));
		else
			*format != '\0' ? flag.printed += write(f->fd, &(*format++), 1) :0;
	}
	va_end(ap);
	return (flag.printed);
}
