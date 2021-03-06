/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_opencl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:24:35 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 12:38:39 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_cl(t_mlx *mlx)
{
	if (!(mlx->cl = (t_cl*)malloc(sizeof(t_cl))))
		exit(1);
}

static int		opencl_init_second(t_mlx *mlx)
{
	char		buffer[10000];
	size_t		len;

	mlx->cl->err = clBuildProgram(mlx->cl->program, 0, NULL, NULL, NULL, NULL);
	if (mlx->cl->err != CL_SUCCESS)
	{
		mlx->cl->err = clGetProgramBuildInfo(mlx->cl->program,
				mlx->cl->device_id, CL_PROGRAM_BUILD_LOG,
						10000, buffer, &len);
		if (mlx->cl->err == CL_SUCCESS)
			ft_putstr(buffer);
		else
			ft_putstr("Error with build\n");
		return (-5);
	}
	mlx->cl->kernel = clCreateKernel(mlx->cl->program,
				"fractal", &mlx->cl->err);
	if (!mlx->cl->kernel || mlx->cl->err != CL_SUCCESS)
		return (-6);
	mlx->cl->output = clCreateBuffer(mlx->cl->context, CL_MEM_WRITE_ONLY,
				sizeof(cl_int) * (WIN_HEIGHT * WIN_WIDTH), NULL, NULL);
	if (!mlx->cl->output)
		return (-7);
	return (0);
}

static int		opencl_init_first(t_mlx *mlx)
{
	char		*kernel_source;

	mlx->cl->device_id = NULL;
	mlx->cl->err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU,
				1, &mlx->cl->device_id, NULL);
	if (mlx->cl->err != CL_SUCCESS)
		return (-1);
	mlx->cl->context = clCreateContext(NULL, 1,
				&mlx->cl->device_id, NULL, NULL, &mlx->cl->err);
	if (!mlx->cl->context)
		return (-2);
	mlx->cl->commands = clCreateCommandQueue(mlx->cl->context,
				mlx->cl->device_id, 0, &mlx->cl->err);
	if (!mlx->cl->commands)
		return (-3);
	kernel_source = create_gpu_sources();
	mlx->cl->program = clCreateProgramWithSource(mlx->cl->context, 1,
				(const char **)&kernel_source, NULL, &mlx->cl->err);
	if (!mlx->cl->program)
		return (-4);
	return (opencl_init_second(mlx));
}

void			opencl_init(t_mlx *mlx)
{
	int			err;

	ft_init_cl(mlx);
	err = opencl_init_first(mlx);
	if (err == 0)
	{
		ft_putstr("Good work\n");
		return ;
	}
	ft_putstr("Error with init cl\n");
	exit(1);
}
