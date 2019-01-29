/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_gpu_sourcec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:03:18 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/29 14:35:15 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*create_gpu_sources(void)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*new;
	char	*tmp;

	new = ft_strnew(1);
	if ((fd = open(GPU_CODE, O_RDONLY)) == -1)
	{
		ft_putstr("Error with open\n");
		exit(1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = new;
		if (!(new = ft_strjoin(tmp, buf)))
		{
			free(new);
			ft_putstr("Error with strjoin\n");
			exit(1);
		}
		free(tmp);
	}
	return (new);
}
