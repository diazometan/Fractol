/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:06:17 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 11:07:34 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_str_usage()
{
		ft_putstr("Usage\n");
		ft_putstr(" ./fractol [-m | mandelbrot] -Using device\n");
		ft_putstr(" ./fractol [-j | julia]      -Using device\n");
		ft_putstr(" ./fractol [-b | burnship]   -Using device\n");
		ft_putstr(" ./fractol [-t | tricorn]    -Using device\n");
		ft_putstr(" ./fractol [-buf | buffalo]  -Using device\n");
		ft_putstr(" ./fractol [-bir | bird]     -Using device\n");
		ft_putstr("Using device :\n");
		ft_putstr("  GPU or CPU\n");
		exit (1);
}

int		ft_check_argv(t_mlx *mlx, char **argv)
{
	int	type;

	if (ft_strcmp(argv[1], "-GPU") == 0)
		mlx->gpu_flag = 1;
	else if (ft_strcmp(argv[1], "-CPU") == 0)
		mlx->gpu_flag = 0;
	else
		ft_str_usage();
	if ((ft_strcmp (argv[2], "-m") == 0 || ft_strcmp (argv[2], "-mandelbrot") == 0))
		type = 1;
	else if ((ft_strcmp (argv[2], "-j") == 0 || ft_strcmp (argv[2], "-julia") == 0))
		type = 2;
	else if ((ft_strcmp (argv[2], "-b") == 0 || ft_strcmp (argv[2], "-burnship") == 0))
		type = 3;
	else if ((ft_strcmp (argv[2], "-t") == 0 || ft_strcmp (argv[2], "-tricorn") == 0))
		type = 4;
	else if ((ft_strcmp (argv[2], "-buf") == 0 || ft_strcmp (argv[2], "-buffalo") == 0))
		type = 5;
	else if ((ft_strcmp (argv[2], "-bir") == 0 || ft_strcmp (argv[2], "-buffalo") == 0))
		type = 6;
	else
		ft_str_usage();
	return (type);
}
