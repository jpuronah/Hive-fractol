/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:18:34 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 21:55:52 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 400
# define WIN_HEIGHT 400

# include "../libft/libft.h"
# include "../includes/colors.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
//perse
# include <stdio.h>

typedef struct s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			line_bytes;
	int			endian;
}				t_image;

/*
typedef struct s_zoom
{
	float	pixel_length_x;
	float	pixel_length_y;
	float	constant_y_julia;
	float	constant_x_julia;
	float	x_axis_min;
	float	x_axis_max;
	float	y_axis_min;
	float	y_axis_max;
}			t_zoom;
*/

typedef struct s_mlx
{
	void			*mlxptr;
	void			*winptr;
	t_image			*image;

	int				first_round;
	int				fractal_type;
	int				x_offset;
	int				y_offset;

	int				y;
	int				x;
	int				color;
	unsigned int	iterations;

	float			pixel_length_x;
	float			pixel_length_y;

	float			x_axis_min;
	float			x_axis_max;
	float			y_axis_min;
	float			y_axis_max;

	float			constant_y;
	float			constant_x;

	float			z_imaginary;
	//float			z_imaginary;
	float			z_real;
	//float			z_real;
	float			constant_y_julia;
	float			constant_x_julia;
}					t_mlx;

/* ------------------------------- Main ------------------------------------- */

void		print_error(char *reason);
int			check_fractal_type(int ac, char **av);

/* ------------------------------- Draw ------------------------------------- */

void		graphics(t_mlx mlx);
void		menu(t_mlx *mlx);

/* ------------------------------- Image ------------------------------------ */

t_image		*new_image(t_mlx mlx);
t_image		*delete_image(t_mlx mlx, t_image *img);
void		clear_image(t_image *image);
void		color_pixel_in_image(t_image *image, int x, int y, int color);

/* ----------------------------- Controls ----------------------------------- */

int			key_event(int key, t_mlx *mlx);
int			mouse_actions(int key, int x, int y, t_mlx *mlx);

/* ------------------------- Fractals & Calculus ---------------------------- */

void		mandelbrot_calculus(t_mlx mlx);
void		optional_fractal_calculus(t_mlx mlx);
int			julia_coordinates(int x, int y, t_mlx *mlx);

//void		optional_fractal_calculus_mouse_move(t_mlx mlx);
//int			mouse_events_third(int x, int y, t_mlx *mlx);
//void		julia_init(t_mlx *mlx);
//void		julia_calculus(t_mlx *mlx);
//void		julia_calculus(t_mlx *mlx, float a, float b);
//int			mouse_events_mandelbrot(int x, int y, t_mlx *mlx);
//void		mandelbrot_calculus_mouse_move(t_mlx mlx);
#endif
