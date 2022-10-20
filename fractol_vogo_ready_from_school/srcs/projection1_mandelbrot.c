/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection1_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:42:56 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 11:41:34 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
t_palette	*get_palettes(void)
{
	static t_palette	array[5];

	array[0] =
		(t_palette){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[1] =
		(t_palette){5, 0, {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[2] =
		(t_palette){5, 0, {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF}};
	array[3] =
		(t_palette){7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}};
	array[4] = (t_palette){0, 0, {0}};
	return (array);
}
*/

/*
static int	colour(int n)
{
	if (n >= 25)
		return (BLACK);
	if (n < 1)
		return (HOTPINK);
	if (n < 2)
		return (HOTPINK);
	if (n < 3)
		return (HOTPINK);
	if (n < 4)
		return (HOTPINK);
	if (n < 5)
		return (HOTPINK);
	if (n < 6)
		return (HOTPINK);
	if (n < 7)
		return (FIREBRICK);
	if (n < 8)
		return (HOTPINK);
	if (n < 9)
		return (BLUE);
	if (n < 10)
		return (HOTPINK);
	if (n < 11)
		return (GREEN);
	if (n < 12)
		return (HOTPINK);
	if (n < 13)
		return (PURPLE);
	if (n < 14)
		return (HOTPINK);
	if (n < 15)
		return (RED);
	if (n < 16)
		return (HOTPINK);
	if (n < 17)
		return (ALICEBLUE);
	if (n < 18)
		return (HOTPINK);
	if (n < 19)
		return (CORAL);
	if (n < 20)
		return (HOTPINK);
	if (n < 21)
		return (WHITE);
	else
		return (LEMONCHIFFON);
	return (0);
}*/

static int	colour(int n)
{
	if (n >= 31)
		return (BLACK);
	if (n < 1)
		return (A);
	if (n < 2)
		return (B);
	if (n < 3)
		return (C);
	if (n < 4)
		return (D);
	if (n < 5)
		return (E);
	if (n < 6)
		return (F);
	if (n < 7)
		return (G);
	if (n < 8)
		return (H);
	if (n < 9)
		return (I);
	if (n < 10)
		return (J);
	if (n < 11)
		return (K);
	if (n < 12)
		return (L);
	if (n < 13)
		return (M);
	if (n < 14)
		return (N);
	if (n < 15)
		return (O);
	if (n < 16)
		return (P);
	if (n < 17)
		return (Q);
	if (n < 18)
		return (E);
	if (n < 19)
		return (S);
	if (n < 20)
		return (T);
	if (n < 21)
		return (U);
	if (n < 22)
		return (V);
	if (n < 23)
		return (W);
	if (n < 24)
		return (X);
	if (n < 25)
		return (Y);
	if (n < 26)
		return (Z);
	if (n < 27)
		return (AA);
	if (n < 28)
		return (AB);
	if (n < 29)
		return (AC);
	if (n < 30)
		return (AD);
	else
		return (AE);
	return (0);
}

void	mandelbrot_calculus(t_mlx mlx)
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
				mlx.z_imaginary = 2 * mlx.z_real * mlx.z_imaginary + mlx.c_imaginary;
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

void	mandelbrot_calculus_mouse_move(t_mlx mlx)
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
				mlx.z_imaginary = 2 * mlx.z_real * mlx.z_imaginary + mlx.mandelbrot_c_imaginary;
				mlx.z_real = mlx.z_real_number_2 - mlx.z_imaginary_number_2 + mlx.mandelbrot_c_real;
			}
			put_pixel_in_image(mlx.image, mlx.x, mlx.y, colour(mlx.n));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(&mlx);
}
