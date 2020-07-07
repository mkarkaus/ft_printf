/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:47:20 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/07 14:27:37 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.h"
#include "../includes/ft_printf.h"

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

void	identify_conv(t_flag *f, va_list ap)
{
	int		i;

	i = 0;
	while (f->fmt[i + 1] != '\0')
		i++;
	if (f->fmt[i] == 's' || f->fmt[i] == 'c' || f->fmt[i] == 'p' || \
				f->fmt[i] == 'b')
		pointer_conv(f, ap, f->fmt[i]);
	else if (f->fmt[i] == 'd' || f->fmt[i] == 'i' || f->fmt[i] == 'o' || \
				f->fmt[i] == 'u' || f->fmt[i] == 'x' || f->fmt[i] == 'X')
		int_conv(f, ap, f->fmt[i]);
	else if (f->fmt[i] == 'f' || f->fmt[i] == 'g' || f->fmt[i] == 'e')
	{
		f->num = ft_memalloc(8);
		float_conv(f, ap, 0, f->fmt[i]);
		free(f->num);
	}
	apply_width_pres_flags(f, f->fmt[i]);
	if (f->res != NULL)
	{
		f->printed += ft_putstr_fd(f->res, f->fd);
		ft_strclr(f->res);
		free(f->res);
	}
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
		(*format == '%' && *(format + 1) != '%') ? struct_clear(f) : 0;
		if (*format == '%' && *(format + 1) == '%' && (format += 2))
			flag.printed += write(f->fd, "%", 1);
		else if (*format == '%' && *(format + 1) != '%')
			format += (receive_format(format + 1, f, ap) == 0) ? \
				ft_strlen(flag.fmt) + 1 : 1;
		else if (*format == '{')
			(colcheck(f, format)) ? ((format += colcheck(f, format)) != NULL)\
				: (flag.printed += write(f->fd, &(*format++), 1));
		else if (*format != '\0')
			flag.printed += write(f->fd, &(*format++), 1);
	}
	va_end(ap);
	return (flag.printed);
}
