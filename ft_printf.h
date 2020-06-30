/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 17:38:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/06/30 17:13:31 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>//   REMOVE
# include <inttypes.h>
# include "libft/libft.h"

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
void			flags_fill(t_flag *f, int i);
void			length_mod(t_flag *f, int i);
int				valid_format(char c);
int				ft_printf(const char *format, ...);
void			uitoabase(t_flag *f, unsigned long num, int i, \
					unsigned int base);
void			cspb_conv(t_flag *f, va_list ap, char chr);
void			int_conv(t_flag *f, va_list ap, char chr);
void			float_conv(t_flag *f, va_list ap, int i, char chr);
void			ft_flag_type(t_flag *f, char chr);
void			ft_flags_chars(t_flag *f, char chr);
void			print_memory(const void *addr, size_t size);
char			*minus_flag(t_flag *f);
void			zero_flag(t_flag *f);
char			*hash_flag(t_flag *f, char chr);
void			width_flag(t_flag *f);
void			pres_flag(t_flag *f, char chr);

#endif
