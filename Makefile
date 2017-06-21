# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 13:23:44 by oshudria          #+#    #+#              #
#    Updated: 2017/06/20 22:26:39 by oshudria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME = $(shell uname -s)

CC = gcc
NAME = fractol
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes/

SRC_PATH = ./srcs/

SRC_NAME = fractol.c \
		check_input_param.c \
		init_data.c \
		get_fractal_param.c \
		expose.c \
		make_main_image_part_one.c \
		make_main_image_part_two.c \
		mandelbrot.c \
		julia.c \
		burning_ship.c \
		spider.c \
		julia_x.c \
		get_color.c \
		key_hook.c \
		mouse_hook.c \
		move.c \
		zoom.c \
		reset_fractal.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))

LIBFT = ./libft/libft.a
LIBFT_INC = -I./libft/includes/

ifeq ($(UNAME), Darwin)
	ADDLIB = -lm -lpthread -lmlx -framework OpenGL -framework AppKit -O3
else ifeq ($(UNAME), Linux)
	ADDLIB = -lm -lpthread -lmlx -lX11 -lXext -O3
endif

COLOR_NONE = \033[0m
COLOR_YELLOW = \033[33m
COLOR_MAGENTA = \033[35m

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ) $(LIBFT) $(ADDLIB)
	@echo "$(COLOR_YELLOW)Fractol succesfully compiled.$(COLOR_NONE)"

$(OBJ_DIR)/%.o: ./srcs/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(INCLUDES) -c -o $@ $<

clean:
	make clean -C ./libft
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR_MAGENTA)Fractol clean done.$(COLOR_NONE)"

fclean: clean
	@$(RM) $(NAME)
	make fclean -C ./libft
	@echo "$(COLOR_MAGENTA)Fractol fclean done.$(COLOR_NONE)"

re: fclean all
