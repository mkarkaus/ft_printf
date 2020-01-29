/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:06:17 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/25 14:23:42 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define MAX_FD 4864
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

#endif
