/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:27:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:56:30 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal(t_mlx mlx)
{
	mlx.first_round = 1;
	mlx.zoom_real_number = (mlx.real_number_max - mlx.real_number_min) / (WIN_WIDTH - 1);
	mlx.zoom_imaginary_number = (mlx.imaginary_number_max - mlx.imaginary_number_min) / (WIN_HEIGHT - 1);
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
