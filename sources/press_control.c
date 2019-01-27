/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:00:56 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/27 19:04:58 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEYBOARD_ESC)
		exit(1);
	return (0);
}

void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == MOUSE_SCROLL_DOWN)
		ft_zoom_helper(mlx, 0);
	if (key == MOUSE_SCROLL_UP)
		ft_zoom_helper(mlx, 1);
	if (mlx->comlex->fractal_type == 1)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 1) : ft_draw_mandelbrot(mlx);
    if (mlx->comlex->fractal_type == 2)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 2) : ft_draw_julia(mlx);
    if (mlx->comlex->fractal_type == 3)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 3) : ft_draw_ship(mlx);
}

int	mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return (0);
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		ft_zoom(button, mlx);
	else if (button == MOUSE_BUTTON_1)
		mlx->mouse->press_1 = 1;
	else if (button == MOUSE_BUTTON_2)
		mlx->mouse->press_2 = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_mlx *mlx)
{
	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return (0);
	(void)button;
	mlx->mouse->press_1 = 0;
	mlx->mouse->press_2 = 0;
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->pre_x = mlx->mouse->x;
	mlx->mouse->pre_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->press_1 == 1 && mlx->comlex->fractal_type == 2)
	{
		mlx->comlex->Re_Julia_const = (double)(mlx->mouse->x - WIN_WIDTH / 2) / (WIN_WIDTH / 2);
		mlx->comlex->Im_Julia_const = (double)(mlx->mouse->y - WIN_HEIGHT / 2) / (WIN_HEIGHT / 2);
		draw_gpu_fractal(mlx, 2);
	}
	if (mlx->mouse->press_2 == 1)
	{
		mlx->comlex->Min_Re -= mlx->comlex->step_x * (mlx->mouse->x - mlx->mouse->pre_x);
		mlx->comlex->Min_Im -= mlx->comlex->step_y * (mlx->mouse->y - mlx->mouse->pre_y);
		mlx->comlex->Max_Re -= mlx->comlex->step_x * (mlx->mouse->x - mlx->mouse->pre_x);
		mlx->comlex->Max_Im -= mlx->comlex->step_y * (mlx->mouse->y - mlx->mouse->pre_y);
		draw_gpu_fractal(mlx, 1);
	}
	return (0);
}

int	exit_x(void)
{
	exit(1);
}