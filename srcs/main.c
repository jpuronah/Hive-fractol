/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:43:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/23 18:25:48 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_axis_min_max(t_mlx *mlx, int fractal_type)
{
	if (fractal_type == 2)
	{
		mlx->iterations = 1111;
		mlx->x_axis_min = -2.0;
		mlx->x_axis_max = 2.0;
		mlx->y_axis_min = -2.0;
		mlx->y_axis_max = 2.0;
	}
	else
	{
		mlx->iterations = 55;
		mlx->x_axis_min = -2.0;
		mlx->x_axis_max = 2.0;
		mlx->y_axis_min = -1.3;
		mlx->y_axis_max = 1.3;
	}
}

static void	init_calculus(t_mlx *mlx)
{
	mlx->constant_x = 0.0;
	mlx->constant_y = 0.0;
	mlx->x_pixel = 0.0;
	mlx->y_pixel = 0.0;
	mlx->constant_x_julia = 0.0;
	mlx->constant_y_julia = 0.0;
	mlx->pixel_length_x = (mlx->x_axis_max - mlx->x_axis_min) / (WIN_WIDTH - 1);
	mlx->pixel_length_y = (mlx->y_axis_max - mlx->y_axis_min) / (WIN_HEIGHT - 1);
}


static void	set_variables(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->first_round = 0;
	mlx->colour = 0;
	mlx->x_offset = 0;
	mlx->y_offset = 0;
}

static t_mlx	init_mlx(int fractal_type)
{
	t_mlx	mlx;

	mlx.mlxptr = mlx_init();
	//if (mlx.mlxptr == NULL)
	//	print_error("Could not initialize mlx pointer");
	mlx.winptr = mlx_new_window(mlx.mlxptr, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	//if (mlx.winptr == NULL)
	//	print_error("Could not initialize mlx window pointer");
	mlx.image = new_image(&mlx);
	//if (mlx.image == NULL)
	//	print_error("Could not initialize image pointer");
	mlx.fractal_type = fractal_type;
	mlx.fractal_type = fractal_type;
	mlx.x = 0;
	mlx.y = 0;
	mlx.first_round = 0;
	mlx.colour = 0;
	mlx.x_offset = 0;
	mlx.y_offset = 0;
	set_variables(&mlx);
	set_axis_min_max(&mlx, fractal_type);
	init_calculus(&mlx);
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
		mlx = init_mlx(fractal_type);
		graphics(mlx);
	}
	else
		print_error("Usage: ./fractol <fractal name> \
			(julia, mandelbrot, tricorn)");
	return (0);
}
