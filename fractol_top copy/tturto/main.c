/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:18:16 by tturto            #+#    #+#             */
/*   Updated: 2022/10/16 19:11:32 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void	initiliaze_render(t_container data)
{
	printf("initialize_render\n");
	data.real_factor = (data.real_max - data.real_min) / (WIDTH - 1);
	data.imag_factor = (data.imag_max - data.imag_min) / (HEIGHT - 1);
	if (data.select == 1)
		mandelbrot(data);
	if (data.select == 2)
		mlx_hook(data.win, 6, 0, mouse_events_julia, &data);
	if (data.select == 3)
		tricorn(data);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_container	data;

	printf("main1\n");
	data.select = selected_fractal(argc, argv);
	printf("main2\n");
	data.mlx = mlx_init();
	printf("main3\n");
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	printf("main4\n");
	initialize_min_max_iter(&data);
	printf("main5\n");
	initiliaze_render(data);
	printf("main6\n");
	mlx_mouse_hook(data.win, mouse_zoom, &data);
	printf("main7\n");
	mlx_key_hook(data.win, key_events, &data);
	printf("main8\n");
	mlx_loop(data.mlx);
	printf("mainvika\n");
	return (0);
}
