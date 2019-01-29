/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:48:25 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 11:08:23 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_redraw(t_mlx *mlx)
{
	if (mlx->comlex->fractal_type == 1)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 1) : ft_draw_mandelbrot(mlx);
    if (mlx->comlex->fractal_type == 2)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 2) : ft_draw_julia(mlx);
    if (mlx->comlex->fractal_type == 3)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 3) : ft_draw_ship(mlx);
	if (mlx->comlex->fractal_type == 4)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 4) : ft_draw_ship(mlx);
	if (mlx->comlex->fractal_type == 5)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 5) : ft_draw_ship(mlx);
	if (mlx->comlex->fractal_type == 6)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 6) : ft_draw_ship(mlx);
}

void ft_basic_settings(t_mlx *mlx)
{
	mlx->comlex->Min_Re = -2.0;
	mlx->comlex->Max_Re = 2.0;
	mlx->comlex->Min_Im = -2.0;
	mlx->comlex->Max_Im = 2.0;
	mlx->comlex->step_x = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH;
	mlx->comlex->step_y = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT;
}
