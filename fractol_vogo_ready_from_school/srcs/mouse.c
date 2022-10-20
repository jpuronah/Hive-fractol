/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:54:44 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 21:42:06 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mouse_zoom(t_mlx *mlx, int key)
{
	if (key == 4)
	{
		printf("4:%d\n\n\n\n\n\n\n\n\n\n\n\n\n\n", key);
		mlx->x_axis_min *= 0.95;
		mlx->x_axis_max *= 0.95;
		mlx->y_axis_min *= 0.95;
		mlx->y_axis_max *= 0.95;
	}
	if (key == 5)
	{
		printf("5 %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n", key);
		mlx->x_axis_min *= 1.05;
		mlx->x_axis_max *= 1.05;
		mlx->y_axis_min *= 1.05;
		mlx->y_axis_max *= 1.05;
	}
}

void	init_julia_zoom(t_mlx *mlx, t_zoom *julia_zoom)
{
	julia_zoom->pixel_length_x = mlx->pixel_length_x;
	julia_zoom->pixel_length_y = mlx->pixel_length_y;
	julia_zoom->constant_y_julia = mlx->constant_y_julia;
	julia_zoom->constant_x_julia = mlx->constant_x_julia;
	julia_zoom->x_axis_min = mlx->x_axis_min;
	julia_zoom->x_axis_max = mlx->x_axis_max;
	julia_zoom->y_axis_min = mlx->y_axis_min;
	julia_zoom->y_axis_max = mlx->y_axis_max;
}

int	mouse_actions(int key, int x, int y, t_mlx *mlx)
{
	t_zoom	julia_zoom;

	init_julia_zoom(mlx, &julia_zoom);
	if (x && y)
	{
		x = 0;
		y = 0;
	}
	mouse_zoom(mlx, key);
	printf("mouse_actions\n");
	printf("mouse_actions; %d, %d\n", x, y);
	mlx->pixel_length_x = (mlx->x_axis_max - mlx->x_axis_min) / (WIN_WIDTH - 1);
	mlx->pixel_length_y = (mlx->y_axis_max - mlx->y_axis_min) / (WIN_HEIGHT - 1);
	printf("zooms actions; %f, %f\n", mlx->pixel_length_x, mlx->pixel_length_y);
	if (mlx->fractal_type == 1)
		mandelbrot_calculus(*mlx);
	if (mlx->fractal_type == 2)
		mlx_hook(mlx->winptr,6, 0, julia_coordinates, mlx);
	if (mlx->fractal_type == 3)
		optional_fractal_calculus(*mlx);
	return (0);
}

//mlx_hook(data->win, 6, 0, mouse_events_julia, data);