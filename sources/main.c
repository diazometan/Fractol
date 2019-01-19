/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:51:21 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/19 21:06:21 by lwyl-the         ###   ########.fr       */
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
    if (ft_strcmp (argv[1], "1"))
        ft_draw(&mlx);
    if (ft_strcmp (argv[1], "2"))
        ft_draw_julia(&mlx);
    //ft_init_key(&mlx);
	mlx_loop(mlx.mlx_ptr);
    return (0);
}