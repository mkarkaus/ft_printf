#include <stdio.h>

int     main()
{
    int     i;
    int     d;
    i = 234;
    d = 11111111;
    printf("printf: d: %d, i: %i\n", d, i);

    char    c;
    c = 'z';
    printf("printf: %c\n", c);

    char    *str;
    str = "hmmm";
    printf("printf: %s and %2$dasfweaf%%bmhnty\n", str, d);
    return (0);
}