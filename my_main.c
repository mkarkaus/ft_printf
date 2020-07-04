
#include "./includes/ft_printf.h"

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

	ft_printf("\n¤¤¤ HASHTAG ¤¤¤\n");

	ret = ft_printf("%#.19o\n", i);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#.19o\n", i);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%#.19x\n", u);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#.19x\n", u);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'f'-flag float ¤¤¤\n");

	ret = ft_printf("%12.5f\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.5f\n", f);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%5.10f\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%5.10f\n", f);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'f'-flag double ¤¤¤\n");

	ret = ft_printf("%.5lf\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.5lf\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.10lf\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.10lf\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.19lf\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.19lf\n", d);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'f'-flag long double ¤¤¤\n");

	ret = ft_printf("%.5Lf\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.5Lf\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.10Lf\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.10Lf\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.19Lf\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.19Lf\n", ld);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'g'-flag float ¤¤¤\n");

	ret = ft_printf("%12.5g\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.5g\n", f);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%5.10g\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%5.10g\n", f);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.3Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.3Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.2Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.2Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.1Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.1Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'g'-flag double ¤¤¤\n");

	ret = ft_printf("%.5lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.5lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.10lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.10lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.19lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.19lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.3Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.3Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.2Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.2Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.1Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.1Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'g'-flag long double ¤¤¤\n");

	ret = ft_printf("%.5Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.5Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.10Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.10Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.19Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.19Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.3Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.3Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.2Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.2Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.1Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.1Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'e'-flag float ¤¤¤\n");

	ret = ft_printf("%12.5e\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.5e\n", f);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%5.10e\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%5.10e\n", f);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'e'-flag double ¤¤¤\n");

	ret = ft_printf("%.5le\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.5le\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.10le\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.10le\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.19le\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.19le\n", d);
	ft_printf("or %d\n", ret);

	ft_printf("\n¤¤¤ 'e'-flag long double ¤¤¤\n\n");

	ret = ft_printf("%.5Le\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.5Le\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%12.10Le\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%12.10Le\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%.19Le\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%.19Le\n", ld);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'f'-flag float (optional flags) ¤¤¤\n");

	ret = ft_printf("%#12.5f\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#12.5f\n", f);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%+05.10f\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%+05.10f\n", f);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'f'-flag double (optional flags) ¤¤¤\n");

	ret = ft_printf("%-#.5lf\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%-#.5lf\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%+12.10lf\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%+12.10lf\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%- .19lf\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%- .19lf\n", d);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'f'-flag long double (optional flags) ¤¤¤\n");

	ret = ft_printf("%#.5Lf\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#.5Lf\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%-12.10Lf\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%-12.10Lf\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%0+.19Lf\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%0+.19Lf\n", ld);
	ft_printf("or %d\n", ret);

	ft_printf("\n¤¤¤ 'g'-flag float (optional flags) ¤¤¤\n\n");

	ret = ft_printf("%#12.5g\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#12.5g\n", f);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%-5.10g\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%-5.10g\n", f);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%+.3Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%+.3Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("% 12.2Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("% 12.2Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%0.1Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%0.1Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'g'-flag double (optional flags) ¤¤¤\n");

	ret = ft_printf("%#.5lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#.5lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%-12.10lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%-12.10lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%+.19lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%+.19lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%0.3Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%0.3Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%- 12.2Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%- 12.2Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%#+.1Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#+.1Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'g'-flag long double (optional flags) ¤¤¤\n");

	ret = ft_printf("%#.5lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#.5lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%-12.10lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%-12.10lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%+.19lg\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%+.19lg\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%0.3Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%0.3Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%- 12.2Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%- 12.2Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%#+.1Lg\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#+.1Lg\n", ld);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'e'-flag float (optional flags) ¤¤¤\n");

	ret = ft_printf("%#12.5e\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#12.5e\n", f);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%+05.10e\n", f);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%+05.10e\n", f);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'e'-flag double (optional flags) ¤¤¤\n");

	ret = ft_printf("%-#.5le\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%-#.5le\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%+12.10le\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%+12.10le\n", d);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%- .19le\n", d);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%- .19le\n", d);
	ft_printf("or %d\n\n", ret);

	ft_printf("\n¤¤¤ 'e'-flag long double (optional flags) ¤¤¤\n");

	ret = ft_printf("%#.5Le\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%#.5Le\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%-12.10Le\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%-12.10Le\n", ld);
	ft_printf("or %d\n\n", ret);

	ret = ft_printf("%0+.19Le\n", ld);
	ft_printf("my %d\n", ret);
	ret = ft_printf("%0+.19Le\n", ld);
	ft_printf("or %d\n\n", ret);

	// ft_printf("\n¤¤¤ {cyan}PRETTY {red}COLOR {magenta}TESTS{r} ¤¤¤\n");

	// ret = ft_printf("%0+.19Le\n", ld);
	// ft_printf("my %d\n", ret);
	return (0);
}