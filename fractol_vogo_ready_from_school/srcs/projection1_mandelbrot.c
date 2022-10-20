/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection1_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:42:56 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 16:47:08 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_colour(int color)
{
	if (color >= 31)
		return (BLACK);
	if (color == 1)
		return (A);
	if (color == 2)
		return (B);
	if (color == 3)
		return (C);
	if (color == 4)
		return (D);
	if (color == 5)
		return (E);
	if (color == 6)
		return (F);
	if (color == 7)
		return (G);
	if (color == 8)
		return (H);
	if (color == 9)
		return (I);
	if (color == 10)
		return (J);
	if (color == 11)
		return (K);
	if (color == 12)
		return (L);
	if (color == 13)
		return (M);
	if (color == 14)
		return (N);
	if (color == 15)
		return (O);
	if (color == 16)
		return (P);
	if (color == 17)
		return (Q);
	if (color == 18)
		return (E);
	if (color == 19)
		return (S);
	if (color == 20)
		return (T);
	if (color == 21)
		return (U);
	if (color == 22)
		return (V);
	if (color == 23)
		return (W);
	if (color == 24)
		return (X);
	if (color == 25)
		return (Y);
	if (color == 26)
		return (Z);
	if (color == 27)
		return (AA);
	if (color == 28)
		return (AB);
	if (color == 29)
		return (AC);
	if (color == 30)
		return (AD);
	else
		return (AE);
	return (0);
}

void	run_fractal_equation(t_mlx *mlx)
{
	float	tmp;

	tmp = 0.0;
	while (mlx->color++ < mlx->iterations)
	{
		tmp = mlx->z_imaginary;
		mlx->z_imaginary = 2 * mlx->z_real * mlx->z_imaginary + mlx->c_imaginary;
		mlx->z_real = (mlx->z_real * mlx->z_real) - (tmp * tmp) + mlx->c_real;
		if (((mlx->z_real * mlx->z_real) + 
			(mlx->z_imaginary * mlx->z_imaginary)) > 4)
			break ;
	}
}

void	mandelbrot_calculus(t_mlx mlx)
{
	clear_image(mlx.image);
	//mlx.x = 0;
	mlx.y = 0;
	while (mlx.y < WIN_HEIGHT)
	{
		mlx.x = 0;
		mlx.c_imaginary = mlx.y_axis_min + (mlx.y + mlx.y_offset) * mlx.pixel_length_y;
		while (mlx.x < WIN_WIDTH)
		{
			mlx.c_real = mlx.x_axis_min + (mlx.x + mlx.x_offset) * mlx.pixel_length_x;
			mlx.z_real = mlx.c_real;
			mlx.z_imaginary = mlx.c_imaginary;
			mlx.color = 0;
			run_fractal_equation(&mlx);
			color_pixel_in_image(mlx.image, mlx.x, mlx.y, set_colour(mlx.color));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(&mlx);
}
