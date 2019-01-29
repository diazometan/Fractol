/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:20:47 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 10:35:03 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_zoom_in(t_mlx *mlx, double mouse_x, double mouse_y)
{
	double		mouse_xn;
	double		mouse_yn;

	mlx->comlex->Min_Re *= 0.8;
	mlx->comlex->Max_Re *= 0.8;
	mlx->comlex->Min_Im *= 0.8;
	mlx->comlex->Max_Im *= 0.8;
	mouse_xn = mlx->mouse->x * ((mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH) + mlx->comlex->Min_Re;
	mouse_yn = mlx->mouse->y * ((mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT) + mlx->comlex->Min_Im;
	mlx->comlex->Min_Re += mouse_x - mouse_xn;
	mlx->comlex->Max_Re += mouse_x - mouse_xn; 
	mlx->comlex->Min_Im += mouse_y - mouse_yn;
	mlx->comlex->Max_Im += mouse_y - mouse_yn;
}

static void		ft_zoom_out(t_mlx *mlx, double mouse_x, double mouse_y)
{
	double		mouse_xn;
	double		mouse_yn;

	mlx->comlex->Min_Re *= 1.25;
	mlx->comlex->Max_Re *= 1.25;
	mlx->comlex->Min_Im *= 1.25;
	mlx->comlex->Max_Im *= 1.25;
	mouse_xn = mlx->mouse->x * ((mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH) + mlx->comlex->Min_Re;
	mouse_yn = mlx->mouse->y * ((mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT) + mlx->comlex->Min_Im;
	mlx->comlex->Min_Re += mouse_x - mouse_xn;
	mlx->comlex->Max_Re += mouse_x - mouse_xn; 
	mlx->comlex->Min_Im += mouse_y - mouse_yn;
	mlx->comlex->Max_Im += mouse_y - mouse_yn;
}

static void		ft_zoom_helper(t_mlx *mlx, int type)
{
	double		mouse_x;
	double		mouse_y;

	mouse_x = mlx->mouse->x * ((mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH) + mlx->comlex->Min_Re;
	mouse_y = mlx->mouse->y * ((mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT) + mlx->comlex->Min_Im;
	if (type)
		ft_zoom_in(mlx, mouse_x, mouse_y);
	else
		ft_zoom_out(mlx, mouse_x, mouse_y);
	mlx->comlex->step_x = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH;
	mlx->comlex->step_y = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT;
}

void			ft_zoom(int key, t_mlx *mlx)
{
	if (key == MOUSE_SCROLL_DOWN)
	{
		mlx->comlex->iter_max -= 10;
		printf("%e\n", mlx->comlex->step_x);
		ft_zoom_helper(mlx, 0);
	}
	if (key == MOUSE_SCROLL_UP)
	{
		mlx->comlex->iter_max += 10;
		printf("%e\n", mlx->comlex->step_x);
		ft_zoom_helper(mlx, 1);
	}
	ft_redraw(mlx);
}