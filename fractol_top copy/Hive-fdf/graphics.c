/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:27:13 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/16 20:57:07 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colour(int n)
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
}

int	mouse_zoom(int key, int x, int y, t_mlx *mlx)
{
	if (x && y)
	{
		printf("x ja yy\n");
		x = 0;
		y = 0;
	}
	printf("%d\n", key);

	if (key == 1)	//YLÖS
	{
		mlx->real_min = mlx->real_min * 0.95;
		mlx->real_max = mlx->real_max * 0.95;
		mlx->imag_min = mlx->imag_min * 0.95;
		mlx->imag_max = mlx->imag_max * 0.95;
	}
	if (key == 3)	//ALAS
	{
		mlx->real_min = mlx->real_min * 1.05;
		mlx->real_max = mlx->real_max * 1.05;
		mlx->imag_min = mlx->imag_min * 1.05;
		mlx->imag_max = mlx->imag_max * 1.05;
	}
	/*if (key == 1)	//YLÖS
	{
		mlx->real_min = mlx->real_min * 1.0;
		mlx->real_max = mlx->real_max * 1.0;
		mlx->imag_min = mlx->imag_min * 1.0;
		mlx->imag_max = mlx->imag_max * 1.0;
	}
	if (key == 3)	//ALAS
	{
		mlx->real_min = mlx->real_min * 1.0;
		mlx->real_max = mlx->real_max * 1.0;
		mlx->imag_min = mlx->imag_min * 1.0;
		mlx->imag_max = mlx->imag_max * 1.0;
	}*/
	mlx->real_factor = (mlx->real_max - mlx->real_min) / (WIN_WIDTH - 1);
	mlx->imag_factor = (mlx->imag_max - mlx->imag_min) / (WIN_HEIGHT - 1);
	printf("%f, %f, %f, %f, %f, %f\n", mlx->real_min, mlx->real_max, mlx->imag_min, mlx->imag_max, mlx->real_factor, mlx->imag_factor);
	//mandelbrot(mlx);
	if (mlx->select == 1)
	{
		printf("mandel\n");
		mandelbrot(mlx);
	}
	if (mlx->select == 2)
	{
		printf("julli\n");
		mouse_events_julia(x, y, mlx);
		mlx_hook(mlx->winptr, 5, 0, &mouse_events_julia, mlx);
	}
	if (mlx->select == 3)
	{
		printf("tri\n");
		tricorn(mlx);
	}
	return (0);
}

void	graphics(t_mlx *mlx)
{
	/*t_mlx	*mlx;

	mlx = malloc_mlx();
	if (mlx == NULL)
		print_error("Error: Cannot initialize mlx");*/
	//mlx_key_hook(mlx->winptr, key_event, mlx);
	//menu(mlx);
	//printf("%d\n", mlx->select);
	mlx_mouse_hook(mlx->winptr, mouse_zoom, mlx);
	mlx_loop(mlx->mlxptr);
}












/*
static t_mlx	*malloc_mlx()
{
	t_mlx	*mlx;

	mlx = NULL;
	mlx = ft_memalloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlxptr = mlx_init();
	mlx->winptr = mlx_new_window(mlx->mlxptr, WIN_WIDTH, WIN_HEIGHT, win_title);
	mlx->image = new_image(mlx);
	mlx->projection = 1;
	mlx->end = 1;
	mlx->angle = ft_memalloc(sizeof(t_angle));
	if (mlx->image == NULL || mlx->angle == NULL == NULL
		|| mlx->mlxptr == NULL || mlx->winptr == NULL)
		return (NULL);
	mlx->angle->x = 0.52359;
	mlx->angle->y = 0.52359;
	mlx->angle->scale = 16;
	mlx->angle->offsetx = WIN_WIDTH / 2;
	mlx->angle->offsety = WIN_HEIGHT / 2;
	return (mlx);
}

static t_vector	shift_view(t_vector vector, t_mlx *mlx)
{
	if (mlx->projection == 1)
		vector = set_projection_1(vector, mlx);
	else
		vector = set_projection_2_and_0(vector, mlx);
	vector.x *= mlx->angle->scale;
	vector.y *= mlx->angle->scale;
	vector.x += mlx->angle->offsetx;
	vector.y += mlx->angle->offsety;
	return (vector);
}

static void	draw(t_mlx *mlx, t_vector vec1, t_vector vec2)
{
	double		delta_x;
	double		delta_y;

	vec1 = shift_view(vec1, mlx);
	vec2 = shift_view(vec2, mlx);
	delta_x = calculate_delta(vec1, vec2, 1);
	delta_y = calculate_delta(vec1, vec2, 2);
	if (!cohen_sutherland_lineclip(&vec1, &vec2))
		return ;
	while (((int)(vec1.x - round(vec2.x)) || (int)(vec1.y - round(vec2.y))))
	{
		if (vec1.x > WIN_WIDTH || vec1.y > WIN_HEIGHT
			|| vec1.y < 0 || vec1.x < 0)
			break ;
		put_pixel_in_image(mlx->image,
			(int)round(vec1.x), (int)round(vec1.y), 0xFFFFFF);
		vec1.x += delta_x;
		vec1.y += delta_y;
	}
	if (ft_abs_db(round(vec2.x) - vec1.x) < delta_x
		|| ft_abs_db(round(vec2.y) - vec1.y) < delta_y
		|| (mlx->map->width == 1 && mlx->map->height == 1))
		finish_line_and_one_point(vec1, vec2, mlx);
}

void	render(t_mlx *mlx)
{
	t_vector	vec;
	int			x;
	int			y;

	clear_image(mlx->image);
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			vec = vector_list(mlx, x, y);
			if (x + 1 < mlx->map->width)
				draw(mlx, vec, vector_list(mlx, x + 1, y));
			if (y + 1 < mlx->map->height)
				draw(mlx, vec, vector_list(mlx, x, y + 1));
			if (mlx->map->width == 1 && mlx->map->height == 1)
				draw(mlx, vec, vec);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->image->image, 0, 0);
}*/
