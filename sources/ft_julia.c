/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:52:08 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/23 21:12:06 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_draw_julia(t_mlx *mlx)
{
    double aa;
    double bb;
    double twoab;
	double a;
	double b;
    double x;
    double y;
    int n;
	int i;
	int j;

	y = mlx->comlex->Min_Im;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		x = mlx->comlex->Min_Re;
		while (j < WIN_WIDTH)
		{
			a = x;
			b = y;
			n = 0;
			while (n < MAX)
			{
				aa = a * a;
				bb = b * b;
				twoab = 2.0 * a * b;
				if (aa + bb > 4.0)
					break;
				a = aa - bb + mlx->comlex->Re_Julia_const;
				b = twoab + mlx->comlex->Im_Julia_const;
				n++;
			}
			if (n == MAX)
			{
				mlx->img.data[j + WIN_WIDTH * i] = 0;
			}
			else
			{
				mlx->img.data[j + WIN_WIDTH * i] = 265 * n;
			}
			j++;
			x += mlx->comlex->step_x;
		}
		y += mlx->comlex->step_y;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}