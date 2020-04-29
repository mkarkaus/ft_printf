/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 17:38:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/04/28 12:50:34 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H_
# define _FT_PRINTF_H_

# include <stdarg.h>
# include <stdio.h>//   REMOVE
# include <inttypes.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	void		*addr;
	char		*res;
	char		fmt[20];
	long double	*ld;
	intmax_t	*num;
	int			printed;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			cap_l;
	int			hash;
	int			plus;
	int			minus;
	int			space;
	int			zero;
	int			pres;
	int			width;
}				t_flag;

void	struct_clear(struct s_flag *f);
void	flags_fill(struct s_flag *f, int i);
void	length_mod(struct s_flag *f, int i);
int		valid_format(char c);
int		ft_printf(const char *format, ...);
void	uitoabase(struct s_flag *f, uintmax_t num, int i, unsigned int base);
void	ft_csp_conv(struct s_flag *f, va_list ap, char chr);
void	ft_int_conv(struct s_flag *f, va_list ap, char chr);
void	ft_double_conv(struct s_flag *f, va_list ap, char chr);
void	ft_flag_type(struct s_flag *f, char chr);
void	ft_flags_chars(struct s_flag *f, char chr);
void	print_memory(const void *addr, size_t size);
char	*ft_minus(struct s_flag *f);
void	ft_zero(struct s_flag *f);
char	*ft_hash(struct s_flag *f, char chr);

#endif