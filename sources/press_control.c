/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:00:56 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/23 21:34:14 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */







	// // // // // double WW = (mlx->comlex->Max_Re - mlx->comlex->Min_Re)/2; //*0.8
	// // // // // double HH = (mlx->comlex->Max_Im - mlx->comlex->Min_Im)/2; //*0.8
	// // // // // double XX = (mlx->comlex->Max_Re + mlx->comlex->Min_Re) / 2;
	// // // // // double YY = (mlx->comlex->Max_Im + mlx->comlex->Min_Im) / 2;

	// // // // printf("[%f,%f] [%f,%f]\n", mlx->comlex->Min_Re,mlx->comlex->Min_Im,mlx->comlex->Max_Re,mlx->comlex->Max_Im);
	// // // // printf("step x %f step y %f\n", mlx->comlex->step_x, mlx->comlex->step_y);
	// // // // printf("zoom %f\n", mlx->comlex->zoom);

	// // // // double mouse_x = -1.5;//mlx->mouse->x * mlx->comlex->step_x;
	// // // // double mouse_y = 0;//mlx->mouse->y * mlx->comlex->step_y;

	// // // // // double mouse_x_1 = mlx->comlex->Max_Re - mouse_x;
	// // // // // double mouse_y_1 = mlx->comlex->Max_Im - mouse_y;

	// // // //  double new_mouse_x = (mouse_x - mlx->comlex->Min_Re);
	// // // //  double new_mouse_y = (mouse_y - mlx->comlex->Min_Im);
	// // // //  double new_mouse_x_1 = (mlx->comlex->Max_Re - mouse_x);
	// // // //  double new_mouse_y_1 = (mlx->comlex->Max_Im - mouse_y);

	// // // // printf("mouse_x %f  mouse_y %f\n", mouse_x, mouse_y);

	// // // // printf("off_x_min %f   off_y_min %f\n", new_mouse_x, new_mouse_y);
	// // // // printf("off_x_max %f   off_y_max %f\n", new_mouse_x_1, new_mouse_y_1);

	// // // // mlx->comlex->Min_Re = mouse_x - new_mouse_x * mlx->comlex->zoom; //mouse_x - new_mouse_x_1;
	// // // // mlx->comlex->Max_Re = mouse_x + new_mouse_x_1 * mlx->comlex->zoom;  //mouse_x + new_mouse_x_1;
	// // // // mlx->comlex->Min_Im = mouse_y - new_mouse_y * mlx->comlex->zoom; //mouse_y - new_mouse_y_1;
	// // // // mlx->comlex->Max_Im = mouse_y + new_mouse_y_1 * mlx->comlex->zoom;  //mouse_y + new_mouse_y_1;

	// // // // //mlx->comlex->Min_Im = /*YY - HH*0.8;*/ mlx->comlex->Min_Im + mlx->comlex->step_y * mlx->comlex->y_offset;
	// // // // //mlx->comlex->Min_Re = /*XX - WW*0.8;*/ mlx->comlex->Min_Re + mlx->comlex->step_x * mlx->comlex->x_offset;
	// // // // //mlx->comlex->Max_Re = /*XX + WW*0.8;*/ mlx->comlex->Max_Re + mlx->comlex->step_x * mlx->comlex->x_offset;
	// // // // //mlx->comlex->Max_Im = /*YY + HH*0.8;*/ mlx->comlex->Max_Im + mlx->comlex->step_y * mlx->comlex->y_offset;
	// // // // mlx->comlex->step_x = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH;
	// // // // mlx->comlex->step_y = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT;
	// // // // printf("[%f,%f] [%f,%f]\n", mlx->comlex->Min_Re,mlx->comlex->Min_Im,mlx->comlex->Max_Re,mlx->comlex->Max_Im);
	// // // // printf("step x after %f step y after %f\n", mlx->comlex->step_x, mlx->comlex->step_y);
	// // // // printf("======\n");


#include "fractol.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEYBOARD_ESC)
		exit(1);
	return (0);
}

void ft_zoom_helper(t_mlx *mlx, int type)
{
	printf("step: %f, %f\n", mlx->comlex->step_x, mlx->comlex->step_y);
	double mouse_x = mlx->mouse->x * 0.004;
	double mouse_y = mlx->mouse->y * 0.004;

	printf("[%f, %f] | %f, %f\n", mouse_x, mouse_y, mlx->mouse->x, mlx->mouse->y);

	double new_min_x = (mouse_x - mlx->comlex->Min_Re);
	double new_min_y = (mouse_y - mlx->comlex->Min_Im);
	double new_max_x = (mlx->comlex->Max_Re - mouse_x);
	double new_max_y = (mlx->comlex->Max_Im - mouse_y);

	if (type)
	{
		mlx->comlex->Min_Re = mouse_x - new_min_x * 0.8;
		mlx->comlex->Max_Re = mouse_x + new_max_x * 0.8;
		mlx->comlex->Min_Im = mouse_y - new_min_y * 0.8;
		mlx->comlex->Max_Im = mouse_y + new_max_y * 0.8;
		mlx->comlex->step_x *= 0.8;
		mlx->comlex->step_y *= 0.8;
	}
	else
	{
		mlx->comlex->Min_Re = mouse_x - new_min_x * 1.25;
		mlx->comlex->Max_Re = mouse_x + new_max_x * 1.25;
		mlx->comlex->Min_Im = mouse_y - new_min_y * 1.25;
		mlx->comlex->Max_Im = mouse_y + new_max_y * 1.25;
		mlx->comlex->step_x *= 1.25;
		mlx->comlex->step_y *= 1.25;
	}
	//mlx->comlex->step_x = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH;
	//mlx->comlex->step_y = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT;
}


void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == MOUSE_SCROLL_DOWN)
	{
		mlx->comlex->x_offset = mlx->mouse->x;
		mlx->comlex->y_offset = mlx->mouse->y;
		// mlx->comlex->zoom -= 0.1;
		ft_zoom_helper(mlx, 0);
	}
	if (key == MOUSE_SCROLL_UP)
	{
		mlx->comlex->x_offset = mlx->mouse->x;
		mlx->comlex->y_offset = mlx->mouse->y;
		// mlx->comlex->zoom += 0.1;
		ft_zoom_helper(mlx, 1);
	}
	ft_draw(mlx);
}

int	mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return (0);
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		ft_zoom(button, mlx);
	else if (button == MOUSE_BUTTON_1)
		mlx->mouse->press_1 = 1;
	else if (button == MOUSE_BUTTON_2)
		mlx->mouse->press_2 = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_mlx *mlx)
{
	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return (0);
	(void)button;
	mlx->mouse->press_1 = 0;
	mlx->mouse->press_2 = 0;
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->pre_x = mlx->mouse->x;
	mlx->mouse->pre_y = mlx->mouse->y;
	mlx->mouse->x = x - WIN_WIDTH / 2.0;
	mlx->mouse->y = y - WIN_HEIGHT / 2.0;
	mlx->comlex->step_x = (mlx->comlex->Max_Re - mlx->comlex->Min_Re) / WIN_WIDTH;
	mlx->comlex->step_y = (mlx->comlex->Max_Im - mlx->comlex->Min_Im) / WIN_HEIGHT;

	/*if (mlx->mouse->press_1 == 1)
	{
		mlx->comlex->Re_Julia_const = (double)(mlx->mouse->x) / (WIN_WIDTH / 2);
		mlx->comlex->Im_Julia_const = (double)(mlx->mouse->y) / (WIN_HEIGHT / 2);
		ft_draw_julia(mlx); 
	}
	if (mlx->mouse->press_2 == 1)
	{
		mlx->comlex->x_offset -= (mlx->mouse->x - mlx->mouse->pre_x);
		mlx->comlex->y_offset -= (mlx->mouse->y - mlx->mouse->pre_y);
		ft_draw(mlx);
	}*/
	return (0);
}

int	exit_x(void)
{
	exit(1);
}