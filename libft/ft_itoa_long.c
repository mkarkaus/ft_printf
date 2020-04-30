
#include <stdlib.h>
#include "libft.h"

char		*ft_itoa_long(long n)
{
	char	*fresh;
	int		i;
	int		k;

	i = ft_intlen_long(n);
	k = i;
	if (!(fresh = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	if (n == 0)
		fresh[0] = '0';
	if (n < 0)
	{
		fresh[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		i--;
		fresh[i] = n % 10 + '0';
		n /= 10;
	}
	fresh[k] = '\0';
	return (fresh);
}