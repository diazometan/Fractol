/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gpu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 12:18:40 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 11:50:05 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_gpu_fractal(t_mlx *mlx, int type)
{
	int		err;

	mlx->comlex->fractal_type = type;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	set_kernel_argc(mlx);
	mlx->cl->global = WIN_HEIGHT * WIN_WIDTH;
	err = clEnqueueNDRangeKernel(mlx->cl->commands, mlx->cl->kernel, 1, NULL,
				&mlx->cl->global, NULL, 0, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		ft_putstr("Error with Range\n");
		exit(1);
	}
	clFinish(mlx->cl->commands);
	err = clEnqueueReadBuffer(mlx->cl->commands, mlx->cl->output, CL_TRUE, 0,
				sizeof(cl_int) * WIN_HEIGHT * WIN_WIDTH,
						mlx->img.data, 0, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		ft_putstr("Error with Read buffer\n");
		exit(1);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}
