
#include "ft_printf.h"

void    struct_clear(struct s_flag *f)
{
    ft_strclr(f->fmt);
    ft_strclr(f->res);
    f->l = 0;
    f->ll = 0;
    f->h = 0;
    f->hh = 0;
    f->hash = 0;
    f->plus = 0;
    f->minus = 0;
    f->space = 0;
    f->zero = 0;
    f->pres = 0;
    f->width = 0;
}

int     valid_format(char c)
{
    if (c == 's' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' \
        || c == 'X' || c == 'c' || c == 'p' || c == 'f')
        return (1);
    else if (c == 'l' || c == 'h')
        return (2);
    else if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '.' \
        || c == '*' || (c >= '0' && c <= '9'))
        return (3);
    return (0);
}

void    length_mod(struct s_flag *f, int i)
{
    if (f->fmt[i] == 'l' && f->fmt[i + 1] != 'l')
        f->l = 1;
    else if (f->fmt[i] == 'l' && f->fmt[i + 1] == 'l')
        f->ll = 1;
    else if (f->fmt[i] == 'h' && f->fmt[i + 1] != 'h')
        f->h = 1;
    else if (f->fmt[i] == 'h' && f->fmt[i + 1] == 'h')
        f->hh = 1;
}

void    flags_fill(struct s_flag *f, int i)
{
    while (valid_format(f->fmt[i]) == 3)
    {
        if (f->fmt[i] == '0' && f->zero == 0)
            f->zero = 1;
        else if (f->fmt[i] == '#')
            f->hash = 1;
        else if (f->fmt[i] == '+')
            f->plus = 1;
        else if (f->fmt[i] == '-')
            f->minus = 1;
        else if (f->fmt[i] == ' ')
            f->space = 1;
        else if (f->fmt[i] == '.')
        {
            f->pres = ft_atoi(f->fmt + i + 1);
            i += ft_intlen(f->pres);
        }
        else if (f->fmt[i] >= '1' && f->fmt[i] <= '9')
        {
            f->width = ft_atoi(f->fmt + i);
            i += ft_intlen(f->width) - 1;
        }
        i++;
    }
    length_mod(f, i);
}