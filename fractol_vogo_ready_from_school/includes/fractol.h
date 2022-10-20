/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:18:34 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 17:31:29 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 540
# define WIN_HEIGHT 540

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>


# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define BLUE 0x0000FF
# define GRAY 0x808080
# define GREEN 0x008000
# define PURPLE 0x800080
# define RED 0xFF0000
# define ALICEBLUE 0xF0F8FF
# define CORAL 0xFF7F50
# define FIREBRICK 0xB22222
# define HOTPINK 0xFF69B4
# define LEMONCHIFFON 0xFFFACD

# define A 0x201923
# define B 0xffffff
# define C 0xfcff5d
# define D 0x7dfc00
# define E 0x0ec434
# define F 0x228c68
# define G 0x8ad8e8
# define H 0x235b54
# define I 0x29bdab
# define J 0x3998f5
# define K 0x37294f
# define L 0x277da7
# define M 0x3750db
# define N 0xf22020
# define O 0x991919
# define P 0xffcba5
# define Q 0xe68f66
# define R 0xc56133
# define S 0x96341c
# define T 0x632819
# define U 0xffc413
# define V 0xf47a22
# define W 0x2f2aa0
# define X 0xb732cc
# define Y 0x772b9d
# define Z 0xf07cab
# define AA 0xd30b94
# define AB 0xedeff3
# define AC 0xc3a5b4
# define AD 0x946aa2
# define AE 0x5d4c86

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
	void		*mlxptr;
	void		*winptr;
	t_image		*image;

	int					first_round;
	int					fractal_type;
	int					x_offset;
	int					y_offset;

	int					y;
	int					x;
	int					color;
	unsigned int		iterations;

	float				pixel_length_x;
	float				pixel_length_y;

	float				x_axis_min;
	float				x_axis_max;
	float				y_axis_min;
	float				y_axis_max;

	float				constant_y;
	float				constant_x;

	float				z_imaginary;
	//float				z_imaginary;
	float				z_real;
	//float				z_real;

	float				constant_y_julia;
	float				constant_x_julia;
}				t_mlx;

/* --------------------------- Main ----------------------------------------- */

void		print_error(char *reason);
int			check_fractal_type(int ac, char **av);

/* --------------------------- Draw ----------------------------------------- */

void		graphics(t_mlx mlx);
void		menu(t_mlx *mlx);

/* --------------------------- Image ---------------------------------------- */

t_image		*new_image(t_mlx mlx);
t_image		*delete_image(t_mlx mlx, t_image *img);
void		clear_image(t_image *image);
void		color_pixel_in_image(t_image *image, int x, int y, int color);

/* -------------------------- Controls -------------------------------------- */

int			key_event(int key, t_mlx *mlx);
int			mouse_actions(int key, int x, int y, t_mlx *mlx);

/* --------------------- Fractals & Calculus -------------------------------- */

void		mandelbrot_calculus(t_mlx mlx);
void		mandelbrot_calculus_mouse_move(t_mlx mlx);
int			mouse_events_mandelbrot(int x, int y, t_mlx *mlx);

void		optional_fractal_calculus(t_mlx mlx);
void		optional_fractal_calculus_mouse_move(t_mlx mlx);
int			mouse_events_third(int x, int y, t_mlx *mlx);

void		julia_init(t_mlx *mlx);
void		julia_calculus(t_mlx *mlx);
int			mouse_events_julia(int x, int y, t_mlx *mlx);
#endif
