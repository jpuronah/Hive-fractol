/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:18:34 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/19 23:39:01 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
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


# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
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
typedef struct s_fractal
{

}					t_fractal;*/

typedef struct s_mlx
{
	void		*mlxptr;
	void		*winptr;
	int			projection;
	int			end;
	t_image		*image;

	int					fractal_type;
	int					first_round;

	unsigned int		iterations;
	float				real_number_min;
	float				real_number_max;
	float				imaginary_number_min;
	float				imaginary_number_max;

	float				zoom_real_number;		// ZOOM X ASKELI
	float				zoom_imaginary_number;	// ZOOM Y AKSELI

	float				z_imaginary_number_2;
	float				z_real_number_2;
	float				c_imaginary;
	float				z_imaginary;
	float				c_real;
	float				z_real;
	float				julia_c_imaginary;
	float				julia_c_real;

	float				mandelbrot_c_imaginary;
	float				mandelbrot_c_real;

	float				third_c_imaginary;
	float				third_c_real;

	unsigned int		y;
	unsigned int		x;
	unsigned int		n;

	int					mouse_move;
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
void		put_pixel_in_image(t_image *image, int x, int y, int color);

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













/*int			cohen_sutherland_lineclip(t_vector *vector1, t_vector *vector2);

t_vector	vector_list(t_mlx *mlx, int x, int y);
t_vector	set_projection_1(t_vector two_d, t_mlx *mlx);
t_vector	set_projection_2_and_0(t_vector two_d, t_mlx *mlx);

void		read_and_save_map(int fd, t_mlx *mlx);

t_map		*init_map(void);
void		check_line(char *line, t_mlx *mlx);
void		map_depth(t_map *map);
char		*save_save(char *save, char *line);
t_map		*vectors_for_map(char *save, t_map *map);

double		ft_abs_db(double i);
double		ft_max_double(double a, double b);
double		calculate_delta(t_vector vec1, t_vector vec2, int letter);
void		finish_line_and_one_point(t_vector vec1, t_vector end, t_mlx *mlx);
int			delete_save_and_map(char *save, t_map **map);
*/