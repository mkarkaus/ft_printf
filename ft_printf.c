#include "ft_printf.h"

struct s_flag   ft_format_check(const char *format, struct s_flag f)
{
    int     i;

    i = 0;
    ft_strclr(f.fmt);
    while (format[i] != 's' && format[i] != 'd' && format[i] != 'i' && \
            format[i] != 'o' && format[i] != 'u' && \
            format[i] != 'x' && format[i] != 'X' && \
            format[i] != 'c')
    {
        f.fmt[i] = format[i];
        i++;
    }
    f.fmt[i] = format[i];
    f.fmt[i + 1] = '\0';
    printf("%s", "func");
    return (f);
}

int             ft_printf(const char *format, ...)
{
    va_list         ap;
    struct s_flag   f;

    va_start(ap, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == '%')
            format++;
        else if (*format == '%' && *(format + 1) != '%')
        {
            f.addr = va_arg(ap, void *);
            f = ft_format_check(format + 1, f);
            format = format + ft_strlen(f.fmt) + 1;
        }
        write(1, &(*format), 1);
        format++;
    }
    va_end(ap);
    // printf("%s", f.fmt);
    return (0);
}

/* 

             flag -d___
            /          \
ft_printf__/___flag -s__(?precision)
            \__flag -i_/
*/