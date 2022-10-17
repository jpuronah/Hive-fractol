/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:43:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/16 20:51:37 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *reason)
{
	ft_putendl(reason);
	exit(EXIT_FAILURE);
}

static t_mlx	init_mlx(char *win_title)
{
	t_mlx	mlx;

	mlx.mlxptr = mlx_init();
	mlx.winptr = mlx_new_window(mlx.mlxptr, WIN_WIDTH, WIN_HEIGHT, win_title);
	mlx.image = new_image(&mlx);

	mlx.real_factor = (mlx.real_max - mlx.real_min) / (WIN_WIDTH - 1);
	mlx.imag_factor = (mlx.imag_max - mlx.imag_min) / (WIN_HEIGHT - 1);

	if (mlx.select == 2)
	{
		mlx.iter = 80;
		mlx.real_min = -2;
		mlx.real_max = 2;
		mlx.imag_min = -2;
		mlx.imag_max = 2;
	}
	else
	{
		mlx.iter = 50;
		mlx.real_min = -2;
		mlx.real_max = 1;
		mlx.imag_min = -1.3;
		mlx.imag_max = 1.3;
	}
	return (mlx);
}

static int	selected_fractal(int argc, char **argv)
{
	unsigned short int	select;

	if (argc != 2 || (ft_strncmp(argv[1], "mandelbrot", 11) != 0
			&& ft_strncmp(argv[1], "julia", 6) != 0
			&& ft_strncmp(argv[1], "tricorn", 8) != 0))
	{
		ft_putstr("Usage: send one argument for the program. ");
		ft_putstr("Argument must be one of the following:\n");
		ft_putstr("mandelbrot\njulia\ntricorn\n");
		exit (0);
	}
	select = 0;
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		select = 1;
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		select = 2;
	if (ft_strncmp(argv[1], "tricorn", 8) == 0)
		select = 3;
	return (select);
}

static void	initiliaze_render(t_mlx mlx)
{
	printf("initialize_render\n");
	mlx.real_factor = (mlx.real_max - mlx.real_min) / (WIN_WIDTH - 1);
	mlx.imag_factor = (mlx.imag_max - mlx.imag_min) / (WIN_HEIGHT - 1);
	printf("%f, %f, %f, %f, %f, %f\n", mlx.real_min, mlx.real_max, mlx.imag_min, mlx.imag_max, mlx.real_factor, mlx.imag_factor);
	if (mlx.select == 1)
		mandelbrot(&mlx);
	if (mlx.select == 2)
		mlx_hook(mlx.winptr, 6, 0, mouse_events_julia, &mlx);
		//julia(&mlx);
	if (mlx.select == 3)
		tricorn(&mlx);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;

	mlx = init_mlx(av[1]);
	mlx.select = selected_fractal(ac, av);
	if (ac == 2)
	{
		initiliaze_render(mlx);
		mlx_mouse_hook(mlx.winptr, mouse_zoom, &mlx);
		mlx_loop(mlx.mlxptr);
		//graphics(&mlx);
	}
	else
		print_error("error: wrong number of arguments");
	return (0);
}
