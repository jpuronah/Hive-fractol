/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection2_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:16 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 12:03:20 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Iterations measure, how fast the single
**	pixel value will 'blow up' towards infinity
*/
static void	run_fractal_equation_julia(t_mlx *mlx)
{
	float	tmp;

	tmp = 0.0;
	while (mlx->colour++ < mlx->iterations)
	{
		tmp = mlx->y_pixel;
		mlx->y_pixel = 2 * mlx->x_pixel * mlx->y_pixel + mlx->constant_y_julia;
		mlx->x_pixel = (mlx->x_pixel * mlx->x_pixel) - (tmp * tmp) + mlx->constant_x_julia;
		if (((mlx->x_pixel * mlx->x_pixel) + 
			(mlx->y_pixel * mlx->y_pixel)) > 8)
			break ;
	}
}

void	julia_calculus(t_mlx *mlx)
{
	clear_image(mlx->image);
	mlx->y = 0;
	mlx->x = 0;
	while (mlx->y < WIN_HEIGHT)
	{
		mlx->x = 0;
		mlx->constant_y = mlx->y_axis_min + mlx->y * mlx->pixel_length_y;
		while (mlx->x < WIN_WIDTH)
		{
			mlx->constant_x = mlx->x_axis_min + mlx->x * mlx->pixel_length_x;
			mlx->x_pixel = mlx->constant_x;
			mlx->y_pixel = mlx->constant_y;
			mlx->colour = 0;
			run_fractal_equation_julia(mlx);
			color_pixel_in_image(mlx->image, mlx->x, mlx->y, set_colour(mlx->colour));
			mlx->x++;
		}
		mlx->y++;
	}
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->image->image, 0, 0);
	menu(mlx);
}

int	julia_coordinates(int x, int y, t_mlx *mlx)
{
	mlx->constant_x_julia = 0.0;
	mlx->constant_y_julia = 0.0;
	if ((x > 0 && x < WIN_WIDTH) && (y > 0 && y < WIN_HEIGHT))
	{
		mlx->constant_y_julia = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
		mlx->constant_x_julia = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	}
	julia_calculus(mlx);
	return (0);
}

