/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:27:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 11:43:01 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal(t_mlx mlx)
{
	printf("init_fractal\n");
	printf("%d\n", mlx.fractal_type);
	mlx.first_round = 1;
	mlx.pixel_length_x = (mlx.x_axis_max - mlx.x_axis_min) / (WIN_WIDTH - 1);
	mlx.pixel_length_y = (mlx.y_axis_max - mlx.y_axis_min) / (WIN_HEIGHT - 1);
	if (mlx.fractal_type == 1)
		mandelbrot_calculus(mlx);
	//if (mlx.fractal_type == 2)
	//	mlx_hook(mlx.winptr, 6, 0, &julia_coordinates, &mlx);
	if (mlx.fractal_type == 2)
		julia_coordinates(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx);
	//if (mlx.fractal_type == 2)
	//	mouse_actions(1, WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx);
	if (mlx.fractal_type == 3)
		optional_fractal_calculus(mlx);
}

void	graphics(t_mlx mlx)
{
	if (mlx.first_round == 0)
		init_fractal(mlx);
	printf("graphics\n\n\n");
	mlx_mouse_hook(mlx.winptr, mouse_actions, &mlx);
	printf("graphics2\n\n\n");
	mlx_key_hook(mlx.winptr, key_event, &mlx);
	mlx_loop(mlx.mlxptr);
	//menu(&mlx);
}
