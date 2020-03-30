#include "libft.h"
#include <stdlib.h>

char    *ft_strrev(char *str)
{
    int     i;
    int     j;
    char    *res;

    j = 0;
    i = ft_strlen(str) - 1;
    res = (char *)malloc((i + 2) * sizeof(char));
    while (i >= 0)
    {
        res[j] = str[i];
        j++;
        i--;
    }
    free(str);
    return (res);
}