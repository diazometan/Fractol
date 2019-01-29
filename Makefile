# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 16:55:04 by lwyl-the          #+#    #+#              #
#    Updated: 2019/01/29 18:44:12 by lwyl-the         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MLX = minilibx_macos/libmlx.a

LIB = libft/libft.a

SRC = sources/main.c\
	sources/init.c\
	sources/press_control.c\
	sources/fractals/ft_mandelbrot.c\
	sources/fractals/ft_burnship.c\
	sources/fractals/ft_julia.c\
	sources/fractals/ft_tricorn.c\
	sources/fractals/ft_bird.c\
	sources/fractals/ft_buffalo.c\
	sources/get_next_line.c\
	sources/gpu/ft_draw_gpu.c\
	sources/gpu/ft_kernel_args.c\
	sources/gpu/ft_init_opencl.c\
	sources/gpu/ft_create_gpu_sourcec.c\
	sources/gpu/ft_free.c\
	sources/ft_mouse_move.c\
	sources/ft_usage.c\
	sources/ft_redraw.c\
	sources/ft_zoom.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(MLX)
	gcc -o $(NAME) -Llibft -lft $(OBJ) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -framework OpenCL

.c.o:
	gcc -Wall -Wextra -Werror -I includes/ -Ilibft -o $@ -c $<

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