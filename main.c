#include <stdio.h>
#include "./includes/ft_printf.h"

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

	int     		ret;
	int     		i;
	int     		j;
	unsigned int    u;
	float			f;
	double			d;
	long double		ld;
	char    		*str;

	str = "abcdefg";
	i = 123;
	j = -1;
	u = 123456789;
	f = 123.123321f;
	d = 456.555555555555;
	ld = 789.7777777777777777;

	int k = 0;
	char p[5];

	printf("\n¤¤¤ PLUS FLAG when WIDTH greater than PRECISION ¤¤¤\n\n");

	ret = ft_printf("%+10.9i\n", i);
	printf("my %d\n", ret);
	ret = printf("%+10.9i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+15.9d\n", j);
	printf("my %d\n", ret);
	ret = printf("%+15.9d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+15.9d\n", k);
	printf("my %d\n", ret);
	ret = printf("%+15.9d\n", k);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ FLAG when WIDTH less than PRECISION ¤¤¤\n\n");

	ret = ft_printf("%+10.19i\n", i);
	printf("my %d\n", ret);
	ret = printf("%+10.19i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+9.15d\n", j);
	printf("my %d\n", ret);
	ret = printf("%+9.15d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+9.15d\n", k);
	printf("my %d\n", ret);
	ret = printf("%+9.15d\n", k);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ WITH FLAGS when WIDTH equal to PRECISION ¤¤¤\n\n");

	ret = ft_printf("%+10.10i\n", i);
	printf("my %d\n", ret);
	ret = printf("%+10.10i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+10.10d\n", j);
	printf("my %d\n", ret);
	ret = printf("%+10.10d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+10.10d\n", k);
	printf("my %d\n", ret);
	ret = printf("%+10.10d\n", k);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ HASHTAG FLAG when WIDTH greater than PRECISION ¤¤¤\n\n");

	ret = ft_printf("%#18.9o\n", u);
	printf("my %d\n", ret);
	ret = printf("%#18.9o\n", u);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%#20.9x\n", u);
	printf("my %d\n", ret);
	ret = printf("%#20.9x\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%#20.9X\n", u);
	printf("my %d\n", ret);
	ret = printf("%#20.9X\n", u);
	printf("or %d\n\n", ret);

		printf("\n¤¤¤ FLAG when WIDTH less than PRECISION ¤¤¤\n\n");

	ret = ft_printf("%#19.25o\n", u);
	printf("my %d\n", ret);
	ret = printf("%#19.25o\n", u);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%#19.25x\n", u);
	printf("my %d\n", ret);
	ret = printf("%#19.25x\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%#19.25X\n", u);
	printf("my %d\n", ret);
	ret = printf("%#19.25X\n", u);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ WITH FLAGS when WIDTH equal to PRECISION ¤¤¤\n\n");

	ret = ft_printf("%#19.19o\n", u);
	printf("my %d\n", ret);
	ret = printf("%#19.19o\n", u);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%#19.19x\n", u);
	printf("my %d\n", ret);
	ret = printf("%#19.19x\n", u);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ SPACE FLAG when WIDTH greater than PRECISION ¤¤¤\n\n");

	ret = ft_printf("% 10.9i\n", i);
	printf("my %d\n", ret);
	ret = printf("% 10.9i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("% 15.9d\n", j);
	printf("my %d\n", ret);
	ret = printf("% 15.9d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("% 15.9d\n", k);
	printf("my %d\n", ret);
	ret = printf("% 15.9d\n", k);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ SPACE FLAG when WIDTH less than PRECISION ¤¤¤\n\n");

	ret = ft_printf("% 10.19i\n", i);
	printf("my %d\n", ret);
	ret = printf("% 10.19i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("% 9.15d\n", j);
	printf("my %d\n", ret);
	ret = printf("% 9.15d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("% 9.15d\n", k);
	printf("my %d\n", ret);
	ret = printf("% 9.15d\n", k);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ SPACE FLAG when WIDTH equal to PRECISION ¤¤¤\n\n");

	ret = ft_printf("% 10.10i\n", i);
	printf("my %d\n", ret);
	ret = printf("% 10.10i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("% 10.10d\n", j);
	printf("my %d\n", ret);
	ret = printf("% 10.10d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("% 10.10d\n", k);
	printf("my %d\n", ret);
	ret = printf("% 10.10d\n", k);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ MINUS FLAG when WIDTH greater than PRECISION ¤¤¤\n\n");

	ret = ft_printf("%-10.4s\n", str);
	printf("my %d\n", ret);
	ret = printf("%-10.4s\n", str);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-10.9i\n", i);
	printf("my %d\n", ret);
	ret = printf("%-10.9i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-15.9d\n", j);
	printf("my %d\n", ret);
	ret = printf("%-15.9d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-15.9d\n", k);
	printf("my %d\n", ret);
	ret = printf("%-15.9d\n", k);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-18.9o\n", u);
	printf("my %d\n", ret);
	ret = printf("%-18.9o\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-18.9u\n", u);
	printf("my %d\n", ret);
	ret = printf("%-18.9u\n", u);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%-20.9x\n", u);
	printf("my %d\n", ret);
	ret = printf("%-20.9x\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-20.9X\n", u);
	printf("my %d\n", ret);
	ret = printf("%-20.9X\n", u);
	printf("or %d\n\n", ret);

		printf("\n¤¤¤ FLAG when WIDTH less than PRECISION ¤¤¤\n\n");

	ret = ft_printf("%-4.6s\n", str);
	printf("my %d\n", ret);
	ret = printf("%-4.6s\n", str);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-10.19i\n", i);
	printf("my %d\n", ret);
	ret = printf("%-10.19i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-9.15d\n", j);
	printf("my %d\n", ret);
	ret = printf("%-9.15d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-9.15d\n", k);
	printf("my %d\n", ret);
	ret = printf("%-9.15d\n", k);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-19.25o\n", u);
	printf("my %d\n", ret);
	ret = printf("%-19.25o\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-19.25u\n", u);
	printf("my %d\n", ret);
	ret = printf("%-19.25u\n", u);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%-19.25x\n", u);
	printf("my %d\n", ret);
	ret = printf("%-19.25x\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-19.25X\n", u);
	printf("my %d\n", ret);
	ret = printf("%-19.25X\n", u);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ WITH FLAGS when WIDTH equal to PRECISION ¤¤¤\n\n");

	ret = ft_printf("%-10.10s\n", str);
	printf("my %d\n", ret);
	ret = printf("%-10.10s\n", str);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-10.10i\n", i);
	printf("my %d\n", ret);
	ret = printf("%-10.10i\n", i);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-10.10d\n", j);
	printf("my %d\n", ret);
	ret = printf("%-10.10d\n", j);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-10.10d\n", k);
	printf("my %d\n", ret);
	ret = printf("%-10.10d\n", k);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-19.19o\n", u);
	printf("my %d\n", ret);
	ret = printf("%-19.19o\n", u);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-19.19u\n", u);
	printf("my %d\n", ret);
	ret = printf("%-19.19u\n", u);
	printf("or %d\n\n", ret);
	
	ret = ft_printf("%-19.19x\n", u);
	printf("my %d\n", ret);
	ret = printf("%-19.19x\n", u);
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

	printf("\n¤¤¤ 'f'-flag float ¤¤¤\n");

	ret = ft_printf("%12.5f\n", f);
	printf("my %d\n", ret);
	ret = printf("%12.5f\n", f);
	printf("or %d\n\n", ret);

	ret = ft_printf("%5.10f\n", f);
	printf("my %d\n", ret);
	ret = printf("%5.10f\n", f);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag double ¤¤¤\n");

	ret = ft_printf("%.5lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%.5lf\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.10lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%12.10lf\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.19lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%.19lf\n", d);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag long double ¤¤¤\n");

	ret = ft_printf("%.5Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.5Lf\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.10Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.10Lf\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.19Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.19Lf\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag float ¤¤¤\n");

	ret = ft_printf("%12.5g\n", f);
	printf("my %d\n", ret);
	ret = printf("%12.5g\n", f);
	printf("or %d\n\n", ret);

	ret = ft_printf("%5.10g\n", f);
	printf("my %d\n", ret);
	ret = printf("%5.10g\n", f);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag double ¤¤¤\n");

	ret = ft_printf("%.5lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%.5lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.10lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%12.10lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.19lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%.19lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag long double ¤¤¤\n");

	ret = ft_printf("%.5Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.5Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.10Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.10Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.19Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.19Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag float ¤¤¤\n");

	ret = ft_printf("%12.5e\n", f);
	printf("my %d\n", ret);
	ret = printf("%12.5e\n", f);
	printf("or %d\n\n", ret);

	ret = ft_printf("%5.10e\n", f);
	printf("my %d\n", ret);
	ret = printf("%5.10e\n", f);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag double ¤¤¤\n");

	ret = ft_printf("%.5le\n", d);
	printf("my %d\n", ret);
	ret = printf("%.5le\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.10le\n", d);
	printf("my %d\n", ret);
	ret = printf("%12.10le\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.19le\n", d);
	printf("my %d\n", ret);
	ret = printf("%.19le\n", d);
	printf("or %d\n", ret);

	printf("\n¤¤¤ 'e'-flag long double ¤¤¤\n\n");

	ret = ft_printf("%.5Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.5Le\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%12.10Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.10Le\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%.19Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.19Le\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag float (optional flags) ¤¤¤\n");

	ret = ft_printf("%#12.5f\n", f);
	printf("my %d\n", ret);
	ret = printf("%#12.5f\n", f);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+05.10f\n", f);
	printf("my %d\n", ret);
	ret = printf("%+05.10f\n", f);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag double (optional flags) ¤¤¤\n");

	ret = ft_printf("%-#.5lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%-#.5lf\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+12.10lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%+12.10lf\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%- .19lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%- .19lf\n", d);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag long double (optional flags) ¤¤¤\n");

	ret = ft_printf("%#.5Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%#.5Lf\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-12.10Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%-12.10Lf\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%0+.19Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0+.19Lf\n", ld);
	printf("or %d\n", ret);

	printf("\n¤¤¤ 'g'-flag float (optional flags) ¤¤¤\n\n");

	ret = ft_printf("%#12.5g\n", f);
	printf("my %d\n", ret);
	ret = printf("%#12.5g\n", f);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-5.10g\n", f);
	printf("my %d\n", ret);
	ret = printf("%-5.10g\n", f);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%+.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("% 12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("% 12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%0.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag double (optional flags) ¤¤¤\n");

	ret = ft_printf("%#.5lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%#.5lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-12.10lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%-12.10lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+.19lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%+.19lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%0.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%- 12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%- 12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%#+.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%#+.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag long double (optional flags) ¤¤¤\n");

	ret = ft_printf("%#.5lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%#.5lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-12.10lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%-12.10lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+.19lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%+.19lg\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%0.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%- 12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%- 12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%#+.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%#+.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag float (optional flags) ¤¤¤\n");

	ret = ft_printf("%#12.5e\n", f);
	printf("my %d\n", ret);
	ret = printf("%#12.5e\n", f);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+05.10e\n", f);
	printf("my %d\n", ret);
	ret = printf("%+05.10e\n", f);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag double (optional flags) ¤¤¤\n");

	ret = ft_printf("%-#.5le\n", d);
	printf("my %d\n", ret);
	ret = printf("%-#.5le\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%+12.10le\n", d);
	printf("my %d\n", ret);
	ret = printf("%+12.10le\n", d);
	printf("or %d\n\n", ret);

	ret = ft_printf("%- .19le\n", d);
	printf("my %d\n", ret);
	ret = printf("%- .19le\n", d);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag long double (optional flags) ¤¤¤\n");

	ret = ft_printf("%#.5Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%#.5Le\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%-12.10Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%-12.10Le\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%0+.19Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0+.19Le\n", ld);
	printf("or %d\n\n", ret);

	ret = ft_printf("%0#19X\n", u);
    printf("my %d\n", ret);
    ret = printf("%0#19X\n", u);
    printf("or %d\n\n", ret);
	
	ft_printf("\n¤¤¤ {b_cyan}PRETTY {b_magenta}COLOR {b_yellow}TESTS{r} ¤¤¤\n\n");

	ret = ft_printf("{green}%0+.19Le{r}\n", ld);
	printf("my %d\n", ret);
	ret = ft_printf("{cyan}I'll {red}just {blue}write {b_yellow}a \
{r}long {magenta}sentence\n{bck_red}so{r} {bck_blue}it{r} {bck_green}would{r}\
 {bck_yellow}be{r} {bck_black}easier{r} {bck_cyan}to{r} {u_blue}see{r} {b_green}if\
 \n{u_magenta}this{r} {u_red}works.{r}\n");
	printf("my %d\n\n", ret);

	ret = ft_printf("%%d 0000042 == |%d|", 0000042);
    printf("my %d\n", ret);
    ret = printf("%%d 0000042 == |%d|", 0000042);
    printf("or %d\n\n", ret);
	
	ret = ft_printf("%%%%%%%%%%%%\n");
    printf("my %d\n", ret);
    ret = printf("%%%%%%%%%%%%\n");
    printf("or %d\n\n", ret);
	
	ret = ft_printf("%.03s", NULL);
    printf("my %d\n", ret);
    ret = printf("%.03s", NULL);
    printf("or %d\n\n", ret);

	ret = ft_printf("%.09s", NULL);
    printf("my %d\n", ret);
    ret = printf("%.09s", NULL);
    printf("or %d\n\n", ret);

	ret = ft_printf("%2.9p", 1234);
    printf("my %d\n", ret);
    ret = printf("%2.9p", 1234);
    printf("or %d\n\n", ret);

	// ret = ft_printf("%llu\n", 18446744073709551614);
    // printf("my %d\n", ret);
    // ret = printf("%llu\n", 18446744073709551614);
    // printf("or %d\n\n", ret);

	return (0);
}