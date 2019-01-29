/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:00:56 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 18:43:45 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_key_more(int key, t_mlx *mlx)
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
}

int				key_press(int key, t_mlx *mlx)
{
	ft_key_more(key, mlx);
	if (key == KEYBOARD_R)
		ft_basic_settings(mlx);
	if (key == NUMPAD_PLUS)
		mlx->comlex->iter_max += 5;
	if (key == NUMPAD_MINUS)
		mlx->comlex->iter_max -= 5;
	if (key == KEYBOARD_SPACE && mlx->comlex->fractal_type == 2)
	{
		mlx->julia++;
		if (mlx->julia > 1)
			mlx->julia = 0;
	}
	ft_redraw(mlx);
	if (key == KEYBOARD_ESC)
	{
		ft_free(mlx);
		exit(1);
	}
	return (0);
}
