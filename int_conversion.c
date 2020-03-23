
#include "ft_printf.h"

void            ft_write_oct(struct s_flag *f, long num)
{
    char    c;

    if (num > 7)
        ft_write_oct(f, num / 8);
    c = '0' + (num % 8);
    write(1, &c, 1);
    f->printed++;
}

void    ft_int_conv(struct s_flag *f, char chr)
{
    if (chr == 'd' || chr == 'i')
    {
        f->printed += write(1, &(*ft_itoa((long)f->addr)), \
            ft_intlen((long)f->addr));
    }
    else if (chr == 'o')
        ft_write_oct(f, (long)f->addr);
    else if (chr == 'x' || chr == 'X')
        ft_write_hex(f, (long)f->addr, chr == 'X');
}

// float_print(struct s_flag *f, long num, int dot)
// {
//     if (num >= 10)
//         float_print(f, num / 10, dot - 1);
//     if (dot == 0)
//         f->printed += write(1, ".", 1);
//     f->printed += write(1, (num % 10) + '0', 1);
// }

// f_flag_func(struct s_flag *f, double num)
// {
//     int     dot;

//     dot = 0;
//     while (num % 10 != 0)
//     {
//         num *= 10;
//         i++;
//     }
//     float_print(f, (long)num, dot);
// }