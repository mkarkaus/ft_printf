#include "libft.h"
#include <stdlib.h>

char    *ft_strrev(char *str)
{
    int     i;
    int     j;
    char    *res;

    j = 0;
    i = ft_strlen(str) - 1;
    if (!(res = (char *)malloc((i + 2) * sizeof(char))))
        return (0);
    while (i >= 0)
    {
        res[j] = str[i];
        i--;
        j++;
    }
    res[j] = '\0';
    return (res);
}