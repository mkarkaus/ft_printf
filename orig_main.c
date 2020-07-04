#include <stdio.h>

int     main()
{
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

	printf("\n¤¤¤ HASHTAG ¤¤¤\n");

	ret = printf("%#.19o\n", i);
	printf("my %d\n", ret);
	ret = printf("%#.19o\n", i);
	printf("or %d\n\n", ret);

	ret = printf("%#.19x\n", u);
	printf("my %d\n", ret);
	ret = printf("%#.19x\n", u);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag float ¤¤¤\n");

	ret = printf("%12.5f\n", f);
	printf("my %d\n", ret);
	ret = printf("%12.5f\n", f);
	printf("or %d\n\n", ret);

	ret = printf("%5.10f\n", f);
	printf("my %d\n", ret);
	ret = printf("%5.10f\n", f);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag double ¤¤¤\n");

	ret = printf("%.5lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%.5lf\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%12.10lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%12.10lf\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%.19lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%.19lf\n", d);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag long double ¤¤¤\n");

	ret = printf("%.5Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.5Lf\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%12.10Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.10Lf\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%.19Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.19Lf\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag float ¤¤¤\n");

	ret = printf("%12.5g\n", f);
	printf("my %d\n", ret);
	ret = printf("%12.5g\n", f);
	printf("or %d\n\n", ret);

	ret = printf("%5.10g\n", f);
	printf("my %d\n", ret);
	ret = printf("%5.10g\n", f);
	printf("or %d\n\n", ret);

	ret = printf("%.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag double ¤¤¤\n");

	ret = printf("%.5lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%.5lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%12.10lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%12.10lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%.19lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%.19lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag long double ¤¤¤\n");

	ret = printf("%.5Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.5Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%12.10Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.10Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%.19Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.19Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag float ¤¤¤\n");

	ret = printf("%12.5e\n", f);
	printf("my %d\n", ret);
	ret = printf("%12.5e\n", f);
	printf("or %d\n\n", ret);

	ret = printf("%5.10e\n", f);
	printf("my %d\n", ret);
	ret = printf("%5.10e\n", f);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag double ¤¤¤\n");

	ret = printf("%.5le\n", d);
	printf("my %d\n", ret);
	ret = printf("%.5le\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%12.10le\n", d);
	printf("my %d\n", ret);
	ret = printf("%12.10le\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%.19le\n", d);
	printf("my %d\n", ret);
	ret = printf("%.19le\n", d);
	printf("or %d\n", ret);

	printf("\n¤¤¤ 'e'-flag long double ¤¤¤\n\n");

	ret = printf("%.5Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.5Le\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%12.10Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%12.10Le\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%.19Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%.19Le\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag float (optional flags) ¤¤¤\n");

	ret = printf("%#12.5f\n", f);
	printf("my %d\n", ret);
	ret = printf("%#12.5f\n", f);
	printf("or %d\n\n", ret);

	ret = printf("%+05.10f\n", f);
	printf("my %d\n", ret);
	ret = printf("%+05.10f\n", f);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag double (optional flags) ¤¤¤\n");

	ret = printf("%-#.5lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%-#.5lf\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%+12.10lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%+12.10lf\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%- .19lf\n", d);
	printf("my %d\n", ret);
	ret = printf("%- .19lf\n", d);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'f'-flag long double (optional flags) ¤¤¤\n");

	ret = printf("%#.5Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%#.5Lf\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%-12.10Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%-12.10Lf\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%0+.19Lf\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0+.19Lf\n", ld);
	printf("or %d\n", ret);

	printf("\n¤¤¤ 'g'-flag float (optional flags) ¤¤¤\n\n");

	ret = printf("%#12.5g\n", f);
	printf("my %d\n", ret);
	ret = printf("%#12.5g\n", f);
	printf("or %d\n\n", ret);

	ret = printf("%-5.10g\n", f);
	printf("my %d\n", ret);
	ret = printf("%-5.10g\n", f);
	printf("or %d\n\n", ret);

	ret = printf("%+.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%+.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("% 12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("% 12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%0.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag double (optional flags) ¤¤¤\n");

	ret = printf("%#.5lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%#.5lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%-12.10lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%-12.10lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%+.19lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%+.19lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%0.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%- 12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%- 12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%#+.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%#+.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'g'-flag long double (optional flags) ¤¤¤\n");

	ret = printf("%#.5lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%#.5lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%-12.10lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%-12.10lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%+.19lg\n", d);
	printf("my %d\n", ret);
	ret = printf("%+.19lg\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%0.3Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0.3Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%- 12.2Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%- 12.2Lg\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%#+.1Lg\n", ld);
	printf("my %d\n", ret);
	ret = printf("%#+.1Lg\n", ld);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag float (optional flags) ¤¤¤\n");

	ret = printf("%#12.5e\n", f);
	printf("my %d\n", ret);
	ret = printf("%#12.5e\n", f);
	printf("or %d\n\n", ret);

	ret = printf("%+05.10e\n", f);
	printf("my %d\n", ret);
	ret = printf("%+05.10e\n", f);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag double (optional flags) ¤¤¤\n");

	ret = printf("%-#.5le\n", d);
	printf("my %d\n", ret);
	ret = printf("%-#.5le\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%+12.10le\n", d);
	printf("my %d\n", ret);
	ret = printf("%+12.10le\n", d);
	printf("or %d\n\n", ret);

	ret = printf("%- .19le\n", d);
	printf("my %d\n", ret);
	ret = printf("%- .19le\n", d);
	printf("or %d\n\n", ret);

	printf("\n¤¤¤ 'e'-flag long double (optional flags) ¤¤¤\n");

	ret = printf("%#.5Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%#.5Le\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%-12.10Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%-12.10Le\n", ld);
	printf("or %d\n\n", ret);

	ret = printf("%0+.19Le\n", ld);
	printf("my %d\n", ret);
	ret = printf("%0+.19Le\n", ld);
	printf("or %d\n\n", ret);

	// printf("\n¤¤¤ {cyan}PRETTY {red}COLOR {magenta}TESTS{r} ¤¤¤\n");

	// ret = printf("%0+.19Le\n", ld);
	// printf("my %d\n", ret);
	return (0);
}