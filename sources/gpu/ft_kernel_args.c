/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kernel_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 12:19:20 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 12:58:33 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_set_kernel_argc(t_mlx *mlx, int *err)
{
	*err |= clSetKernelArg(mlx->cl->kernel, 9,
			sizeof(double), &mlx->comlex->step_x);
	*err |= clSetKernelArg(mlx->cl->kernel, 10,
			sizeof(double), &mlx->comlex->step_y);
	*err |= clSetKernelArg(mlx->cl->kernel, 11,
			sizeof(double), &mlx->comlex->re_julia_const);
	*err |= clSetKernelArg(mlx->cl->kernel, 12,
			sizeof(double), &mlx->comlex->im_julia_const);
	*err |= clSetKernelArg(mlx->cl->kernel, 13,
			sizeof(int), &mlx->comlex->color);
}

void		set_kernel_argc(t_mlx *mlx)
{
	int		err;

	err = clSetKernelArg(mlx->cl->kernel, 0,
			sizeof(cl_mem), &mlx->cl->output);
	err |= clSetKernelArg(mlx->cl->kernel, 1,
			sizeof(int), &mlx->comlex->width);
	err |= clSetKernelArg(mlx->cl->kernel, 2,
			sizeof(int), &mlx->comlex->height);
	err |= clSetKernelArg(mlx->cl->kernel, 3,
			sizeof(int), &mlx->comlex->fractal_type);
	err |= clSetKernelArg(mlx->cl->kernel, 4,
			sizeof(int), &mlx->comlex->iter_max);
	err |= clSetKernelArg(mlx->cl->kernel, 5,
			sizeof(double), &mlx->comlex->min_re);
	err |= clSetKernelArg(mlx->cl->kernel, 6,
			sizeof(double), &mlx->comlex->max_re);
	err |= clSetKernelArg(mlx->cl->kernel, 7,
			sizeof(double), &mlx->comlex->min_im);
	err |= clSetKernelArg(mlx->cl->kernel, 8,
			sizeof(double), &mlx->comlex->max_im);
	ft_set_kernel_argc(mlx, &err);
	if (err != CL_SUCCESS)
		ft_putstr("Error in kernel args\n");
}
