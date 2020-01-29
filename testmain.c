#include <stdio.h>

int     main()
{
    int     d;
    char    c;
    char    *str;
    int     i;

    d = 111;
    c = 'z';
    str = "hmmm";
    i = printf("lahja%dpaketti\n", d);
    printf("%d", i);
    return (0);
}