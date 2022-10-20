/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:52 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 22:02:08 by jpuronah         ###   ########.fr       */
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
	while (mlx->color++ < mlx->iterations)
	{
		tmp = mlx->z_imaginary;
		mlx->z_imaginary = -2 * mlx->z_real * mlx->z_imaginary + mlx->constant_y;
		mlx->z_real = (mlx->z_real * mlx->z_real) - (tmp * tmp) + mlx->constant_x;
		if (((mlx->z_real * mlx->z_real) + 
			(mlx->z_imaginary * mlx->z_imaginary)) > 4)
			break ;
	}
}

void	optional_fractal_calculus(t_mlx mlx)
{
	clear_image(mlx.image);
	mlx.x = 0;
	mlx.y = 0;
	while (mlx.y < WIN_HEIGHT)
	{
		mlx.constant_y = mlx.y_axis_min + (mlx.y + mlx.y_offset) * mlx.pixel_length_y;
		mlx.x = 0;
		while (mlx.x < WIN_WIDTH)
		{
			mlx.constant_x = mlx.x_axis_min + (mlx.x + mlx.x_offset) * mlx.pixel_length_x;
			mlx.z_real = mlx.constant_x;
			mlx.z_imaginary = mlx.constant_y;
			mlx.color = 0;
			run_fractal_equation_third(&mlx);
			color_pixel_in_image(mlx.image, mlx.x, mlx.y, set_colour(mlx.color));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(&mlx);
}
