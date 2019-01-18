/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:47:36 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/18 21:13:27 by lwyl-the         ###   ########.fr       */
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
	int flag;

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
			flag = 1;
			while (n < MAX)
			{
				aa = mlx->comlex->Re_x * mlx->comlex->Re_x;
				bb = mlx->comlex->Im_y * mlx->comlex->Im_y;
				twoab = 2 * mlx->comlex->Re_x * mlx->comlex->Im_y;
				if (aa + bb > 4)
				{
					flag = 0;
					break;
				}
				mlx->comlex->Re_x = aa - bb + mlx->comlex->Re_c;
				mlx->comlex->Im_y = twoab +  mlx->comlex->Im_c;
				n++;
			}
			if (flag == 0)
				mlx->img.data[x + WIN_WIDTH * y] = 0xFFFFFF;
			else
				mlx->img.data[x + WIN_WIDTH * y] = n;
			x++;
        }
		y++;
    }
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}*/

void		ft_draw(t_mlx *mlx)
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
				if (a * a + b * b > 4.0)
					break;
				a = aa - bb + x;
				b = twoab + y;
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
			x += mlx->comlex->Re_factor;
		}
		y += mlx->comlex->Im_factor;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}