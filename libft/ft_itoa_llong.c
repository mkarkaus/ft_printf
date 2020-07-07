/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:24:55 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/06 12:55:20 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa_llong(long long n)
{
	char	*fresh;
	int		i;
	int		k;

	i = ft_intlen_llong(n);
	k = i;
	fresh = ft_memalloc(i + 1);
	if (n == 0)
		fresh[0] = '0';
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
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
