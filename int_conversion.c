
#include "ft_printf.h"

void    ft_int_conv(struct s_flag *f, char chr)
{
    if (chr == 'd' || chr == 'i')
    {
        f->printed += write(1, &(*ft_itoa((long)f->addr)), \
            ft_intlen((long)f->addr));
    }
    else if (chr == 'x' || chr == 'X')
        ft_write_hex(f, (long)f->addr, chr == 'X');
}