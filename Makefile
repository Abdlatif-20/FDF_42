# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:28:31 by aben-nei          #+#    #+#              #
#    Updated: 2023/03/19 18:24:49 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_BNS = fdf_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
RM = rm -f
HDR = fdf.h
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIB = libft/
M = Mandatory/
B = Bonus/
SRC = $(M)fdf.c $(M)utils.c $(M)parsing.c $(GNL) $(B)ft_rotate_x_bonus.c $(B)ft_rotate_y_bonus.c $(M)dda_algorithm.c $(LIB)ft_strlen.c \
	$(LIB)ft_strncmp.c $(LIB)ft_atoi.c $(LIB)ft_calloc.c $(LIB)ft_strdup.c $(LIB)ft_split.c $(LIB)ft_putchar_fd.c $(LIB)ft_putstr_fd.c \
	$(LIB)ft_putendl_fd.c $(LIB)ft_strlcpy.c $(LIB)ft_substr.c $(LIB)ft_bzero.c $(LIB)ft_memset.c $(LIB)ft_putnbr.c

SRC_BNS = $(B)fdf_bonus.c $(M)utils.c $(M)parsing.c $(GNL) $(B)ft_rotate_x_bonus.c $(B)ft_rotate_y_bonus.c $(B)ft_key_hook_bonus.c \
	$(B)mouse_hooks_bonus.c $(B)ft_translate_bonus.c $(B)ft_zoom_in_out_bonus.c $(B)ft_reset.c $(B)ft_color.c $(M)dda_algorithm.c \
	$(LIB)ft_strlen.c $(LIB)ft_strncmp.c $(LIB)ft_atoi.c $(LIB)ft_calloc.c $(LIB)ft_strdup.c $(LIB)ft_split.c $(LIB)ft_putchar_fd.c \
	$(LIB)ft_putstr_fd.c $(LIB)ft_putendl_fd.c $(LIB)ft_strlcpy.c $(LIB)ft_substr.c $(LIB)ft_bzero.c $(LIB)ft_memset.c $(LIB)ft_putnbr.c

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