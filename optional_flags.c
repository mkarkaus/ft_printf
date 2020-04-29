/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:25:19 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/04/22 15:53:23 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_double_hash(struct s_flag *f, char *str)
{
	int		i;

	i = 0;
	while (f->res[i] != '.' && f->res[i] != '\0')
		i++;
	str = ft_strcpy(str, f->res);
	if (f->res[i] != '.')
	{
		str[i] = '.';
		str[i + 1] = '\0';
	}
	return (str);
}

char	*ft_hash(struct s_flag *f, char chr)
{
	char	*str;

	str = (char *)malloc((ft_strlen(f->res) + 3) * sizeof(char));
	if (chr == 'o' && f->res[0] != '0')
	{
		str[0] = '0';
		ft_strcpy(str + 1, f->res);
	}
	else if ((chr == 'x' || chr == 'X') && ft_strcmp(f->res, "0"))
	{
		str[0] = '0';
		if (chr == 'x')
			str[1] = 'x';
		else
			str[1] = 'X';
		ft_strcpy(str + 2, f->res);
	}
	else if (chr == 'f')
		str = ft_double_hash(f, str);
	free(f->res);
	return (str);
}

void	ft_zero(struct s_flag *f)
{
	int		i;

	i = f->space;
	while (f->res[i] == ' ')
	{
		f->res[i] = '0';
		i++;
	}
}

char	*ft_minus(struct s_flag *f)
{
	char	*str;
	int		spaces;
	int		i;

	spaces = 0;
	str = (char *)malloc((ft_strlen(f->res) + 1) * sizeof(char));
	while (f->res[spaces] == ' ')
		spaces++;
	i = ft_strlen(f->res) - spaces + f->space;
	str = ft_strncpy(str, f->res + spaces - f->space, i);
	while (spaces - f->space > 0)
	{
		str[i] = ' ';
		spaces--;
		i++;
	}
	str[i] = '\0';
	free(f->res);
	return (str);
}
