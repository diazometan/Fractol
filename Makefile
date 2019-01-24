# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 16:55:04 by lwyl-the          #+#    #+#              #
#    Updated: 2019/01/24 12:21:15 by lwyl-the         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MLX = minilibx_macos/libmlx.a

LIB = libft/libft.a

SRC = sources/main.c\
	sources/init.c\
	sources/press_control.c\
	sources/assistant.c\
	sources/ft_mandelbrot.c\
	sources/ft_burnship.c\
	sources/ft_julia.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(MLX)
	gcc -o $(NAME) -Llibft -lft $(OBJ) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

.c.o:
	gcc  -I includes/ -Ilibft -o $@ -c $<

$(LIB):
	cd libft && make
	cd libft && make clean

$(MLX):
	cd minilibx_macos && make

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean
	cd minilibx_macos && make clean

re: fclean all