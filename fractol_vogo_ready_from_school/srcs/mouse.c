/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:54:44 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:58:42 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_events_mandelbrot(int x, int y, t_mlx *mlx)
{
	mlx->mandelbrot_c_imaginary = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	mlx->mandelbrot_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	mandelbrot_calculus_mouse_move(*mlx);
	return (0);
}

int	mouse_events_third(int x, int y, t_mlx *mlx)
{
	mlx->third_c_imaginary = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	mlx->third_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	optional_fractal_calculus_mouse_move(*mlx);
	return (0);
}

static void mouse_zoom(t_mlx *mlx, int key)
{
	if (key == 1)
	{
		mlx->real_number_min = mlx->real_number_min * 0.95;
		mlx->real_number_max = mlx->real_number_max * 0.95;
		mlx->imaginary_number_min = mlx->imaginary_number_min * 0.95;
		mlx->imaginary_number_max = mlx->imaginary_number_max * 0.95;
	}
	if (key == 3)
	{
		mlx->real_number_min *= 1.05;
		mlx->real_number_max *= 1.05;
		mlx->imaginary_number_min *= 1.05;
		mlx->imaginary_number_max *= 1.05;
	}
}

int	mouse_actions(int key, int x, int y, t_mlx *mlx)
{
	if (x && y)
	{
		x = 0;
		y = 0;
	}
	mouse_zoom(mlx, key);
	mlx->zoom_real_number = (mlx->real_number_max - mlx->real_number_min) / (WIN_WIDTH - 1);
	mlx->zoom_imaginary_number = (mlx->imaginary_number_max - mlx->imaginary_number_min) / (WIN_HEIGHT - 1);
	if (mlx->mouse_move == 1)
	{
		exit(0);
		if (mlx->fractal_type == 1)
			mlx_hook(mlx->winptr, 6, 0, mouse_events_mandelbrot, &mlx);
		if (mlx->fractal_type == 2)
			mlx_hook(mlx->winptr, 6, 0, &mouse_events_julia, &mlx);
		if (mlx->fractal_type == 3)
			mlx_hook(mlx->winptr, 6, 0, mouse_events_third, &mlx);
	}
	else
	{
		if (mlx->fractal_type == 1)
			mandelbrot_calculus(*mlx);
		if (mlx->fractal_type == 2)
			mlx_hook(mlx->winptr, 6, 0, &mouse_events_julia, &mlx);
		if (mlx->fractal_type == 3)
			optional_fractal_calculus(*mlx);
	}
	return (0);
}
