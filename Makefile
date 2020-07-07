# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 11:11:01 by mkarkaus          #+#    #+#              #
#    Updated: 2020/07/06 11:33:34 by mkarkaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

SRCS_PATH = ./srcs/
SRCS_FILES = ft_printf.c parse_format.c struct_edit.c float_types.c integer_types.c \
optional_flags.c precision_width.c other_float_types.c pointer_types.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

LIB_SRCS_PATH = ./libft/
LIB_SRCS_FILES = ft_putstr_fd.c ft_strlen.c ft_strjoin.c ft_strclr.c ft_atoi.c \
ft_intlen.c ft_itoa_llong.c ft_memalloc.c ft_strrev.c ft_strcpy.c ft_strcmp.c \
ft_strncpy.c ft_itoa.c ft_intlen_llong.c ft_bzero.c ft_strdup.c ft_isdigit.c \
ft_strncmp.c ft_memset.c ft_strcut.c

LIB_SRCS = $(addprefix $(LIB_SRCS_PATH), $(LIB_SRCS_FILES))

FLAGS = -Wall -Werror -Wextra

OBJ = $(patsubst %.c, %.o, $(SRCS_FILES) $(LIB_SRCS_FILES))

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
	@gcc $(LIB_SRCS) $(SRCS) main.c
	@echo "Executable CREATED with flags"

exef:
	@gcc $(FLAGS) $(LIB_SRCS) $(SRCS) main.c
	@echo "Executable CREATED with flags"
