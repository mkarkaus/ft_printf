
#include "ft_printf.h"

void            ft_write_hex(long num, int upper)
{
    char    hex[] = "0123456789abcdef";
    char    hex_u[] = "0123456789ABCDEF";

    if (num >= 10)
        ft_write_hex(num / 16, upper);
    if (upper == 0)
        write(1, hex + (num % 16), 1);
    else
        write(1, hex_u + (num % 16), 1);
}

void            ft_cs_print(struct s_flag f, char chr)
{
    if (chr == 'c')
        write(1, &(f.addr), 1);
    else if (chr == 's')
        ft_putstr(f.addr);
    else if (chr == 'p')
    {
        write(1, "0x", 2);
        ft_write_hex((long)&f.addr, 0);
    }
    printf("\n%p\n", f.addr);
}