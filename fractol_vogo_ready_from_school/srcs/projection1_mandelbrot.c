/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection1_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:42:56 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 22:02:04 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Iterations measure, how fast the single
**	pixel value will 'blow up' towards infinity
*/
static void	run_fractal_equation_mandelbrot(t_mlx *mlx)
{
	float	tmp;

	tmp = 0.0;
	while (mlx->color++ < mlx->iterations)
	{
		tmp = mlx->z_imaginary;
		mlx->z_imaginary = 2 * mlx->z_real * mlx->z_imaginary + mlx->constant_y;
		mlx->z_real = (mlx->z_real * mlx->z_real) - (tmp * tmp) + mlx->constant_x;
		if (((mlx->z_real * mlx->z_real) + 
			(mlx->z_imaginary * mlx->z_imaginary)) > 4)
			break ;
	}
}

void	mandelbrot_calculus(t_mlx mlx)
{
	clear_image(mlx.image);
	mlx.y = 0;
	while (mlx.y < WIN_HEIGHT)
	{
		mlx.x = 0;
		mlx.constant_y = mlx.y_axis_min + (mlx.y + mlx.y_offset) * mlx.pixel_length_y;
		while (mlx.x < WIN_WIDTH)
		{
			mlx.constant_x = mlx.x_axis_min + (mlx.x + mlx.x_offset) * mlx.pixel_length_x;
			mlx.z_real = mlx.constant_x;
			mlx.z_imaginary = mlx.constant_y;
			mlx.color = 0;
			run_fractal_equation_mandelbrot(&mlx);
			color_pixel_in_image(mlx.image, mlx.x, mlx.y, set_colour(mlx.color));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(&mlx);
}
