/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:52 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 13:35:27 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Iterations measure, how fast the single
**	pixel value will 'blow up' towards infinity
*/
static void	run_fractal_equation_third(t_mlx *mlx)
{
	float	tmp;

	tmp = 0.0;
	while (mlx->colour++ < mlx->iterations)
	{
		tmp = mlx->y_pixel;
		mlx->y_pixel = -2 * mlx->x_pixel * mlx->y_pixel + mlx->constant_y;
		mlx->x_pixel = (mlx->x_pixel * mlx->x_pixel)
			- (tmp * tmp) + mlx->constant_x;
		if (((mlx->x_pixel * mlx->x_pixel)
				+ (mlx->y_pixel * mlx->y_pixel)) > 4)
			break ;
	}
}

void	optional_fractal_calculus(t_mlx mlx)
{
	mlx.x = 0;
	mlx.y = 0;
	while (mlx.y < WIN_HEIGHT)
	{
		mlx.constant_y = mlx.y_axis_min
			+ (mlx.y + mlx.y_offset) * mlx.pixel_length_y;
		mlx.x = 0;
		while (mlx.x < WIN_WIDTH)
		{
			mlx.constant_x = mlx.x_axis_min
				+ (mlx.x + mlx.x_offset) * mlx.pixel_length_x;
			mlx.x_pixel = mlx.constant_x;
			mlx.y_pixel = mlx.constant_y;
			mlx.colour = 0;
			run_fractal_equation_third(&mlx);
			mlx_pixel_put(mlx.mlxptr, mlx.winptr,
				mlx.x, mlx.y, set_colour(mlx.colour));
			mlx.x++;
		}
		mlx.y++;
	}
	menu(&mlx);
}
