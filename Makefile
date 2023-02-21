# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:28:31 by aben-nei          #+#    #+#              #
#    Updated: 2023/02/21 18:37:14 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx
# -fsanitize=address -g -Ofast
SRC = fdf.c utils.c parsine.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
