/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:43:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:58:15 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_grid_values(t_mlx *mlx, int fractal_type)
{
	if (fractal_type == 2)
	{
		mlx->iterations = 80;
		mlx->real_number_min = -2;
		mlx->real_number_max = 2;
		mlx->imaginary_number_min = -2;
		mlx->imaginary_number_max = 2;
	}
	else
	{
		mlx->iterations = 50;
		mlx->real_number_min = -2;
		mlx->real_number_max = 1;
		mlx->imaginary_number_min = -1.3;
		mlx->imaginary_number_max = 1.3;
	}
}

static void	set_calculus_values(t_mlx mlx)
{
	mlx.z_real_number_2 = 0;
	mlx.z_imaginary_number_2 = 0;
	mlx.c_imaginary = 0;
	mlx.z_imaginary = 0;
	mlx.c_real = 0;
	mlx.z_real = 0;
	mlx.julia_c_imaginary = 0;
	mlx.julia_c_real = 0;
}

static t_mlx	init_mlx(char *win_title, int fractal_type)
{
	t_mlx	mlx;

	mlx.mlxptr = mlx_init();
	mlx.winptr = mlx_new_window(mlx.mlxptr, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	mlx.image = new_image(mlx);
	mlx.fractal_type = fractal_type;
	mlx.first_round = 0;
	mlx.x = 0;
	mlx.y = 0;
	mlx.n = 0;
	mlx.mouse_move = 0;
	set_grid_values(&mlx, fractal_type);
	mlx.zoom_real_number = (mlx.real_number_max - mlx.real_number_min) / (WIN_WIDTH - 1);
	mlx.zoom_imaginary_number = (mlx.imaginary_number_max - mlx.imaginary_number_min) / (WIN_HEIGHT - 1);
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
