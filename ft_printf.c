#include "libft/libft.h"
#include "ft_printf.h"

int             ft_which_flag(char *str)
{
    
}

struct s_flag   ft_next_flag(char *format, struct s_flag f)
{
    while (format[f.i])
    {
        if (format[f.i] == '%' && format[f.i + 1] == '%')
            f.i++;
        else if (format[f.i] == '%')

        write(1, format[f.i], 1);
        f.i++;
    }
    return (f);
}

int             ft_printf(const char *format, ...)
{
    va_list         ap;
    char            *fmt;
    struct s_flag   f;

    f.i = 0;
    if (!(fmt = (char *)malloc(ft_strlen(format) + 1) * sizeof(char)))
        return (0);
    ft_strcpy(fmt, format);
    va_start(ap, format);
    while (f = ft_next_flag(format, f))
    {

    }
    va_arg(ap, void);
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



//              flag -d___
//             /          \
// ft_printf__/___flag -s__(?precision)
//             \__flag -i_/