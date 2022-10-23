/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:54:44 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/23 18:14:08 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_axis_default(t_mlx *mlx)
{
	if (mlx->fractal_type == 2)
	{
		mlx->iterations = 25;
		mlx->x_axis_min = -2.0;
		mlx->x_axis_max = 2.0;
		mlx->y_axis_min = -2.0;
		mlx->y_axis_max = 2.0;
	}
	else
	{
		mlx->iterations = 25;
		mlx->x_axis_min = -2.0;
		mlx->x_axis_max = 1.0;
		mlx->y_axis_min = -1.12;
		mlx->y_axis_max = 1.12;
	}
}

static void	mouse_zoom(t_mlx *mlx, int key)
{
	if (key == 4)
	{
		mlx->x_axis_min *= 0.5;
		mlx->x_axis_max *= 0.5;
		mlx->y_axis_min *= 0.5;
		mlx->y_axis_max *= 0.5;
	}
	if (key == 5)
	{
		mlx->x_axis_min *= 1.5;
		mlx->x_axis_max *= 1.5;
		mlx->y_axis_min *= 1.5;
		mlx->y_axis_max *= 1.5;
	}
}

int	mouse_actions(int key, int x, int y, t_mlx *mlx)
{
	mouse_zoom(mlx, key);
	mlx->pixel_length_x
		= (mlx->x_axis_max - mlx->x_axis_min) / (WIN_WIDTH - 1);
	mlx->pixel_length_y
		= (mlx->y_axis_max - mlx->y_axis_min) / (WIN_HEIGHT - 1);
	if (mlx->pixel_length_y > 10 || mlx->pixel_length_x > 10)
		set_axis_default(mlx);
	if (mlx->pixel_length_y < 0.0000001 || mlx->pixel_length_x < 0.0000001)
		set_axis_default(mlx);
	if (mlx->fractal_type == 1)
		mandelbrot_calculus(*mlx);
	if (mlx->fractal_type == 2)
		julia_coordinates(x, y, mlx);
	if (mlx->fractal_type == 2)
		mlx_hook(mlx->winptr, 6, 0, &julia_coordinates, mlx);
	if (mlx->fractal_type == 3)
		optional_fractal_calculus(*mlx);
	return (0);
}
