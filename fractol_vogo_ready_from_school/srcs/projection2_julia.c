/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection2_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:16 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 16:47:16 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colour_julia(int color)
{
	if (color >= 40)
		return (LEMONCHIFFON);
	if (color < 2)
		return (HOTPINK);
	if (color < 4)
		return (FIREBRICK);
	if (color < 6)
		return (BLUE);
	if (color < 8)
		return (GRAY);
	if (color < 10)
		return (GREEN);
	if (color < 12)
		return (PURPLE);
	if (color < 14)
		return (RED);
	if (color < 16)
		return (ALICEBLUE);
	if (color < 18)
		return (CORAL);
	else
		return (0x000000 << (color % 20));
}

void	julia_calculus(t_mlx *mlx)
{
	clear_image(mlx->image);
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->y < WIN_HEIGHT)
	{
		mlx->c_imaginary = mlx->y_axis_max - mlx->y * mlx->pixel_length_y;
		mlx->x = 0;
		while (mlx->x < WIN_WIDTH)
		{
			mlx->c_real = mlx->x_axis_min + mlx->x * mlx->pixel_length_x;
			mlx->z_real = mlx->c_real;
			mlx->z_imaginary = mlx->c_imaginary;
			mlx->color = 0;
			while (mlx->color++ < mlx->iterations)
			{
				mlx->z_real_number_2 = mlx->z_real * mlx->z_real;
				mlx->z_imaginary_number_2 = mlx->z_imaginary * mlx->z_imaginary;
				if (mlx->z_real_number_2 + mlx->z_imaginary_number_2 > 4)
					break ;
				mlx->z_imaginary = 2 * mlx->z_real * mlx->z_imaginary + mlx->julia_c_imaginary;		//Tämä on mouse_move_c value 
				mlx->z_real = mlx->z_real_number_2 - mlx->z_imaginary_number_2 + mlx->julia_c_real;	//Tämä myös
			}																						//mlx->mouse_imaginary;
			color_pixel_in_image(mlx->image, mlx->x, mlx->y, colour_julia(mlx->color));					//mlx->mouse_real; ??!?!?
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
