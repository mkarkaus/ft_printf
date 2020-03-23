#include "ft_printf.h"

void    struct_clear(struct s_flag *f)
{
    ft_strclr(f->fmt);
    f->l = 0;
    f->ll = 0;
    f->h = 0;
    f->hh = 0;
    f->plus = 0;
    f->minus = 0;
    f->space = 0;
    f->zero = 0;
}

int     valid_format(char c)
{
    if (c == 's' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' \
        || c == 'X' || c == 'c' || c == 'p' || c == 'f')
        return (1);
    else if (c == 'l' || c == 'h' || c == '.' || c == '*' || c == '#' \
        || c == '-' || c == '+' || c == ' ' || (c >= '0' && c <= '9'))
        return (2);
    return (0);
}

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
        ft_which_format(f);
    }
    else
        write(1, "%", 1);
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
            format += ft_strlen(flag.fmt) + 1;
        }
        flag.printed += write(1, &(*format), 1);
        format++;
    }
    va_end(ap);
    return (flag.printed);
}
