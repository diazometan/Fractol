/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:51:21 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/27 18:32:42 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void check_argv(t_mlx *mlx, char **argv)
{
    if (ft_strcmp(argv[1], "-GPU") == 0)
        mlx->gpu_flag = 1;
    else if (ft_strcmp(argv[1], "-CPU") == 0)
        mlx->gpu_flag = 0;
    if (ft_strcmp (argv[2], "-m") == 0 && mlx->gpu_flag == 1)
        draw_gpu_fractal(mlx, 1);
    else if (ft_strcmp (argv[2], "-m") == 0 && mlx->gpu_flag == 0)
        ft_draw_mandelbrot(mlx);
    else if (ft_strcmp (argv[2], "-j") == 0 && mlx->gpu_flag == 1)
        draw_gpu_fractal(mlx, 2);
    else if (ft_strcmp (argv[2], "-j") == 0 && mlx->gpu_flag == 0)
        ft_draw_julia(mlx);
    else if (ft_strcmp (argv[2], "-b") == 0 && mlx->gpu_flag == 1)
        draw_gpu_fractal(mlx, 3);
    else if (ft_strcmp (argv[2], "-b") == 0 && mlx->gpu_flag == 0)
        ft_draw_ship(mlx);
    else
        exit(1);
}

int main(int argc, char **argv)
{
    t_mlx mlx;
    ft_init_mlx(&mlx);
    ft_init_comlex(&mlx);
    if (!(mlx.mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		exit(1);
    mlx.mouse->x = 0;
	mlx.mouse->y = 0;
    ft_init_key(&mlx);
    ft_init_fractal(&mlx);
    ft_init_cl(&mlx);
    opencl_init(&mlx);
    if (argc == 1)
        exit (1);
    check_argv(&mlx, argv);
	mlx_loop(mlx.mlx_ptr);
    return (0);
}