#include "libft/libft.h"
#include "ft_printf.h"

// char    *replace_format_with_value(char *fmt)
// {

// }

// void    which_format(char *fmt)
// {
//     while (*fmt != '%')
//         fmt++;

// }


int     ft_printf(const char *format, ...)
{
    va_list ap;
    t_flags f;
    char    *fmt;

    if (!(fmt = (char *)malloc(ft_strlen(format) + 1) * sizeof(char)))
        return (0);
    va_start(ap, format);
    va_arg(ap, void);
    // while (format)
    // {
    //     if (ft_strstr(format, "%s"))
    //         str = va_arg(ap, char *);
    //     if (ft_strstr(format, "%d"))

    //     if (ft_strstr(format, "%c"))
    //     format++;
    // }
    va_end(ap);
    return (0);
}

// Idea is that turn format into char *fmt and pass it around functions to fill in 
// the % formats with the values.
// strstr

// One that stores the rest of the format string so that it won't get overwritten

// String argument (ONLY THE PART WE REPLACE %-option WITH) will be passed first 
// to the option-function (diouxX) and then to the flags (precision, l, ll, h)
// after which:

// One that mallocs more (the length of the transformed argument) 
// memory for the format string AND replaces the %- option with value.
