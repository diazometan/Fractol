/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:47:36 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/26 17:19:32 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int rgb(int n, double a, double b)
{
	double r;
	double g;
	double d;
	double color;
	double color_1;

	color = (n + 2 - log2(log2(a + b))) / MAX;
	color_1 = color - (int)color;
	r = (int)(74 * color_1);
	g = (int)(205 * color_1);
	d = (int)(196 * color_1);
	return ((int)r << 16 | (int)g << 8 | (int)d);
}*/

static void	ft_iteration(t_mlx *mlx, int i, int j)
{
	double aa;
    double bb;
    double twoab;
	int n;

	n = 0;
	while (n < MAX)
	{
		aa = mlx->fractal->x * mlx->fractal->x;
		bb = mlx->fractal->y * mlx->fractal->y;
		twoab = 2.0 * mlx->fractal->x * mlx->fractal->y;
		if (aa + bb > 4.0)
			break ;
		mlx->fractal->x = aa - bb + mlx->comlex->Re;
		mlx->fractal->y = twoab + mlx->comlex->Im;
		n++;
	}
	if (n == MAX)
		mlx->img.data[j + WIN_WIDTH * i] = 0;
	else
		mlx->img.data[j + WIN_WIDTH * i] = 0x00000F << n;
}

void		ft_draw_mandelbrot(t_mlx *mlx)
{
	int i;
	int j;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->comlex->fractal_type = 1;
	mlx->comlex->Im = mlx->comlex->Min_Im;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		mlx->comlex->Re = mlx->comlex->Min_Re;
		while (j < WIN_WIDTH)
		{
			mlx->fractal->x = mlx->comlex->Re;
			mlx->fractal->y = mlx->comlex->Im;
			ft_iteration(mlx, i, j);
			j++;
			mlx->comlex->Re += mlx->comlex->step_x;
		}
		mlx->comlex->Im += mlx->comlex->step_y;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}