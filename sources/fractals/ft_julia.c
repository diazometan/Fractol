/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:52:08 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/26 17:19:39 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		mlx->fractal->x = aa - bb + mlx->comlex->Re_Julia_const;
		mlx->fractal->y = twoab + mlx->comlex->Im_Julia_const;
		n++;
	}
	if (n == MAX)
		mlx->img.data[j + WIN_WIDTH * i] = 0;
	else
		mlx->img.data[j + WIN_WIDTH * i] = 265 * n;
}

void ft_draw_julia(t_mlx *mlx)
{
	int i;
	int j;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->comlex->fractal_type = 2;
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