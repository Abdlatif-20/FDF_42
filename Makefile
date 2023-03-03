# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:28:31 by aben-nei          #+#    #+#              #
#    Updated: 2023/03/03 01:00:18 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -Ofast

# -fsanitize=address -g -Ofast
SRC = fdf.c utils.c parsine.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	ft_rotate_x_bonus.c ft_rotate_y_bonus.c ft_key_hook_bonus.c mouse_hooks_bonus.c ft_translate_bonus.c \
	ft_zoom_in_out_bonus.c ft_reset.c ft_color.c dda_algorithm.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_atoi.c \
	libft/ft_calloc.c libft/ft_strdup.c libft/ft_split.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_strlcpy.c \
	libft/ft_substr.c libft/ft_bzero.c libft/ft_memset.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(OBJ)
	# @make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
