#include "ft_printf.h"

void    ft_which_format(struct s_flag *f)
{
    int     i;
    i = 0;

    while (f->fmt[i + 1] != '\0')
        i++;
    if (f->fmt[i] == 's' || f->fmt[i] == 'c' || f->fmt[i] == 'p')
        ft_cs_print(f, f->fmt[i]);
    else if (f->fmt[i] == 'd' || f->fmt[i] == 'i' || f->fmt[i] == 'o' || \
                f->fmt[i] == 'u' || f->fmt[i] == 'x' || f->fmt[i] == 'X')
        ft_int_conv(f, f->fmt[i]);
}

void    ft_format_check(const char *format, struct s_flag *f)
{
    int     i;

    i = 0;
    // printf("--%ld--", sizeof(f.addr));
    ft_strclr(f->fmt);
    while (format[i] != 's' && format[i] != 'd' && format[i] != 'i' && \
            format[i] != 'o' && format[i] != 'u' && \
            format[i] != 'x' && format[i] != 'X' && \
            format[i] != 'c' && format[i] != 'p')
    {
        f->fmt[i] = format[i];
        i++;
    }
    f->fmt[i] = format[i];
    f->fmt[i + 1] = '\0';
    ft_which_format(f);
    // printf("--%s--", arg);
}

int     ft_printf(const char *format, ...)
{
    va_list         ap;
    struct s_flag   flag;
    struct s_flag   *f;

    f = &flag;
    flag.printed = 0;
    va_start(ap, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == '%')
            format++;
        else if (*format == '%' && *(format + 1) != '%')
        {
            flag.addr = va_arg(ap, void *);
            ft_format_check(format + 1, f);
            format = format + ft_strlen(flag.fmt) + 1;
        }
        flag.printed += write(1, &(*format), 1);
        format++;
    }
    va_end(ap);
    return (flag.printed);
}

/* 

             flag -d___
            /          \
ft_printf__/___flag -s__(?precision)
            \__flag -i_/
*/