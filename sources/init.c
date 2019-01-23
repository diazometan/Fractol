/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:56:05 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/23 20:58:21 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_init_comlex(t_mlx *mlx)
{
    if(!(mlx->comlex = (t_comlex*)malloc(sizeof(t_comlex))))
        exit(1);
    mlx->comlex->Re = 0;
    mlx->comlex->Im = 0;
    mlx->comlex->Re_c = 0;
    mlx->comlex->Im_c = 0;
	mlx->comlex->zoom = 1;
	mlx->comlex->Min_Re = -2.0;
	mlx->comlex->Max_Re = 2.0;
	mlx->comlex->Min_Im = -2.0;
	mlx->comlex->Max_Im = 2.0;
	//mlx->comlex->Max_Im = mlx->comlex->Min_Im + (mlx->comlex->Max_Re - mlx->comlex->Min_Re) * WIN_HEIGHT / WIN_WIDTH;
	mlx->comlex->Re_Julia_const = -0.8;
	mlx->comlex->Im_Julia_const = 0.156;
	mlx->comlex->step_x = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH ;
	mlx->comlex->step_y = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT;
	mlx->comlex->x_offset = 0;
	mlx->comlex->y_offset = 0;
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
