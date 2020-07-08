/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 17:38:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/07/08 12:50:08 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>//REMOVE
# include <stdarg.h>
# include <inttypes.h>
# include "../libft/libft.h"

typedef struct	s_flag
{
	void		*addr;
	char		*res;
	char		fmt[20];
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
	int			exp;
	int			fd;
}				t_flag;

void			struct_clear(t_flag *f);
int				receive_flags(t_flag *f, int i, va_list ap);
int				length_mod(t_flag *f, int i);
void			identify_conv(t_flag *f, va_list ap);
int				valid_format(char c);
int				receive_format(const char *format, t_flag *f, va_list ap);
int				ft_printf(const char *format, ...);
void			uitoabase(t_flag *f, unsigned long long num, int i, \
					unsigned int base);
void			pointer_conv(t_flag *f, va_list ap, char chr);
void			int_conv(t_flag *f, va_list ap, char chr);
void			insert_exp(t_flag *f);
void			g_adjust_pres(t_flag *f, long double nbr, int k);
char			*rm_trailing_zeros(char *str);
int				other_float_types(t_flag *f, long double *nbr, char chr);
void			float_conv(t_flag *f, va_list ap, int i, char chr);
void			apply_length_mod(t_flag *f, char chr);
void			apply_width_pres_flags(t_flag *f, char chr);
void			print_memory(const void *addr, size_t size);
void			minus_flag(t_flag *f);
void			zero_flag(t_flag *f);
char			*hash_flag(t_flag *f, char chr);
void			apply_width(t_flag *f, int edge_case);
void			apply_prec(t_flag *f, char chr);

#endif
