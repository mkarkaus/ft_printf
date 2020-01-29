#include "libft/libft.h"

char    *replace_format_with_value(char *fmt)
{

}

void    which_format(char *fmt)
{
    while (*fmt != '%')
        fmt++;

}

int     ft_printf(const char *format, ...)
{
    va_list ap;
    char    *str;
    char    c;
    char    *fmt;
            
    while(*format != '%')
    {
        write(1, *format, 1);
        format++;
    }
    which_format(fmt);
    replace_format_with_value();
    // str = format;
    va_start(ap, format);
    while (format)
    {
        if (ft_strstr(format, "%s"))
            str = va_arg(ap, char *);
        if (ft_strstr(format, "%d"))

        if (ft_strstr(format, "%c"))
        format++;
    }
    va_end(ap);
    return (0);
}

// Idea is that turn format into char *fmt and pass it around functions to fill in 
// the % formats with the values.