# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:28:31 by aben-nei          #+#    #+#              #
#    Updated: 2023/03/08 18:57:12 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_BNS = fdf_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
RM = rm -f
HDR = Mandatory/fdf.h Bonus/fdf_bonus.h
# -fsanitize=address -g -Ofast
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m
NC='\033[0m'
SRC = Mandatory/fdf.c Mandatory/utils.c Mandatory/parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	Bonus/ft_rotate_x_bonus.c Bonus/ft_rotate_y_bonus.c Mandatory/dda_algorithm.c  libft/ft_strlen.c libft/ft_strncmp.c \
	libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_split.c libft/ft_putchar_fd.c \
	libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_strlcpy.c libft/ft_substr.c libft/ft_bzero.c libft/ft_memset.c

SRC_BNS = Bonus/fdf_bonus.c Mandatory/utils.c Mandatory/parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	Bonus/ft_rotate_x_bonus.c Bonus/ft_rotate_y_bonus.c Bonus/ft_key_hook_bonus.c Bonus/mouse_hooks_bonus.c Bonus/ft_translate_bonus.c \
	Bonus/ft_zoom_in_out_bonus.c Bonus/ft_reset.c Bonus/ft_color.c Mandatory/dda_algorithm.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_atoi.c \
	libft/ft_calloc.c libft/ft_strdup.c libft/ft_split.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_strlcpy.c \
	libft/ft_substr.c libft/ft_bzero.c libft/ft_memset.c
OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)
LIBFT = libft/libft.a
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: banner $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)
	@echo "\033[1;32mCreating\033[0m" $@ "\033[1;32m...\033[0m"

bonus: banner_bns $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS)
	@$(CC) $(CFLAGS) $(OBJ_BNS) $(MLXFLAGS) -o $(NAME_BNS)
	@echo "\033[1;32mCreating\033[0m" $@ "\033[1;32m...\033[0m"

%.o: %.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32mCompiling\033[0m" $< "\033[1;32m...\033[0m"
fclean: clean
	@$(RM) $(NAME) $(NAME_BNS)
	@echo "\033[1;31mDeleting\033[0m" $(NAME) $(NAME_BNS) "\033[1;31m...\033[0m"

clean:
	@$(RM) $(OBJ) $(OBJ_BNS)

re: fclean all bonus


banner:
	@echo "\n"
	@echo " \033[38;5;117m\
			       ███████╗██████╗░███████╗\n \
			       ██╔════╝██╔══██╗██╔════╝\n \
			       █████╗  ██║  ██║█████╗  \n \
			       ██╔══╝  ██║  ██║██╔══╝  \n \
			       ██║     ██████╔╝██║     \n \
			       ╚═╝     ╚═════╝ ╚═╝		\n \
			\033[0m"
	@echo "----------------------- Compiling FDF (Mandatory)...-----------------------"
	@echo "\n"

banner_bns:
	@echo "\n"
	@echo " \033[38;5;117m\
			       ███████╗██████╗░███████╗\n \
			       ██╔════╝██╔══██╗██╔════╝\n \
			       █████╗  ██║  ██║█████╗  \n \
			       ██╔══╝  ██║  ██║██╔══╝  \n \
			       ██║     ██████╔╝██║     \n \
			       ╚═╝     ╚═════╝ ╚═╝		\n \
			\033[0m"
	@echo "----------------------- Compiling FDF (Bonus)...-----------------------"
	@echo "\n"