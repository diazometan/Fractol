/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:51:21 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/26 18:43:55 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
    if (argc == 1)
        exit (1);
    if (ft_strcmp (argv[1], "1") == 0)
        ft_draw_mandelbrot(&mlx);
    else if (ft_strcmp (argv[1], "2") == 0)
        ft_draw_julia(&mlx);
    else if (ft_strcmp (argv[1], "3") == 0)
        ft_draw_ship(&mlx);
    else
        exit(1);
	mlx_loop(mlx.mlx_ptr);
    return (0);
}