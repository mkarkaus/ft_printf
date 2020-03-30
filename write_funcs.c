
#include "ft_printf.h"

// void    ft_
void	ft_long_oct(struct s_flag *f, int i)
{
    long long int   num;
    char            c;

    printf("111---%ld---111\n", f->addr);
    if (f->l)
        num = (unsigned long int)f->addr;
    else if (f->ll)
        num = (unsigned long long int)f->addr;
    else if (f->h)
        num = (unsigned short)f->addr;
    else if (f->hh)
        num = (unsigned char)f->addr;
    else 
        num = (unsigned int)f->addr;
    while (num != 0)
	{
        if (num < 0)
            num *= -1;
        c = '0' + (num % 8);
        f->res[i++] = '0' + (num % 8);
        num = num / 8;
        printf("***%lld***\n", num);
    }
}

void    ft_int_oct(struct s_flag *f, unsigned int num, int i)
{
    char    c;

    if (num > 7)
        ft_int_oct(f, num / 8, i + 1);
    c = '0' + (num % 8);
    f->res[i] = c;
    printf("***%s***\n", f->res);
}

// void    ft_long_oct(struct s_flag *f, long num, int i)
// {
//     char    c;

//     if (num > 7)
//         ft_long_oct(f, num / 8, i + 1);
//     c = '0' + (num % 8);
//     f->res[i] = c;
// }

void    ft_conv_hex(struct s_flag *f, long num, int i, int upper)
{
    char    hex[] = "0123456789abcdef";
    char    hex_u[] = "0123456789ABCDEF";

    if (num > 15)
        ft_conv_hex(f, num / 16, i + 1, upper);
    if (upper == 0)
        f->res[i] = hex[num % 16];
    else
        f->res[i] = hex_u[num % 16];
}
