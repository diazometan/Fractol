/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:20:47 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 17:39:59 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_zoom_in(t_mlx *mlx, double mouse_x, double mouse_y)
{
	double		mouse_xn;
	double		mouse_yn;

	if (mlx->comlex->max_re - mlx->comlex->min_re < ZOOM_MAX)
		return ;
	mlx->comlex->min_re *= 0.8;
	mlx->comlex->max_re *= 0.8;
	mlx->comlex->min_im *= 0.8;
	mlx->comlex->max_im *= 0.8;
	mouse_xn = mlx->mouse->x * ((mlx->comlex->max_re - mlx->comlex->min_re) /
			WIN_WIDTH) + mlx->comlex->min_re;
	mouse_yn = mlx->mouse->y * ((mlx->comlex->max_im - mlx->comlex->min_im) /
			WIN_HEIGHT) + mlx->comlex->min_im;
	mlx->comlex->min_re += mouse_x - mouse_xn;
	mlx->comlex->max_re += mouse_x - mouse_xn;
	mlx->comlex->min_im += mouse_y - mouse_yn;
	mlx->comlex->max_im += mouse_y - mouse_yn;
}

static void		ft_zoom_out(t_mlx *mlx, double mouse_x, double mouse_y)
{
	double		mouse_xn;
	double		mouse_yn;

	mlx->comlex->min_re *= 1.25;
	mlx->comlex->max_re *= 1.25;
	mlx->comlex->min_im *= 1.25;
	mlx->comlex->max_im *= 1.25;
	mouse_xn = mlx->mouse->x * ((mlx->comlex->max_re - mlx->comlex->min_re) /
			WIN_WIDTH) + mlx->comlex->min_re;
	mouse_yn = mlx->mouse->y * ((mlx->comlex->max_im - mlx->comlex->min_im) /
			WIN_HEIGHT) + mlx->comlex->min_im;
	mlx->comlex->min_re += mouse_x - mouse_xn;
	mlx->comlex->max_re += mouse_x - mouse_xn;
	mlx->comlex->min_im += mouse_y - mouse_yn;
	mlx->comlex->max_im += mouse_y - mouse_yn;
}

static void		ft_zoom_helper(t_mlx *mlx, int type)
{
	double		mouse_x;
	double		mouse_y;

	if (mlx->comlex->min_re >= mlx->comlex->max_re || mlx->comlex->min_im >= mlx->comlex->max_im)
	{
		return ;
	}
	mouse_x = mlx->mouse->x * ((mlx->comlex->max_re - mlx->comlex->min_re) /
			WIN_WIDTH) + mlx->comlex->min_re;
	mouse_y = mlx->mouse->y * ((mlx->comlex->max_im - mlx->comlex->min_im) /
			WIN_HEIGHT) + mlx->comlex->min_im;
	if (type)
		ft_zoom_in(mlx, mouse_x, mouse_y);
	else
		ft_zoom_out(mlx, mouse_x, mouse_y);
	mlx->comlex->step_x = (mlx->comlex->max_re - mlx->comlex->min_re) /
			WIN_WIDTH;
	mlx->comlex->step_y = (mlx->comlex->max_im - mlx->comlex->min_im) /
			WIN_HEIGHT;
}

void			ft_zoom(int key, t_mlx *mlx)
{
	if (key == MOUSE_SCROLL_DOWN)
	{
		mlx->comlex->iter_max -= 5;
		ft_zoom_helper(mlx, 0);
	}
	if (key == MOUSE_SCROLL_UP)
	{
		mlx->comlex->iter_max += 5;
		ft_zoom_helper(mlx, 1);
	}
	ft_redraw(mlx);
}
