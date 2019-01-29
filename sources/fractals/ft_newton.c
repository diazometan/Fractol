/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:35:36 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/24 12:36:09 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_draw_newton(t_mlx *mlx)
{
	mlx->comlex->fractal_type = 4;
	double aa;
    double bb;
    double twoab;
	double a;
	double b;
    int n;
	int i;
	int j;

	i = 0;
	mlx->comlex->Im = mlx->comlex->Min_Im;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		mlx->comlex->Re = mlx->comlex->Min_Re;
		while (j < WIN_WIDTH)
		{
			a = mlx->comlex->Re;
			b = mlx->comlex->Im;
			n = 0;
			while (n < MAX)
			{
				aa = a * a;
				bb = b * b;
				twoab = 2.0 * a * b;
				if (a * a + b * b > 4.0)
					break ;
				a = aa - bb + mlx->comlex->Re;
				b = twoab + mlx->comlex->Im;
				n++;
			}
			if (n == MAX)
				mlx->img.data[j + WIN_WIDTH * i] = 0;
			else
			{
				mlx->img.data[j + WIN_WIDTH * i] = 0x00000F << n;
			}
			j++;
			mlx->comlex->Re += mlx->comlex->step_x;
		}
		mlx->comlex->Im += mlx->comlex->step_y;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}