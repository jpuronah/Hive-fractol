/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection2_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:16 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 17:34:08 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
int	set_colour_julia(int color)
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
}*/

static int	set_colour_julia(int color)
{
	if (color >= 40)
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

/*while (mlx->color++ < mlx->iterations)
			{
				mlx->z_real_number_2 = mlx->z_real * mlx->z_real;
				mlx->z_imaginary_number_2 = mlx->z_imaginary * mlx->z_imaginary;
				if (mlx->z_real_number_2 + mlx->z_imaginary_number_2 > 4)
					break ;
				mlx->z_imaginary = 2 * mlx->z_real * mlx->z_imaginary + mlx->julia_c_imaginary;		//Tämä on mouse_move_c value 
				mlx->z_real = mlx->z_real_number_2 - mlx->z_imaginary_number_2 + mlx->julia_c_real;	//Tämä myös
			}						*/

static void	run_fractal_equation_julia(t_mlx *mlx)
{
	float	tmp;

	tmp = 0.0;
	while (mlx->color++ < mlx->iterations)
	{
		tmp = mlx->z_imaginary;

		//mlx->z_real_number_2 = mlx->z_real * mlx->z_real;
		//mlx->z_imaginary_number_2 = mlx->z_imaginary * mlx->z_imaginary;
		mlx->z_imaginary = 2 * mlx->z_real * mlx->z_imaginary + mlx->constant_y_julia;
		mlx->z_real = (mlx->z_real * mlx->z_real) - (tmp * tmp) + mlx->constant_x_julia;
		//mlx->z_real = (mlx->z_real * mlx->z_real) - mlx->z_imaginary_number_2 + mlx->constant_x_julia;
		if (((mlx->z_real * mlx->z_real) + 
			(mlx->z_imaginary * mlx->z_imaginary)) > 4)
			break ;
		//if (mlx->z_real_number_2 + mlx->z_imaginary_number_2 > 4)
		//	break ;
	}
	/*float	tmp;

	tmp = 0.0;
	while (mlx->color++ < mlx->iterations)
	{
		tmp = mlx->z_imaginary;
		mlx->z_imaginary = 2 * mlx->z_real * mlx->z_imaginary + mlx->constant_y;
		mlx->z_real = (mlx->z_real * mlx->z_real) - (tmp * tmp) + mlx->constant_x;
		if (((mlx->z_real * mlx->z_real) + 
			(mlx->z_imaginary * mlx->z_imaginary)) > 4)
			break ;
	}*/
}


void	julia_calculus(t_mlx *mlx)
{
	clear_image(mlx->image);
	//mlx->x = 0;
	mlx->y = 0;
	while (mlx->y < WIN_HEIGHT)
	{
		mlx->x = 0;
		//mlx->constant_y = mlx->y_axis_max - mlx->y * mlx->pixel_length_y;
		mlx->constant_y = mlx->y_axis_min + mlx->y * mlx->pixel_length_y;
		while (mlx->x < WIN_WIDTH)
		{
			mlx->constant_x = mlx->x_axis_min + mlx->x * mlx->pixel_length_x;
			mlx->z_real = mlx->constant_x;
			mlx->z_imaginary = mlx->constant_y;
			mlx->color = 0;
			run_fractal_equation_julia(&*mlx);																				//mlx->mouse_imaginary;*/
			color_pixel_in_image(mlx->image, mlx->x, mlx->y, set_colour_julia(mlx->color));					//mlx->mouse_real; ??!?!?
			mlx->x++;
		}
		mlx->y++;
	}
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->image->image, 0, 0);
	menu(mlx);
}

int	mouse_events_julia(int x, int y, t_mlx *mlx)
{
	mlx->constant_y_julia = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	mlx->constant_x_julia = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	julia_calculus(mlx);
	return (0);
}
