
#include "libft.h"

int		ft_intlen_long(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
