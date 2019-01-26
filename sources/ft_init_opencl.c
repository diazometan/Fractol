/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_opencl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:24:35 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/26 19:02:21 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//#ifdef GPU

static int	opencl_init_second(t_mlx *mlx)
{
	char	buffer[10000];
	size_t	len;

	mlx->cl->err = clBuildProgram(mlx->cl->program, 0, NULL, "-I.", NULL, NULL);
	if (mlx->cl->err != 0)
	{
		mlx->cl->err = clGetProgramBuildInfo(mlx->cl->program, mlx->cl->device_id,
						CL_PROGRAM_BUILD_LOG, 10000, buffer, &len);
		if (mlx->cl->err == 0)
			printf("Buffer error %s\n", buffer);
		else
			printf("Error 404\n");
		return (-5);
	}
	mlx->cl->kernel = clCreateKernel(mlx->cl->program, "fractal", &mlx->cl->err);
	if (!mlx->cl->kernel || mlx->cl->err != 0)
		return (-6);
	mlx->cl->output = clCreateBuffer(mlx->cl->context, CL_MEM_WRITE_ONLY, 4 * WIN_HEIGHT * WIN_WIDTH, NULL, NULL);
	if (!mlx->cl->output)
		return (-7);
	return (0);
}

static int	opencl_init_first(t_mlx *mlx)
{
	char *kernel_source;

	mlx->cl->err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &mlx->cl->device_id, NULL);
	if (mlx->cl->err != 0)
		return (-1);
	mlx->cl->context = clCreateContext(0, 1, &mlx->cl->device_id, NULL, NULL, &mlx->cl->err);
	if (!mlx->cl->context)
		return (-2);
	mlx->cl->commands = clCreateCommandQueue(mlx->cl->context, mlx->cl->device_id, 0, &mlx->cl->err);
	if (!mlx->cl->commands)
		return (-3);
	//kernel_source = ;
	mlx->cl->program = clCreateProgramWithSource(mlx->cl->context, 1, (const char **)&kernel_source, NULL, &mlx->cl->err);
	if (!mlx->cl->program)
		return (-4);
	return (opencl_init_second(mlx));
}

void opencl_init(t_mlx *mlx)
{
	int err;

	err = opencl_init_first(mlx);
	if (err == 0)
	{
		printf("Good work\n");
		return ;
	}
	printf("Error\n");
	exit(1);
}

//#endif