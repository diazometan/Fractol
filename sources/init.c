/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:56:05 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 09:04:26 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fractal(t_mlx *mlx)
{
	if(!(mlx->fractal = (t_fractal*)malloc(sizeof(t_fractal))))
		exit(1);
}

void	ft_init_mouse(t_mlx *mlx)
{
	if (!(mlx->mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		exit(1);
	mlx->mouse->x = 0;
	mlx->mouse->y = 0;
}

void    ft_init_comlex(t_mlx *mlx, int type)
{
    if(!(mlx->comlex = (t_comlex*)malloc(sizeof(t_comlex))))
        exit(1);
    mlx->comlex->Re = 0;
    mlx->comlex->Im = 0;
    mlx->comlex->Re_c = 0;
    mlx->comlex->Im_c = 0;
	mlx->comlex->Min_Re = -2.0;
	mlx->comlex->Max_Re = 2.0;
	mlx->comlex->Min_Im = -2.0;
	mlx->comlex->Max_Im = 2.0;
	mlx->comlex->Re_Julia_const = -0.8;
	mlx->comlex->Im_Julia_const = 0.156;
	mlx->comlex->step_x = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH;
	mlx->comlex->step_y = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT;
	mlx->comlex->width = WIN_WIDTH;
	mlx->comlex->height = WIN_HEIGHT;
	mlx->comlex->iter_max = MAX;
	mlx->comlex->color = 0;
	mlx->comlex->fractal_type = type;
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FRACTOL");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
		&mlx->img.size_l, &mlx->img.endian);
}

void	ft_init_key(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, exit_x, mlx);
}
