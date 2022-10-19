/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:52 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 00:00:25 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	colour(int n)
{
	if (n >= 25)
		return (LEMONCHIFFON);
	if (n < 5)
		return (HOTPINK);
	if (n < 7)
		return (FIREBRICK);
	if (n < 9)
		return (BLUE);
	if (n < 2)
		return (GRAY);
	if (n < 11)
		return (GREEN);
	if (n < 13)
		return (PURPLE);
	if (n < 15)
		return (RED);
	if (n < 17)
		return (ALICEBLUE);
	if (n < 19)
		return (CORAL);
	if (n < 21)
		return (WHITE);
	else
		return (BLACK);
	return (0);
}

void	optional_fractal_calculus(t_mlx mlx)
{
	clear_image(mlx.image);
	mlx.x = 0;
	mlx.y = 0;
	while (mlx.y < WIN_HEIGHT)
	{
		mlx.c_imaginary = mlx.imaginary_number_max - mlx.y * mlx.zoom_imaginary_number;
		mlx.x = 0;
		while (mlx.x < WIN_WIDTH)
		{
			mlx.c_real = mlx.real_number_min + mlx.x * mlx.zoom_real_number;
			mlx.z_real = mlx.c_real;
			mlx.z_imaginary = mlx.c_imaginary;
			mlx.n = 0;
			while (mlx.n++ < mlx.iterations)
			{
				mlx.z_real_number_2 = mlx.z_real * mlx.z_real;
				mlx.z_imaginary_number_2 = mlx.z_imaginary * mlx.z_imaginary;
				if (mlx.z_real_number_2 + mlx.z_imaginary_number_2 > 4)
					break ;
				mlx.z_imaginary = -2 * mlx.z_real * mlx.z_imaginary + mlx.c_imaginary;
				mlx.z_real = mlx.z_real_number_2 - mlx.z_imaginary_number_2 + mlx.c_real;
			}
			put_pixel_in_image(mlx.image, mlx.x, mlx.y, colour(mlx.n));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(&mlx);
}

void	optional_fractal_calculus_mouse_move(t_mlx mlx)
{
	clear_image(mlx.image);
	mlx.x = 0;
	mlx.y = 0;
	while (mlx.y < WIN_HEIGHT)
	{
		mlx.c_imaginary = mlx.imaginary_number_max - mlx.y * mlx.zoom_imaginary_number;
		mlx.x = 0;
		while (mlx.x < WIN_WIDTH)
		{
			mlx.c_real = mlx.real_number_min + mlx.x * mlx.zoom_real_number;
			mlx.z_real = mlx.c_real;
			mlx.z_imaginary = mlx.c_imaginary;
			mlx.n = 0;
			while (mlx.n++ < mlx.iterations)
			{
				mlx.z_real_number_2 = mlx.z_real * mlx.z_real;
				mlx.z_imaginary_number_2 = mlx.z_imaginary * mlx.z_imaginary;
				if (mlx.z_real_number_2 + mlx.z_imaginary_number_2 > 4)
					break ;
				mlx.z_imaginary = -2 * mlx.z_real * mlx.z_imaginary + mlx.third_c_imaginary;
				mlx.z_real = mlx.z_real_number_2 - mlx.z_imaginary_number_2 + mlx.third_c_real;
			}
			put_pixel_in_image(mlx.image, mlx.x, mlx.y, colour(mlx.n));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(&mlx);
}

void	optional_fractal_init(t_mlx mlx)
{
	mlx.real_number_min = -2;
	mlx.real_number_max = 1;
	mlx.imaginary_number_min = -1.3;
	mlx.imaginary_number_max = 1.3;
	mlx.zoom_real_number = (mlx.real_number_max - mlx.real_number_min) / (WIN_WIDTH - 1);
	mlx.zoom_imaginary_number = (mlx.imaginary_number_max - mlx.imaginary_number_min) / (WIN_HEIGHT - 1);
	optional_fractal_calculus(mlx);
}
