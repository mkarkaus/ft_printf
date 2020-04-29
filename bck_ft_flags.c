
#include "ft_printf.h"

void    flags_to_use(struct s_flag *f)
{
    if (f->l != 0)
    {
        f->res = ft_memalloc(ft_intlen((long)f->addr + 2));
    }
    else if (f->ll != 0)
    {
        f->res = ft_memalloc(ft_intlen((long long)f->addr + 2));
    }
    else if (f->h != 0)
    {
        f->res = ft_memalloc(ft_intlen((long)f->addr + 2));
    }
    else if (f->hh != 0)
    {
        f->res = ft_memalloc(3);
    }
    else
    {
        f->res = ft_memalloc(ft_intlen_long((long)f->addr + 2));
    }
}

void    ft_int_conv(struct s_flag *f, char chr)
{
    if (chr == 'd' || chr == 'i')
    {
        if (f->l == 1 || f->ll == 1)
            f->res = ft_itoa_long((long)f->addr);
        else
            f->res = ft_itoa((long)f->addr);
    }
    else if (chr == 'o')
    {
        flags_to_use(f);
        ft_flag_type(f, 0, chr);
        f->res = ft_strrev(f->res);
    }
    else if (chr == 'x' || chr == 'X')
    {
        flags_to_use(f);
        ft_conv_hex(f, (long)f->addr, 0, chr == 'X');
        f->res = ft_strrev(f->res);
    }
    f->printed += ft_putstr(f->res);
    free(f->res);                                  // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}

void    ft_cs_print(struct s_flag *f, char chr)
{
    if (chr == 'c')
        f->printed += write(1, &(f->addr), 1);
    else if (chr == 's')
        f->printed += ft_putstr(f->addr);
    else if (chr == 'p')
    {
        f->printed += write(1, "0x", 2);
        ft_conv_hex(f, (long)&f->addr, 0, 0);
        f->printed += ft_putstr(f->res);
    }
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