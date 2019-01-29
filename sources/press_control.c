/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:00:56 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 16:14:47 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_move_julia(t_mlx *mlx)
{
	if (mlx->julia == 1)
		return ;
	mlx->comlex->re_julia_const = (double)(mlx->mouse->x - WIN_WIDTH / 2)
			/ (WIN_WIDTH / 2);
	mlx->comlex->im_julia_const = (double)(mlx->mouse->y - WIN_HEIGHT / 2)
			/ (WIN_HEIGHT / 2);
	ft_redraw(mlx);
}

int				key_press(int key, t_mlx *mlx)
{
	if (key == KEYBOARD_ONE)
		mlx->comlex->color = 0;
	if (key == KEYBOARD_TWO)
		mlx->comlex->color = 1;
	if (key == KEYBOARD_THREE)
		mlx->comlex->color = 2;
	if (key == KEYBOARD_FOUR)
		mlx->comlex->color = 3;
	if (key == KEYBOARD_FIVE)
		mlx->comlex->color = 4;
	if (key == KEYBOARD_R)
		ft_basic_settings(mlx);
	if (key == NUMPAD_PLUS)
		mlx->comlex->iter_max += 10;
	if (key == NUMPAD_MINUS)
		mlx->comlex->iter_max -= 10;
	if (key == KEYBOARD_SPACE && mlx->comlex->fractal_type == 2)
	{
		mlx->julia++;
		if (mlx->julia > 1)
			mlx->julia = 0;
	}
	ft_redraw(mlx);
	if (key == KEYBOARD_ESC)
		exit(1);
	return (0);
}

int				mouse_press(int button, int x, int y, t_mlx *mlx)
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

int				mouse_release(int button, int x, int y, t_mlx *mlx)
{
	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return (0);
	(void)button;
	mlx->mouse->press_1 = 0;
	mlx->mouse->press_2 = 0;
	return (0);
}

int				mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->pre_x = mlx->mouse->x;
	mlx->mouse->pre_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	ft_move_julia(mlx);
	if (mlx->mouse->press_2 == 1)
	{
		mlx->comlex->min_re -= mlx->comlex->step_x *
				(mlx->mouse->x - mlx->mouse->pre_x);
		mlx->comlex->min_im -= mlx->comlex->step_y *
				(mlx->mouse->y - mlx->mouse->pre_y);
		mlx->comlex->max_re -= mlx->comlex->step_x *
				(mlx->mouse->x - mlx->mouse->pre_x);
		mlx->comlex->max_im -= mlx->comlex->step_y *
				(mlx->mouse->y - mlx->mouse->pre_y);
		ft_redraw(mlx);
	}
	return (0);
}
