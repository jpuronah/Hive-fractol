/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:18:34 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/27 08:26:49 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# include "../libft/libft.h"
# include "../includes/colors.h"
# include <mlx.h>
# include <stdio.h>

# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3

typedef struct s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			line_bytes;
	int			endian;
}				t_image;

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
	int				colour;
	unsigned int	iterations;

	float			pixel_length_x;
	float			pixel_length_y;

	float			x_axis_min;
	float			x_axis_max;
	float			y_axis_min;
	float			y_axis_max;

	float			constant_y;
	float			constant_x;

	float			y_pixel;
	float			x_pixel;
	float			constant_y_julia;
	float			constant_x_julia;
}					t_mlx;

/* ------------------------------- Main ------------------------------------- */

void		print_error(char *reason);
int			check_fractal_type(int ac, char **av);

/* ------------------------------- Draw ------------------------------------- */

void		graphics(t_mlx mlx);
void		menu(t_mlx *mlx);

/* ------------------------------ Image ------------------------------------- */

t_image		*new_image(t_mlx *mlx);
void		clear_image(t_image *image);
t_image		*delete_image(t_mlx *mlx, t_image *img);
void		put_pixel_in_image(t_image *image, int x, int y, int color);

/* ----------------------------- Controls ----------------------------------- */

int			key_event(int key, t_mlx *mlx);
int			mouse_actions(int key, int x, int y, t_mlx *mlx);

/* ---------------------------- Fractals ------------------------------------ */

void		mandelbrot_calculus(t_mlx mlx);
void		optional_fractal_calculus(t_mlx mlx);
int			julia_coordinates(int x, int y, t_mlx *mlx);
#endif
