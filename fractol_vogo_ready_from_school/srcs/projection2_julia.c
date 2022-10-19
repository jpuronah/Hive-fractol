/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection2_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:16 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:59:48 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colour_julia(int n)
{
	if (n >= 40)
		return (LEMONCHIFFON);
	if (n < 2)
		return (HOTPINK);
	if (n < 4)
		return (FIREBRICK);
	if (n < 6)
		return (BLUE);
	if (n < 8)
		return (GRAY);
	if (n < 10)
		return (GREEN);
	if (n < 12)
		return (PURPLE);
	if (n < 14)
		return (RED);
	if (n < 16)
		return (ALICEBLUE);
	if (n < 18)
		return (CORAL);
	else
		return (0x000000 << (n % 20));
}

void	julia_calculus(t_mlx *mlx)
{
	clear_image(mlx->image);
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->y < WIN_HEIGHT)
	{
		mlx->c_imaginary = mlx->imaginary_number_max - mlx->y * mlx->zoom_imaginary_number;
		mlx->x = 0;
		while (mlx->x < WIN_WIDTH)
		{
			mlx->c_real = mlx->real_number_min + mlx->x * mlx->zoom_real_number;
			mlx->z_real = mlx->c_real;
			mlx->z_imaginary = mlx->c_imaginary;
			mlx->n = 0;
			while (mlx->n++ < mlx->iterations)
			{
				mlx->z_real_number_2 = mlx->z_real * mlx->z_real;
				mlx->z_imaginary_number_2 = mlx->z_imaginary * mlx->z_imaginary;
				if (mlx->z_real_number_2 + mlx->z_imaginary_number_2 > 4)
					break ;
				mlx->z_imaginary = 2 * mlx->z_real * mlx->z_imaginary + mlx->julia_c_imaginary;
				mlx->z_real = mlx->z_real_number_2 - mlx->z_imaginary_number_2 + mlx->julia_c_real;
			}
			put_pixel_in_image(mlx->image, mlx->x, mlx->y, colour_julia(mlx->n));
			mlx->x++;
		}
		mlx->y++;
	}
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->image->image, 0, 0);
	menu(mlx);
}

int	mouse_events_julia(int x, int y, t_mlx *mlx)
{
	mlx->julia_c_imaginary = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	mlx->julia_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	julia_calculus(mlx);
	return (0);
}
