/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:06:01 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/24 11:56:41 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		ft_radian(double degree)
{
	float	radian;

	radian = degree * 3.14 / 180;
	return (radian);
}

int			ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}