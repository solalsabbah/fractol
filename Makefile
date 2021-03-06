# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 14:33:53 by ssabbah           #+#    #+#              #
#    Updated: 2018/02/26 14:49:00 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_FILES =	fractol.c\
		ft_events.c\
		set_menu.c\
		mandelbrot.c\
		julia.c\

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_FILES))
#LIB = $(addprefix -I,$(LIB_PATH))
INC_DIR = inc
INCLUDES = -I $(INC_DIR)

CC = gcc
FLAGS = -Wall -Wextra

LIBFT = -L./libft -lft
#FTPRINTF = -L ./ft_printf
MLX = -L./minilibx -lmlx -framework OpenGL -framework Appkit

all: $(NAME)


$(NAME): $(OBJ)
	@ make -C libft/
	@ make -C minilibx
	@ $(CC) $(FLAGS)  $(LIBFT) $(MLX) $^ -o $@
	@ echo "\033[32mCompilation done : FRACTOL is ready to be used\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:	
	@ make -C libft clean
	@ make -C minilibx clean
	@ rm -rf $(OBJ)
	@ rm -rf $(OBJ_PATH)
	@ echo "\033[32mCleaning obj\033[0m"

fclean: clean
	@ make -C libft fclean
	@ make -C minilibx fclean
	@ rm -f $(NAME)
	@ echo "\033[32mCleaning FRACTOL\033[0m"

norm :
	@make -C libft norm
	norminette $(SRC)

re : fclean all
