/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_with_prints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:27:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:59:56 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal(t_mlx mlx)
{
	printf("init_fractal (draw initial picture)\n\n\n\n\n\n\n\n\n\n\n\n\n");
	mlx.first_round = 1;
	mlx.zoom_real_number = (mlx.real_number_max - mlx.real_number_min) / (WIN_WIDTH - 1);
	mlx.zoom_imaginary_number = (mlx.imaginary_number_max - mlx.imaginary_number_min) / (WIN_HEIGHT - 1);
	if (mlx.fractal_type == 1)
		mandelbrot_calculus(mlx);
	if (mlx.fractal_type == 2)
		mlx_hook(mlx.winptr, 6, 0, &mouse_events_julia, &mlx);
	if (mlx.fractal_type == 3)
		optional_fractal_calculus(mlx);
}

void	graphics(t_mlx mlx)
{
	printf("graphics\n\n\n\n\n\n\n");
	printf("%d\n", mlx.mouse_move);
	if (mlx.first_round == 0)
		init_fractal(mlx);
	mlx_mouse_hook(mlx.winptr, mouse_actions, &mlx);
	mlx_key_hook(mlx.winptr, key_event, &mlx);
	menu(&mlx);
	mlx_loop(mlx.mlxptr);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:12:21 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:21:13 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_grid_reference(t_mlx *mlx)
{
	printf(" {draw_grid_reference}\n");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, WIN_HEIGHT / 2, WHITE, "This is real -1");
	//mlx_string_put(mlx->mlxptr, mlx->winptr, 20, WIN_HEIGHT / 2, WHITE, "This is real 1");
	//mlx_string_put(mlx->mlxptr, mlx->winptr, 20, WIN_WIDTH / 2, WHITE, "This is complex -1");
	mlx_string_put(mlx->mlxptr, mlx->winptr, WIN_WIDTH / 2, 20, WHITE, "This is complex 1");
}

void	menu(t_mlx *mlx)
{
	printf(" {menu}\n");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 20,
		WHITE, "Press 'ESC' to EXIT PROGRAM");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 40,
		WHITE, "Press 'M' or 'N' to toggle MOUSE_MODE ON / OFF ");
	draw_grid_reference(mlx);
}

static int	exit_fdf(t_mlx *mlx)
{
	printf("exit_fdf\n");
	delete_image(*mlx, mlx->image);
	mlx_destroy_window(mlx->mlxptr, mlx->winptr);
	exit (EXIT_SUCCESS);
}

int	key_event(int key, t_mlx *mlx)
{
	printf("key_event\n");
	printf("KEY: %d\n", key);
	if (key == 53)
	{
		exit_fdf(mlx);
		//mlx_destroy_window(mlx->mlxptr, mlx->winptr);
		//exit(0);
	}
	if (key == 65307)		// HIMASSA TAMA VAIN TOIMII lols
	{
		exit_fdf(mlx);
		//mlx_destroy_window(mlx->mlxptr, mlx->winptr);
		//exit(0);
	}
	/*if (key == 'm')
		mandelbrot_calculus(mlx);
	if (key == 'j')
		julia_init(mlx);
	if (key == 't')
		optional_fractal_init(mlx);*/
	if (key == '+')
		mlx->iterations++;
	if (key == '-')
		mlx->iterations++;
	menu(mlx);
	
	
	// TALLA SEG FAULTTI
	/*
	if (key == 46)
		mlx->mouse_move = 1;
	if (key == 45)
		mlx->mouse_move = 0;
	if (mlx->mouse_move == 1)
		graphics(*mlx);
	if (mlx->mouse_move == 0)
		graphics(*mlx);*/


	//draw_grid_reference(mlx);
	//graphics(*mlx);
	return (0);
}










/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:11 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 18:31:27 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(char *reason)
{
	printf("print_error\n");
	ft_putendl(reason);
	exit(0);
}

int	check_fractal_type(int ac, char **av)
{
	int			fractal_type;

	printf("check_fractal_type\n");
	fractal_type = 0;
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			fractal_type = 1;
		if (ft_strcmp(av[1], "julia") == 0)
			fractal_type = 2;
		if (ft_strcmp(av[1], "third") == 0)
			fractal_type = 3;
	}
	if (ac != 2 || fractal_type == 0)
		print_error("Usage: ./fractol <fractal name> (julia, mandelbrot, XXX)");
	return (fractal_type);
}










/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:43:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:45:36 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_grid_values(t_mlx *mlx, int fractal_type)
{
	printf("set_grid_values (fractal type)\n");
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
	printf("set_calculus_values\n");
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

	printf("init_mlx\n");
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

	printf("main\n");
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












/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:54:44 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:36:19 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_events_mandelbrot(int x, int y, t_mlx *mlx)
{
	//julia_init(mlx);
	printf("\n\n\nmouse_events_mandelbrot\n\n\n");
	printf("x: %d, y: %d\n", x, y);
	mlx->mandelbrot_c_imaginary = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	mlx->mandelbrot_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	printf("varslist: %f, %f, %f, %f\n", mlx->real_number_min, mlx->real_number_max, mlx->imaginary_number_min, mlx->imaginary_number_max);
	//mlx->julia_c_imaginary = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	//mlx->julia_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	mandelbrot_calculus_mouse_move(*mlx);
	//mandelbrot_calculus(*mlx);
	return (0);
}

int	mouse_events_third(int x, int y, t_mlx *mlx)
{
	//julia_init(mlx);
	printf("\n\n\nmouse_events_third\n\n\n");
	printf("x: %d, y: %d\n", x, y);
	mlx->third_c_imaginary = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	mlx->third_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	//mlx->julia_c_imaginary = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	//mlx->julia_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	optional_fractal_calculus_mouse_move(*mlx);
	return (0);
}

static void mouse_zoom(t_mlx *mlx, int key)
{
	printf("mouse_zoom\n");
	if (key == 1)
	{
		mlx->real_number_min = mlx->real_number_min * 0.95;
		mlx->real_number_max = mlx->real_number_max * 0.95;
		mlx->imaginary_number_min = mlx->imaginary_number_min * 0.95;
		mlx->imaginary_number_max = mlx->imaginary_number_max * 0.95;
	}
	if (key == 3)
	{
		mlx->real_number_min *= 1.05;
		mlx->real_number_max *= 1.05;
		mlx->imaginary_number_min *= 1.05;
		mlx->imaginary_number_max *= 1.05;
	}
}

int	mouse_actions(int key, int x, int y, t_mlx *mlx)
{
	printf("mouse_actions\n");
	printf("dadsadsaadsdaskey: %d, x: %d, y: %d\n", key, x, y);
	printf("zooms1 , real: %f, imaginary: %f\n", mlx->zoom_real_number, mlx->zoom_imaginary_number);
	
	// X and Y for click coordinates, could be useful in some cases
	if (x && y)
	{
		x = 0;
		y = 0;
	}
	mouse_zoom(mlx, key);
	mlx->zoom_real_number = (mlx->real_number_max - mlx->real_number_min) / (WIN_WIDTH - 1);
	mlx->zoom_imaginary_number = (mlx->imaginary_number_max - mlx->imaginary_number_min) / (WIN_HEIGHT - 1);
	if (mlx->mouse_move == 1)
	{
		printf("segfault??\n");
		exit(0);
		if (mlx->fractal_type == 1)
			mlx_hook(mlx->winptr, 6, 0, mouse_events_mandelbrot, &mlx);
		if (mlx->fractal_type == 2)
			mlx_hook(mlx->winptr, 6, 0, &mouse_events_julia, &mlx);
		if (mlx->fractal_type == 3)
			mlx_hook(mlx->winptr, 6, 0, mouse_events_third, &mlx);
	}
	else
	{
		if (mlx->fractal_type == 1)
			mandelbrot_calculus(*mlx);
		if (mlx->fractal_type == 2)
			mlx_hook(mlx->winptr, 6, 0, &mouse_events_julia, &mlx);
		if (mlx->fractal_type == 3)
			optional_fractal_calculus(*mlx);
	}
	return (0);
}





/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection1_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:42:56 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:43:24 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
static int	colour(int n)
{
	if (n >= 25)
		return (0x000000);
	if (n < 5)
		return (0x005500);
	if (n < 7)
		return (0x006600);
	if (n < 9)
		return (0x007700);
	if (n < 2)
		return (0x008800);
	if (n < 11)
		return (0x009900);
	if (n < 13)
		return (0x00AA00);
	if (n < 15)
		return (0x00BB00);
	if (n < 17)
		return (0x00CC00);
	if (n < 19)
		return (0x00DD00);
	if (n < 21)
		return (0x00EE00);
	else
		return (0xFFFFFF);
	return (0);
}*/

static int	colour(int n)
{
	if (n >= 25)
		return (LEMONCHIFFON);
	if (n < 5)
		return (HOTPINK);
	if (n < 7)
		return (FIREBRICK);
	if (n < 9)
		return (BLUE);
	if (n < 2)
		return (GRAY);
	if (n < 11)
		return (GREEN);
	if (n < 13)
		return (PURPLE);
	if (n < 15)
		return (RED);
	if (n < 17)
		return (ALICEBLUE);
	if (n < 19)
		return (CORAL);
	if (n < 21)
		return (WHITE);
	else
		return (BLACK);
	return (0);
}

void	mandelbrot_calculus(t_mlx mlx)
{
	printf("mandelbrot_calculus\n");
	printf("varslist: %f, %f, %f, %f\n", mlx.real_number_min, mlx.real_number_max, mlx.imaginary_number_min, mlx.imaginary_number_max);
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
	printf("mandelbrot_calculus\n");
	printf("varslist: %f, %f, %f, %f\n", mlx.real_number_min, mlx.real_number_max, mlx.imaginary_number_min, mlx.imaginary_number_max);
	clear_image(mlx.image);
	mlx.x = 0;
	mlx.y = 0;
	write(1, "|", 1);
	write(1, "\n", 1);
	while (mlx.y < WIN_HEIGHT)
	{
		write(1, "|", 1);
		write(1, "\n", 1);
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

/*
void	mandelbrot_init(t_mlx *mlx)
{
	printf("mandelbrot_init\n");
	printf("f_round: %d\n", mlx->first_round);
	//mlx->first_round = 1;
	
	
	mlx->iterations = 50;
	mlx->real_number_min = -2;
	mlx->real_number_max = 1;
	mlx->imaginary_number_min = -1.3;
	mlx->imaginary_number_max = 1.3;
	mlx->zoom_real_number = (mlx->real_number_max - mlx->real_number_min) / (WIN_WIDTH - 1);
	mlx->zoom_imaginary_number = (mlx->imaginary_number_max - mlx->imaginary_number_min) / (WIN_HEIGHT - 1);


	
	mlx->zoom_real_number = (mlx->real_number_max - mlx->real_number_min) / (WIN_WIDTH - 1);
	mlx->zoom_imaginary_number = (mlx->imaginary_number_max - mlx->imaginary_number_min) / (WIN_HEIGHT - 1);
	printf("varslist: %d, %f, %f, %f, %f\n", mlx->iterations, mlx->real_number_min, mlx->real_number_max, mlx->imaginary_number_min, mlx->imaginary_number_max);
	printf("zooms_init, real: %f, imaginary: %f\n", mlx->zoom_real_number, mlx->zoom_imaginary_number);
	mandelbrot_calculus(mlx);
}
*/










/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection2_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:16 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:43:33 by jpuronah         ###   ########.fr       */
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

/*
int	colour_julia(int n)
{
	if (n >= 40)
		return (0x00FF00);
	if (n < 2)
		return (0x220000);
	if (n < 4)
		return (0x440000);
	if (n < 6)
		return (0x660000);
	if (n < 8)
		return (0x880000);
	if (n < 10)
		return (0xAA0000);
	if (n < 12)
		return (0xBB0000);
	if (n < 14)
		return (0xCC0000);
	if (n < 16)
		return (0xDD0000);
	if (n < 18)
		return (0xFF0000);
	else
		return (0x000000 << (n % 20));
}*/

void	julia_calculus(t_mlx *mlx)
{
	printf("julia\n");
	printf("varslist: %f, %f, %f, %f\n", mlx->real_number_min, mlx->real_number_max, mlx->imaginary_number_min, mlx->imaginary_number_max);
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

/*void	julia_init(t_mlx *mlx)
{
	mlx->iterations = 80;
	mlx->real_number_min = -2;
	mlx->real_number_max = 2;
	mlx->imaginary_number_min = -2;
	mlx->imaginary_number_max = 2;
	mlx->zoom_real_number = (mlx->real_number_max - mlx->real_number_min) / (WIN_WIDTH - 1);
	mlx->zoom_imaginary_number = (mlx->imaginary_number_max - mlx->imaginary_number_min) / (WIN_HEIGHT - 1);
}*/

int	mouse_events_julia(int x, int y, t_mlx *mlx)
{
	//julia_init(mlx);
	printf("\n\n\nmouse_events_julia\n\n\n");
	printf("x: %d, y: %d\n", x, y);
	mlx->julia_c_imaginary = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	mlx->julia_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	julia_calculus(mlx);
	return (0);
}










/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:52 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:44:25 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static int	colour(int n)
{
	if (n >= 25)
		return (0x000000);
	if (n < 5)
		return (0x005500);
	if (n < 7)
		return (0x006600);
	if (n < 9)
		return (0x007700);
	if (n < 2)
		return (0x008800);
	if (n < 11)
		return (0x009900);
	if (n < 13)
		return (0x00AA00);
	if (n < 15)
		return (0x00BB00);
	if (n < 17)
		return (0x00CC00);
	if (n < 19)
		return (0x00DD00);
	if (n < 21)
		return (0x00EE00);
	else
		return (0xFFFFFF);
	return (0);
}*/

static int	colour(int n)
{
	if (n >= 25)
		return (LEMONCHIFFON);
	if (n < 5)
		return (HOTPINK);
	if (n < 7)
		return (FIREBRICK);
	if (n < 9)
		return (BLUE);
	if (n < 2)
		return (GRAY);
	if (n < 11)
		return (GREEN);
	if (n < 13)
		return (PURPLE);
	if (n < 15)
		return (RED);
	if (n < 17)
		return (ALICEBLUE);
	if (n < 19)
		return (CORAL);
	if (n < 21)
		return (WHITE);
	else
		return (BLACK);
	return (0);
}

void	optional_fractal_calculus(t_mlx mlx)
{
	printf("optional fractal calculus\n");
	clear_image(mlx.image);
	printf("%d, %d\n", mlx.y, mlx.x);
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
				mlx.z_imaginary = -2 * mlx.z_real * mlx.z_imaginary + mlx.c_imaginary;
				mlx.z_real = mlx.z_real_number_2 - mlx.z_imaginary_number_2 + mlx.c_real;
			}
			//mlx_pixel_put(mlx.mlxptr, mlx.winptr, mlx.x, mlx.y, colour(mlx.n));
			put_pixel_in_image(mlx.image, mlx.x, mlx.y, colour(mlx.n));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(&mlx);
}

void	optional_fractal_calculus_mouse_move(t_mlx mlx)
{
	printf("optional fractal calculus\n");
	clear_image(mlx.image);
	printf("%d, %d\n", mlx.y, mlx.x);
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
				mlx.z_imaginary = -2 * mlx.z_real * mlx.z_imaginary + mlx.third_c_imaginary;
				mlx.z_real = mlx.z_real_number_2 - mlx.z_imaginary_number_2 + mlx.third_c_real;
			}
			//mlx_pixel_put(mlx.mlxptr, mlx.winptr, mlx.x, mlx.y, colour(mlx.n));
			put_pixel_in_image(mlx.image, mlx.x, mlx.y, colour(mlx.n));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(&mlx);
}

void	optional_fractal_init(t_mlx mlx)
{
	//mlx.iterations = 50;
	mlx.real_number_min = -2;
	mlx.real_number_max = 1;
	mlx.imaginary_number_min = -1.3;
	mlx.imaginary_number_max = 1.3;
	mlx.zoom_real_number = (mlx.real_number_max - mlx.real_number_min) / (WIN_WIDTH - 1);
	mlx.zoom_imaginary_number = (mlx.imaginary_number_max - mlx.imaginary_number_min) / (WIN_HEIGHT - 1);
	optional_fractal_calculus(mlx);
}


/*void	optional_fractal_calculus(t_mlx *mlx)
{
	printf("optional fractal calculus\n");
	clear_image(mlx->image);
	printf("%d, %d\n", mlx->y, mlx->x);
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
				mlx->z_imaginary = -2 * mlx->z_real * mlx->z_imaginary + mlx->c_imaginary;
				mlx->z_real = mlx->z_real_number_2 - mlx->z_imaginary_number_2 + mlx->c_real;
			}
			//mlx_pixel_put(mlx->mlxptr, mlx->winptr, mlx->x, mlx->y, colour(mlx->n));
			put_pixel_in_image(mlx->image, mlx->x, mlx->y, colour(mlx->n));
			mlx->x++;
		}
		mlx->y++;
	}
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->image->image, 0, 0);
	menu(mlx);
}
*/