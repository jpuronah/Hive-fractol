/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:27:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 15:26:22 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal(t_mlx mlx)
{
	mlx.first_round = 1;
	mlx.pixel_length_x = (mlx.x_axis_max - mlx.x_axis_min) / (WIN_WIDTH - 1);
	mlx.pixel_length_y = (mlx.y_axis_max - mlx.y_axis_min) / (WIN_HEIGHT - 1);
	if (mlx.fractal_type == 1)
		mandelbrot_calculus(mlx);
	if (mlx.fractal_type == 2)
		mlx_hook(mlx.winptr, 6, 0, &mouse_events_julia, &mlx);
	if (mlx.fractal_type == 3)
		optional_fractal_calculus(mlx);
}

void	graphics(t_mlx mlx)
{
	if (mlx.first_round == 0)
		init_fractal(mlx);
	mlx_mouse_hook(mlx.winptr, mouse_actions, &mlx);
	mlx_key_hook(mlx.winptr, key_event, &mlx);
	menu(&mlx);
	mlx_loop(mlx.mlxptr);
}
