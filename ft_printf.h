
#ifndef _FT_PRINTF_H_
# define _FT_PRINTF_H_

# include <stdarg.h>
# include <stdio.h>//   REMOVE
# include "libft/libft.h"

int             ft_printf(const char *format, ...);

static struct   s_flag 
{
    void    *addr;
    char    fmt[10];
}               f;

#endif