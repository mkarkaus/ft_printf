
#include "ft_printf.h"

void            ft_write_hex(struct s_flag *f, long num, int upper)
{
    char    hex[] = "0123456789abcdef";
    char    hex_u[] = "0123456789ABCDEF";

    if (num > 16)
        ft_write_hex(f, num / 16, upper);
    if (upper == 0)
        write(1, hex + (num % 16), 1);
    else
        write(1, hex_u + (num % 16), 1);
    (*f).printed++;
}

void            ft_cs_print(struct s_flag *f, char chr)
{
    void    *arg;

    if (chr == 'c')
        (*f).printed = (*f).printed + write(1, &((*f).addr), 1);
    else if (chr == 's')
        (*f).printed = (*f).printed + ft_putstr((*f).addr);
    else if (chr == 'p')
    {
        arg = malloc(sizeof((*f).addr));
        arg = ft_memcpy(arg, (*f).addr, sizeof((*f).addr));
        (*f).printed = (*f).printed + write(1, "0x", 2);
        ft_write_hex(f, (long)&arg, 0);
    }
    // printf("\n%p\n", f.addr);
}