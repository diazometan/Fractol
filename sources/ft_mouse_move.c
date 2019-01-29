/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:41:42 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 18:45:51 by lwyl-the         ###   ########.fr       */
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
