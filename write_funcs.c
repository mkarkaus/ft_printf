
#include "ft_printf.h"

void    ft_conv_oct(struct s_flag *f, long num, int i)
{
    char    c;

    if (num > 7)
        ft_conv_oct(f, num / 8, i++);
    c = '0' + (num % 8);
    f->res[i] = c;
    // i++;
}

void    ft_conv_hex(struct s_flag *f, long num, int i, int upper)
{
    char    hex[] = "0123456789abcdef";
    char    hex_u[] = "0123456789ABCDEF";

    if (num > 15)
        ft_conv_hex(f, num / 16, i++, upper);
    if (upper == 0)
        f->res[i] = hex[num % 16];
    else
        f->res[i] = hex_u[num % 16];
    // i++;
}
