#include <stdlib.h>

int     main()
{
    char    *str;

    str = (char *)malloc(7);
    free(str + 1);
    return (0);
}