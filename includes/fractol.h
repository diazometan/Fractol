/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:51:56 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/26 19:08:05 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define MAX 50

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line.h"
# include "../libft/includes/libft.h"

# include <OpenCL/opencl.h>

# define MOUSE_BUTTON_1 1
# define MOUSE_BUTTON_2 2
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define KEYBOARD_ESC 53

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mouse
{
	double		x;
	double		y;
	int			pre_x;
	int			pre_y;
	int			press_1;
	int			press_2;
}				t_mouse;

typedef struct	s_fractal
{
	double		x;
	double		y;
	double		two_x_y;
}				t_fractal;

typedef struct	s_cl
{
	int			err;
	cl_device_id device_id;
	cl_context context;
	cl_command_queue commands;
	cl_program program;
	cl_kernel kernel;
	cl_mem output;
	size_t local;
	size_t global;
}				t_cl;

typedef struct	s_comlex
{
	double		Re;
	double		Im;
	double		Re_c;
	double		Im_c;
	double		Min_Re;
	double		Max_Re;
	double		Min_Im;
	double		Max_Im;
	double		step_x;
	double		step_y;
	double		Re_Julia_const;
	double		Im_Julia_const;
	double		zoom;
	double		x_offset;
	double		y_offset;
	int			fractal_type;
}				t_comlex;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			*buffer;
	t_img		img;
	t_mouse		*mouse;
	t_comlex	*comlex;
	t_fractal	*fractal;
	t_cl		*cl;
}				t_mlx;

void			ft_init_mlx(t_mlx *mlx);
void			ft_init_key(t_mlx *mlx);
void			ft_init_comlex(t_mlx *mlx);
void			ft_init_fractal(t_mlx *mlx);
void			ft_init_cl(t_mlx *mlx);

int				key_press(int key, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				mouse_release(int button, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);
int				exit_x(void);

void			ft_draw_mandelbrot(t_mlx *mlx);
void			ft_draw_julia(t_mlx *mlx);
void			ft_draw_ship(t_mlx *mlx);

void			ft_zoom_helper(t_mlx *mlx, int type);

float			ft_radian(double degree);
int				ft_abs(int a);

#endif