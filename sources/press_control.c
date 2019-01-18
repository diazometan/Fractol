/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:00:56 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/18 21:15:25 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEYBOARD_ESC)
		exit(1);
	return (0);
}

int	mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return (0);
	/*if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		ft_zoom(button, mlx);*/
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
	mlx->mouse->x = x - WIN_WIDTH / 2;
	mlx->mouse->y = y - WIN_HEIGHT / 2;
	if (mlx->mouse->press_1 == 1)
	{
		mlx->comlex->Re_Julia_const = (double)(mlx->mouse->x) / (WIN_WIDTH / 2);
		mlx->comlex->Im_Julia_const = (double)(mlx->mouse->y) / (WIN_HEIGHT / 2);
		ft_draw_julia(mlx); 
	}
	return (0);
}

int	exit_x(void)
{
	exit(1);
}