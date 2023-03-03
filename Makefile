# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:28:31 by aben-nei          #+#    #+#              #
#    Updated: 2023/03/03 16:07:46 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -Ofast

# -fsanitize=address -g -Ofast
SRC = Mandatory/fdf.c Mandatory/utils.c Mandatory/parsine.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	Bonus/ft_rotate_x_bonus.c Bonus/ft_rotate_y_bonus.c Mandatory/dda_algorithm.c  libft/ft_strlen.c libft/ft_strncmp.c \
	libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_split.c libft/ft_putchar_fd.c \
	libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_strlcpy.c libft/ft_substr.c libft/ft_bzero.c libft/ft_memset.c

SRC_BNS = Bonus/fdf_bonus.c Mandatory/utils.c Mandatory/parsine.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	Bonus/ft_rotate_x_bonus.c Bonus/ft_rotate_y_bonus.c Bonus/ft_key_hook_bonus.c Bonus/mouse_hooks_bonus.c Bonus/ft_translate_bonus.c \
	Bonus/ft_zoom_in_out_bonus.c Bonus/ft_reset.c Bonus/ft_color.c Mandatory/dda_algorithm.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_atoi.c \
	libft/ft_calloc.c libft/ft_strdup.c libft/ft_split.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_strlcpy.c \
	libft/ft_substr.c libft/ft_bzero.c libft/ft_memset.c
OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)
LIBFT = libft/libft.a
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)
	@echo ""
	@for i in {1..40}; do \
	printf "\033[1;36m!\033[0m" $$i; \
	sleep 0.03; \
	done
	@echo ""

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: banner_bns $(OBJ_BNS)
	$(CC) $(CFLAGS) $(SRC_BNS) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all


# banner:
# 	@echo "\n"
# 	@echo " \033[38;5;117m\
# 			 ███████╗██████╗░███████╗\n \
# 			 ██╔════╝██╔══██╗██╔════╝\n \
# 			 █████╗  ██║  ██║█████╗  \n \
# 			 ██╔══╝  ██║  ██║██╔══╝  \n \
# 			 ██║     ██████╔╝██║     \n \
# 			 ╚═╝     ╚═════╝ ╚═╝		\n \
# 			\033[0m"
# 	@echo "----------------------- Compiling FDF (Mandatory)...-----------------------"
# 	@echo "\n"


# banner:
# 	@echo "\033[0;36m\
# 	                  _    _      _   _  _____ _   _
# 	                 | |  | |    | | | |/ ____| \ | |
# 	                 | |  | | ___| |_| | |    |  \| |
# 	                 | |/\| |/ _ \ __| | |    | . \` |
# 	                 \  /\  /  __/ |_| | |____| |\  |
# 	                  \/  \/ \___|\__|_|\_____|_| \_|
# 	\033[0m"


banner_bns:
	@echo "\n"
	@echo " \
				███████╗██████╗░███████╗\n \
				██╔════╝██╔══██╗██╔════╝\n \
				█████╗  ██║  ██║█████╗  \n \
				██╔══╝  ██║  ██║██╔══╝  \n \
				██║     ██████╔╝██║     \n \
				╚═╝     ╚═════╝ ╚═╝		\n \
	"
	@echo "----------------------- Compiling FDF (Bonus)...-----------------------"
	@echo "\n"
