
#include "ft_printf.h"

void            ft_cs_print(struct s_flag f, char chr)
{
    char            *hex;
    unsigned int    i;

    i = 0;
    hex = "0123456789abcdef";
    if (chr == 'c')
        write(1, &(f.addr), 1);
    else if (chr == 's')
        ft_putstr((char *)f.addr);
    else if (chr == 'p')
    {
        while (i < sizeof(f.addr))
        {
            write(1, hex + (((char *)f.addr)[i] / 16), 1);
            write(1, hex + (((char *)f.addr)[i] % 16), 1);
            i++;
        }
    }
}