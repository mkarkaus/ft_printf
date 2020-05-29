#include <stdio.h>
#include "ft_printf.h"

int     main()
{
    int     i;
    int     d;
    // long double   n;
	long double	l;

    l = -29143564345644566353.169367456845667849;
    // i = 234;
    // d = 11111111;
    // printf("printf: d: %d, i: %i\n", d, i);

    // char    c = 'p';
    char    *s = "%Lf yo \n";
    // char    *t = "second";
    // ft_printf("ft_printf: %p jaba%saba\n", s, t);

    // char    *str;
    // str = "hmmm";
    // d = ft_printf("ft_printf: %p and %c\n", s, 'f');
    // printf("--%d--\n", d);
    // i = printf("   printf: %p and %c\n", s, 'f');
    // printf("--%d--\n", i);
    d = ft_printf(s, l);
    printf("--%d--\n", d);

	// n = (long double)l;
	// l = (float)n;
    i = printf(s, l);
    printf("--%d--\n", i);
    // return (0);
}