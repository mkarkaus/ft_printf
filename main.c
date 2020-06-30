#include <stdio.h>
#include "ft_printf.h"

int     main()
{
	// int     i;
	// int     d;

	// char    *str = "Here go! Outside is very hot weather!";

	// int		fd;
	// fd = open("test.txt", O_WRONLY | O_APPEND);

//     char    *s = "String (s) output: '%s'\n\
// Character (c) output is: '%c'\n\
// {b_cyan}%p is the address of the pointer{r}\n\
// Today is thursday\n\
// {green}Green binary: %b{r}\n\
// 'd'-flag: %d, and 'li'-flag %li\n\
// 'Lf'-flag: %.6Lf, and '.8le'-flag on red background {bck_red}%.8le{r}\n\
// Lowercase hexadecimal: %x, and Uppercase hexadecimal: %X\n\
// octal: %o, and unsigned integer: %u\n";

	// d = ft_printf(s, str, 'A', str, "binary", 123, 456456456456,\
	//             (long double)4.12312314, 989.0, 45665465, 45665465, 45665465, 2147483650);
	// d = ft_printf(format, str, (long double)0.00000008001234567);
	// printf("--%d--\n", d);

	// printf("\nOriginal printf:\n\n");

	int     ret;
	int     i;
	int     j;
	unsigned int    u;
	char    *str;

	str = "abcdefg";
	i = 123;
	j = -1;
	u = 123456789;
	
	int k = 0;
	// int l = -6789
	// unsigned int o = 9;
	// unsigned int x = 456789
	char p[5];
	// char str[6] = "abcdef";


	// ret = ft_printf("%f, ");
	// printf("my %d\n", ret);
	// ret = printf("%f", 5.123456789);
	// printf("or %d\n", ret);

	// printf("%ld\n%ld)", sizeof(long), sizeof(long long));

	printf("\n¤¤¤ PRECISION WITH FLAGS ¤¤¤\n\n");

	printf("\n¤¤¤ ZERO ¤¤¤\n");
	
	ret = ft_printf("%0.20x\n", u);
	printf("my %d\n", ret);
	ret = printf("%0.20x\n", u);
	printf("my %d\n\n", ret);

	ret = ft_printf("%0.20X\n", u);
	printf("my %d\n", ret);
	ret = printf("%0.20X\n", u);
	printf("my %d\n\n", ret);

	printf("\n¤¤¤ PLUS ¤¤¤\n");

	ret = ft_printf("%+.6i\n", i);
	printf("my %d\n", ret);
	ret = printf("%+.6i\n", i);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%+.6d\n", i);
	printf("my %d\n", ret);
	ret = printf("%+.6d\n", i);
	printf("or %d\n\n", ret);

		ret = ft_printf("%+.9i\n", j);
	printf("my %d\n", ret);
	ret = printf("%+.9i\n", j);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%+.9d\n", j);
	printf("my %d\n", ret);
	ret = printf("%+.9d\n", j);
	printf("or %d\n\n", ret);

		ret = ft_printf("%+.5i\n", k);
	printf("my %d\n", ret);
	ret = printf("%+.5i\n", k);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%+.5d\n", k);
	printf("my %d\n", ret);
	ret = printf("%+.5d\n", k);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ MINUS ¤¤¤\n");

	ret = ft_printf("%-.11s\n", str);
	printf("my %d\n", ret);
	ret = printf("%-.11s\n", str);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-.21i\n", i);
	printf("my %d\n", ret);
	ret = printf("%-.21i\n", i);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%-.21d\n", i);
	printf("my %d\n", ret);
	ret = printf("%-.21d\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-.21d\n", j);
	printf("my %d\n", ret);
	ret = printf("%-.21d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-.21d\n", k);
	printf("my %d\n", ret);
	ret = printf("%-.21d\n", k);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-.21o\n", i);
	printf("my %d\n", ret);
	ret = printf("%-.21o\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-.21u\n", u);
	printf("my %d\n", ret);
	ret = printf("%-.21u\n", u);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%-.21x\n", u);
	printf("my %d\n", ret);
	ret = printf("%-.21x\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-.21X\n", u);
	printf("my %d\n", ret);
	ret = printf("%-.21X\n", u);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ SPACE ¤¤¤\n");

	ret = ft_printf("% .11i\n", i);
	printf("my %d\n", ret);
	ret = printf("% .11i\n", i);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("% .11d\n", i);
	printf("my %d\n", ret);
	ret = printf("% .11d\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("% .11d\n", j);
	printf("my %d\n", ret);
	ret = printf("% .11d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("% .11d\n", k);
	printf("my %d\n", ret);
	ret = printf("% .11d\n", k);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ HASHTAG ¤¤¤\n");

	ret = ft_printf("%#.19o\n", i);
	printf("my %d\n", ret);
	ret = printf("%#.19o\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%#.19x\n", u);
	printf("my %d\n", ret);
	ret = printf("%#.19x\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%#.19X\n", u);
	printf("my %d\n", ret);
	ret = printf("%#.19X\n", u);
	printf("or %d\n\n", ret);

	return (0);
}