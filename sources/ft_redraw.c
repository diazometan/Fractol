/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:48:25 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/07 10:11:20 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_redraw(t_mlx *mlx)
{
	if (mlx->comlex->fractal_type == 1)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 1) : ft_draw_mandelbrot(mlx);
	if (mlx->comlex->fractal_type == 2)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 2) : ft_draw_julia(mlx);
	if (mlx->comlex->fractal_type == 3)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 3) : ft_draw_ship(mlx);
	if (mlx->comlex->fractal_type == 4)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 4) : ft_draw_tricorn(mlx);
	if (mlx->comlex->fractal_type == 5)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 5) : ft_draw_buffalo(mlx);
	if (mlx->comlex->fractal_type == 6)
		mlx->gpu_flag == 1 ? draw_gpu_fractal(mlx, 6) : ft_draw_bird(mlx);
}

void	ft_basic_settings(t_mlx *mlx)
{
	mlx->comlex->iter_max = 500;
	mlx->comlex->min_re = -2.0;
	mlx->comlex->max_re = 2.0;
	mlx->comlex->min_im = -2.0;
	mlx->comlex->max_im = 2.0;
	mlx->comlex->step_x = (mlx->comlex->max_re - mlx->comlex->min_re)
							/ WIN_WIDTH;
	mlx->comlex->step_y = (mlx->comlex->max_im - mlx->comlex->min_im)
							/ WIN_HEIGHT;
}
