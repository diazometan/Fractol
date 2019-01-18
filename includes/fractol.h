/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:51:56 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/18 21:20:23 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1080
# define WIN_HEIGHT 1080

# define MAX 100

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include "../libft/includes/libft.h"

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
	int			x;
	int			y;
	int			pre_x;
	int			pre_y;
	int			press_1;
	int			press_2;
}				t_mouse;

typedef struct	s_comlex
{
	double		Re_x;
	double		Im_y;
	double		Re_c;
	double		Im_c;
	double		z_R;
	double		Min_Re;
	double		Max_Re;
	double		Min_Im;
	double		Max_Im;
	double		Re_factor;
	double		Im_factor;
	double		Re_Julia_const;
	double		Im_Julia_const;
}				t_comlex;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			*buffer;
	t_img		img;
	t_mouse		*mouse;
	t_comlex	*comlex;
}				t_mlx;

void			ft_init_mlx(t_mlx *mlx);
void			ft_init_key(t_mlx *mlx);
void			ft_init_comlex(t_mlx *mlx);

int				key_press(int key, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				mouse_release(int button, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);
int				exit_x(void);

void			ft_draw(t_mlx *mlx);
void			ft_draw_julia(t_mlx *mlx);

float			ft_radian(double degree);
int				ft_abs(int a);

#endif