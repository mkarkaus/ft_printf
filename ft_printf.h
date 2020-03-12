
#ifndef _FT_PRINTF_H_
# define _FT_PRINTF_H_

# include <stdarg.h>
# include <stdio.h>//   REMOVE
# include "libft/libft.h"

typedef struct   s_flag 
{
    void    *addr;
    char    fmt[10];
}               t_flag;

void            ft_cs_print(struct s_flag f, char chr);
int             ft_printf(const char *format, ...);


#endif