/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:51:21 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 18:38:39 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				exit_x(void)
{
	exit(1);
}

int				main(int argc, char **argv)
{
	t_mlx		mlx;
	int			type;

	if (argc != 3)
		ft_str_usage();
	type = ft_check_argv(&mlx, argv);
	ft_init_mlx(&mlx);
	ft_init_comlex(&mlx, type);
	ft_init_mouse(&mlx);
	ft_init_key(&mlx);
	ft_init_fractal(&mlx);
	if (mlx.gpu_flag == 1)
	{
		opencl_init(&mlx);
		draw_gpu_fractal(&mlx, mlx.comlex->fractal_type);
	}
	else
		ft_redraw(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
