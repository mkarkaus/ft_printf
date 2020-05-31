# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 11:11:01 by mkarkaus          #+#    #+#              #
#    Updated: 2020/05/29 18:17:31 by mkarkaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

SRCS = flags_formats.c ft_flags.c ft_printf.c optional_flags.c print_memory.c \
write_funcs.c

LIB_SRCS_PATH = ./libft/
LIB_SRCS_FILES = ft_putstr.c ft_strlen.c ft_strjoin.c ft_strclr.c ft_atoi.c \
ft_intlen.c ft_itoa_long.c ft_memalloc.c ft_strrev.c ft_strcpy.c ft_strcmp.c \
ft_strncpy.c ft_itoa.c ft_intlen_long.c ft_bzero.c ft_strdup.c ft_isdigit.c

LIB_SRCS = $(addprefix $(LIB_SRCS_PATH), $(LIB_SRCS_FILES))

FLAGS = -Wall -Werror -Wextra

HEAD = ft_printf.h

OBJ = $(patsubst %.c, %.o, $(SRCS) $(LIB_SRCS_FILES))

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRCS) $(LIB_SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Archive file '$(NAME)' and object files for it CREATED."

clean:
	@/bin/rm -f $(OBJ)
	@echo "Object files for '$(NAME)' REMOVED."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Archive file '$(NAME)' REMOVED."

re: fclean all

exe:
	@gcc main.c $(NAME)
	@echo "Executable CREATED without flags"

exef:
	@gcc $(FLAGS) main.c $(NAME)
	@echo "Executable CREATED with flags"
