/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:43:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 12:06:23 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_grid_values(t_mlx *mlx, int fractal_type)
{
	if (fractal_type == 2)
	{
		mlx->iterations = 22;
		mlx->x_axis_min = -2;
		mlx->x_axis_max = 2;
		mlx->y_axis_min = -2;
		mlx->y_axis_max = 2;
	}
	else
	{
		mlx->iterations = 22;
		mlx->x_axis_min = -2;
		mlx->x_axis_max = 1;
		mlx->y_axis_min = -1.12;
		mlx->y_axis_max = 1.12;
	}
}

static void	set_calculus_values(t_mlx mlx)
{
	mlx.constant_y = 0;
	mlx.y_pixel = 0;
	mlx.constant_x = 0;
	mlx.x_pixel = 0;
	mlx.constant_y_julia = 0;
	mlx.constant_x_julia = 0;
}

static t_mlx	init_mlx(char *win_title, int fractal_type)
{
	t_mlx	mlx;

	mlx.mlxptr = mlx_init();
	mlx.winptr = mlx_new_window(mlx.mlxptr, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	mlx.image = new_image(mlx);
	mlx.fractal_type = fractal_type;
	mlx.x = 0;
	mlx.y = 0;
	mlx.first_round = 0;
	mlx.colour = 0;
	mlx.x_offset = 0;
	mlx.y_offset = 0;
	set_grid_values(&mlx, fractal_type);
	mlx.pixel_length_x = (mlx.x_axis_max - mlx.x_axis_min) / (WIN_WIDTH - 1);
	mlx.pixel_length_y = (mlx.y_axis_max - mlx.y_axis_min) / (WIN_HEIGHT - 1);
	set_calculus_values(mlx);
	return (mlx);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	int			fractal_type;

	fractal_type = 0;
	if (ac == 2)
	{
		fractal_type = check_fractal_type(ac, av);
		mlx = init_mlx(av[1], fractal_type);
		graphics(mlx);
	}
	else
		print_error("Usage: ./fractol <fractal name> (julia, mandelbrot, XXX)");
	return (0);
}
