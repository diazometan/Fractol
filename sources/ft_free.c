/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 12:56:12 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/27 13:01:08 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_free_cl(t_mlx *mlx)
{
    clReleaseProgram(mlx->cl->program);
    clReleaseKernel(mlx->cl->kernel);
    clReleaseCommandQueue(mlx->cl->commands);
    clReleaseContext(mlx->cl->context);
    clReleaseMemObject(mlx->cl->output);
    free(mlx->cl);
}