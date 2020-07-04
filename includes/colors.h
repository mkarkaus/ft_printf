/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:29:59 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/06/24 15:03:38 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

/*
**In order:
**Normal text
**Bold text
**Faint text
**Italic text
**Underlined text
**Background color
*/

const char	*g_cname[] =
{
	"{r}",
	"{red}",
	"{green}",
	"{yellow}",
	"{blue}",
	"{magenta}",
	"{cyan}",
	"{white}",
	"{b_red}",
	"{b_green}",
	"{b_yellow}",
	"{b_blue}",
	"{b_magenta}",
	"{b_cyan}",
	"{b_white}",
	"{f_red}",
	"{f_green}",
	"{f_yellow}",
	"{f_blue}",
	"{f_magenta}",
	"{f_cyan}",
	"{f_white}",
	"{i_red}",
	"{i_green}",
	"{i_yellow}",
	"{i_blue}",
	"{i_magenta}",
	"{i_cyan}",
	"{i_white}",
	"{u_red}",
	"{u_green}",
	"{u_yellow}",
	"{u_blue}",
	"{u_magenta}",
	"{u_cyan}",
	"{u_white}",
	"{bck_black}",
	"{bck_red}",
	"{bck_green}",
	"{bck_yellow}",
	"{bck_blue}",
	"{bck_magenta}",
	"{bck_cyan}",
	"{bck_white}",
};

const char	*g_ccode[] = {
	"\e[0;0m",
	"\e[0;31m",
	"\e[0;32m",
	"\e[0;33m",
	"\e[0;34m",
	"\e[0;35m",
	"\e[0;36m",
	"\e[0;37m",
	"\e[1;31m",
	"\e[1;32m",
	"\e[1;33m",
	"\e[1;34m",
	"\e[1;35m",
	"\e[1;36m",
	"\e[1;37m",
	"\e[2;31m",
	"\e[2;32m",
	"\e[2;33m",
	"\e[2;34m",
	"\e[2;35m",
	"\e[2;36m",
	"\e[2;37m",
	"\e[3;31m",
	"\e[3;32m",
	"\e[3;33m",
	"\e[3;34m",
	"\e[3;35m",
	"\e[3;36m",
	"\e[3;37m",
	"\e[4;31m",
	"\e[4;32m",
	"\e[4;33m",
	"\e[4;34m",
	"\e[4;35m",
	"\e[4;36m",
	"\e[4;37m",
	"\e[0;40m",
	"\e[0;41m",
	"\e[0;42m",
	"\e[0;43m",
	"\e[0;44m",
	"\e[0;45m",
	"\e[0;46m",
	"\e[0;47m"
};

#endif
