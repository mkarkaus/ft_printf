
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

int     ft_format_check(const char *format, struct s_flag *f)
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
        flags_fill(f, 0);
        printf("l:  %d\n", f->l);    
        printf("ll: %d\n", f->ll);
        printf("h:  %d\n", f->h);
        printf("hh: %d\n", f->hh);
        printf("hash: %d\n", f->hash);
        printf("plus: %d\n", f->plus);
        printf("minus: %d\n", f->minus);
        printf("space: %d\n", f->space);
        printf("zero: %d\n", f->zero);
        printf("pres: %d\n", f->pres);
        printf("width: %d\n", f->width);
        ft_which_format(f);
    }
    else
    {
        f->printed += write(1, "%", 1);
        return (-1);
    }
    return (0);
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
            if (ft_format_check(format + 1, f) == 0)
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
