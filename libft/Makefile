# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 11:50:18 by mkarkaus          #+#    #+#              #
#    Updated: 2020/07/03 12:09:23 by mkarkaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_memalloc.c ft_memmove.c ft_putnbr.c ft_strclr.c \
ft_striter.c ft_strmapi.c ft_strrchr.c ft_toupper.c ft_isalpha.c ft_memccpy.c \
ft_memset.c ft_putnbr_fd.c ft_strcmp.c ft_striteri.c ft_strncat.c \
ft_strsplit.c ft_isascii.c ft_memchr.c ft_putchar.c ft_putstr.c ft_strcpy.c \
ft_strjoin.c ft_strncmp.c ft_strstr.c ft_isdigit.c ft_memcmp.c \
ft_putchar_fd.c ft_putstr_fd.c ft_strdel.c ft_tolower.c ft_strncpy.c \
ft_strsub.c ft_atoi.c ft_isprint.c ft_memcpy.c ft_putendl.c ft_strcat.c \
ft_strdup.c ft_strlen.c ft_strnequ.c ft_strtrim.c ft_bzero.c ft_itoa.c \
ft_memdel.c ft_putendl_fd.c ft_strchr.c ft_strequ.c ft_strmap.c ft_strnew.c \
ft_strlcat.c ft_strnstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstiter.c ft_lstmap.c ft_intlen.c ft_isupper.c ft_islower.c ft_swap.c \
ft_isspace.c ft_longlen.c ft_itoa_long.c ft_intlen_long.c ft_itoa_ptr.c \
ft_strrev.c ft_strcut.c get_next_line.c

FLAGS = -Wall -Werror -Wextra

HEAD = libft.h get_next_line.h

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "Archive file '$(NAME)' and object files for it CREATED."

clean:
	@/bin/rm -f $(OBJ)
	@echo "Object files for '$(NAME)' REMOVED."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Archive file '$(NAME)' REMOVED."

re: fclean all
