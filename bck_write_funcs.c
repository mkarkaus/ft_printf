
#include "ft_printf.h"

void    ft_shift_memcpy(struct s_flag *f, int bytes)
{
    char    *str;
    long    temp;
    int     i;
    int     j;

    temp = f->addr;
    printf("---%d---", f->addr);
    j = bytes * 8;
    i = 0;
    str = (char *)malloc(bytes);
    ft_bzero(str, 8 - bytes);
    j -= 8;
    while (i < bytes)
    {
        str[i] = (temp >> j) & 0xFF;
        i++;
        j -= 8;
    }
    f->num = (void *)str;
    printf("***%hd***\n", *f->num);
    print_memory(str, 4);
}

void	ft_flag_type(struct s_flag *f)
{
    // f->num = (intmax_t *)malloc(sizeof(long) * 2);
    // f->num[0] = (intmax_t)malloc(sizeof(long));
    if (f->l)
        ft_shift_memcpy(f, 8);
    else if (f->ll)
        ft_shift_memcpy(f, 8);
    else if (f->h)
        ft_shift_memcpy(f, 2);
    else if (f->hh)
        ft_shift_memcpy(f, 1);
    else 
        ft_shift_memcpy(f, 4);
}

// void	ft_flag_type(struct s_flag *f, char chr)
// {
//     void   *num;
    
//     if (f->l)
//         num = (unsigned long *)f->addr;
//     else if (f->ll)
//         num = (unsigned long long *)f->addr;
//     else if (f->h)
//         num = (unsigned short *)f->addr;
//     else if (f->hh)
//         num = (unsigned char *)f->addr;
//     else 
//         num = (unsigned int *)f->addr;
//     if (chr == 'o')
//         ft_oct_conv(f, (long long)num, 0);
//     else if (chr == 'x' || chr == 'X')
//         ft_hex_conv(f, (long long)num, 0, chr == 'X');
// }

void	ft_oct_conv(struct s_flag *f, long long num, int i)
{
    if (num < 0)
        num *= -1;
    if (num > 7)
        ft_oct_conv(f, num / 8, i + 1);
    f->res[i] = '0' + (num % 8);
}

void    ft_hex_conv(struct s_flag *f, long num, int i, int upper)
{
    char    hex[] = "0123456789abcdef";
    char    hex_u[] = "0123456789ABCDEF";

    if (num > 15)
        ft_hex_conv(f, num / 16, i + 1, upper);
    if (upper == 0)
        f->res[i] = hex[num % 16];
    else
        f->res[i] = hex_u[num % 16];
    // printf("-.-.-.-%s-.-.-.-\n", f->res[i]);
}
