
#ifndef _FT_PRINTF_H_
# define _FT_PRINTF_H_

# include <stdarg.h>
# include <stdio.h>//   REMOVE
# include "libft/libft.h"

typedef struct   s_flag 
{
    void    *addr;
    char    *res;
    char    fmt[20];
    int     printed;
    int     l;    
    int     ll;
    int     h;
    int     hh;
    int     hash;
    int     plus;
    int     minus;
    int     space;
    int     zero;
    int     pres;
    int     width;
}               t_flag;

void            struct_clear(struct s_flag *f);
void            flags_fill(struct s_flag *f, int i);
void            length_mod(struct s_flag *f, int i);
int             valid_format(char c);
void            ft_cs_print(struct s_flag *f, char chr);
int             ft_printf(const char *format, ...);
void            ft_conv_hex(struct s_flag *f, long num, int i, int upper);
void            ft_int_conv(struct s_flag *f, char chr);
void            ft_conv_oct(struct s_flag *f, long num, int i);

#endif