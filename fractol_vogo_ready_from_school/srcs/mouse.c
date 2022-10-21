/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:54:44 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 11:33:22 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mouse_zoom(t_mlx *mlx, int key)
{
	printf("mouse_zoom\n");
	if (key == 4)
	{
		mlx->x_axis_min *= 0.95;
		mlx->x_axis_max *= 0.95;
		mlx->y_axis_min *= 0.95;
		mlx->y_axis_max *= 0.95;
	}
	if (key == 5)
	{
		mlx->x_axis_min *= 1.05;
		mlx->x_axis_max *= 1.05;
		mlx->y_axis_min *= 1.05;
		mlx->y_axis_max *= 1.05;
	}
}

int	mouse_actions(int key, int x, int y, t_mlx *mlx)
{
	printf("mouse_actions\n");
	printf("%d, %d\n", x, y);
	printf("%ld\n", 1L<<6);
	if (x && y)
	{
		x = 0;
		y = 0;
	}
	mouse_zoom(mlx, key);
	mlx->pixel_length_x
		= (mlx->x_axis_max - mlx->x_axis_min) / (WIN_WIDTH - 1);
	mlx->pixel_length_y
		= (mlx->y_axis_max - mlx->y_axis_min) / (WIN_HEIGHT - 1);
	if (mlx->fractal_type == 1)
		mandelbrot_calculus(*mlx);
	if (mlx->fractal_type == 2)
		mlx_hook(mlx->winptr, 6, 0, &julia_coordinates, mlx);
	if (mlx->fractal_type == 3)
		optional_fractal_calculus(*mlx);
	return (0);
}
