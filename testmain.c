#include <stdio.h>
#include "ft_printf.h"

int     main()
{
    int     i;
    int     d;
    int     n;

    n = 45322553;
    // i = 234;
    // d = 11111111;
    // printf("printf: d: %d, i: %i\n", d, i);

    // char    c = 'p';
    // char    *s = "first and second";
    // char    *t = "second";
    // ft_printf("ft_printf: %p jaba%saba\n", s, t);

    // char    *str;
    // str = "hmmm";
    // d = ft_printf("ft_printf: %p and %c\n", s, 'f');
    // printf("--%d--\n", d);
    // i = printf("   printf: %p and %c\n", s, 'f');
    // printf("--%d--\n", i);
    d = ft_printf("%X\n", n);
    printf("--%d--\n", d);
    i = printf("%X\n", n);;
    printf("--%d--\n", i);
    // return (0);
}