/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:47:36 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/19 21:46:23 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mlx->img.data

//(a + bi) * (a + bi) = (aa - bb) + 2abi 

#include "fractol.h"

/*void		ft_draw(t_mlx *mlx)
{
    double aa;
    double bb;
    double twoab;
    int x;
    int y;
    int n;

	mlx->comlex->Re_factor = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / (WIN_WIDTH * mlx->comlex->zoom);
	mlx->comlex->Im_factor = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / (WIN_HEIGHT * mlx->comlex->zoom);
	mlx->comlex->Max_Im = mlx->comlex->Max_Im - mlx->comlex->Im_factor * mlx->mouse->y;
	mlx->comlex->Min_Re = mlx->comlex->Min_Re + mlx->comlex->Re_factor * mlx->mouse->x;
    y = 0;
    while (y < WIN_HEIGHT)
    {
        mlx->comlex->Im_c = mlx->comlex->Max_Im - y * mlx->comlex->Im_factor;
        x = 0;
        while (x < WIN_WIDTH)
        {
            mlx->comlex->Re_c = mlx->comlex->Min_Re + x * mlx->comlex->Re_factor;
			mlx->comlex->Re_x = mlx->comlex->Re_c;
			mlx->comlex->Im_y = mlx->comlex->Im_c;
			n = 0;
			while (n < MAX)
			{
				aa = mlx->comlex->Re_x * mlx->comlex->Re_x;
				bb = mlx->comlex->Im_y * mlx->comlex->Im_y;
				twoab = 2 * mlx->comlex->Re_x * mlx->comlex->Im_y;
				if (aa + bb > 4)
					break;
				mlx->comlex->Re_x = aa - bb + mlx->comlex->Re_c;
				mlx->comlex->Im_y = twoab +  mlx->comlex->Im_c;
				n++;
			}
			if (n == MAX)
				mlx->img.data[x + WIN_WIDTH * y] = 0;
			else
				mlx->img.data[x + WIN_WIDTH * y] = 0x00000F << n;
			x++;
        }
		y++;
    }
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}*/

// void		ft_change(t_mlx *mlx)
// {
// 		mlx->comlex->x_offset = mlx->mouse->x;
// 		mlx->comlex->y_offset = mlx->mouse->y;
// 		mlx->comlex->x_offset *= mlx->comlex->Re_factor;
// 		mlx->comlex->y_offset *= mlx->comlex->Im_factor;
// 		mlx->comlex->Re_x += mlx->comlex->x_offset;
// 		mlx->comlex->Im_y += mlx->comlex->y_offset;

// 		mlx->comlex->Re_x /= mlx->comlex->zoom;
// 		mlx->comlex->Im_y /= mlx->comlex->zoom;
// 		mlx->comlex->Re_x -= mlx->comlex->x_offset;
// 		mlx->comlex->Im_y -= mlx->comlex->y_offset;
// }

void		ft_draw(t_mlx *mlx)
{
	double aa;
    double bb;
    double twoab;
	double a;
	double b;
    int n;
	int i;
	int j;

	printf("DO %f\n", mlx->comlex->Min_Re);
	printf("DO %f\n", mlx->comlex->Min_Im);
	mlx->comlex->step_x = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / (WIN_WIDTH * mlx->comlex->zoom);
	mlx->comlex->step_y = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / (WIN_HEIGHT * mlx->comlex->zoom);
	mlx->comlex->Min_Im = mlx->comlex->Min_Im / mlx->comlex->zoom + mlx->comlex->step_y * mlx->comlex->y_offset;
	mlx->comlex->Min_Re = mlx->comlex->Min_Re / mlx->comlex->zoom + mlx->comlex->step_x * mlx->comlex->x_offset;
	mlx->comlex->Max_Re = mlx->comlex->Min_Re + mlx->comlex->step_x * WIN_WIDTH;
	mlx->comlex->Max_Im = mlx->comlex->Min_Im + mlx->comlex->step_y * WIN_HEIGHT;
	printf("AFTER %f\n", mlx->comlex->Min_Re);
	printf("AFTER %f\n", mlx->comlex->Min_Im);
	printf("======\n");
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
			{
				mlx->img.data[j + WIN_WIDTH * i] = 0;
			}
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
	mlx->img.data[540 + 540 * 1080] = 0xFFFFFF;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}