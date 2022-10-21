/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:12:21 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 12:25:54 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Key events, exit and movement
*/
void	menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 20,
		WHITE, "Press 'ESC' to EXIT PROGRAM");
}

static int	exit_fdf(t_mlx *mlx)
{
	delete_image(*mlx, mlx->image);
	mlx_destroy_window(mlx->mlxptr, mlx->winptr);
	exit (EXIT_SUCCESS);
}

int	key_event(int key, t_mlx *mlx)
{
	if (key == 53)
		exit_fdf(mlx);
	if (mlx->fractal_type != 2)
	{
		if (key == 123)
			mlx->x_offset += 100;
		if (key == 124)
			mlx->x_offset -= 100;
		if (key == 126)
			mlx->y_offset += 100;
		if (key == 125)
			mlx->y_offset -= 100;
		if (mlx->y_offset > 800000 || mlx->y_offset < -800000)
			mlx->y_offset = 0;
		if (mlx->x_offset > 800000 || mlx->x_offset < -800000)
			mlx->x_offset = 0;
	}
	if (mlx->fractal_type == 1)
		mandelbrot_calculus(*mlx);
	if (mlx->fractal_type == 2)
		mlx_hook(mlx->winptr, 6, 0, julia_coordinates, mlx);
	if (mlx->fractal_type == 3)
		optional_fractal_calculus(*mlx);
	return (0);
}
