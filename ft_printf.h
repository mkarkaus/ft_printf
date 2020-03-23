
#ifndef _FT_PRINTF_H_
# define _FT_PRINTF_H_

# include <stdarg.h>
# include <stdio.h>//   REMOVE
# include "libft/libft.h"

typedef struct   s_flag 
{
    void    *addr;
    char    fmt[10];
    int     printed;
    int     l;    
    int     ll;
    int     h;
    int     hh;
    int     plus;
    int     minus;
    int     space;
    int     zero;
}               t_flag;

void            ft_cs_print(struct s_flag *f, char chr);
int             ft_printf(const char *format, ...);
void            ft_write_hex(struct s_flag *f, long num, int upper);
void            ft_int_conv(struct s_flag *f, char chr);

#endif