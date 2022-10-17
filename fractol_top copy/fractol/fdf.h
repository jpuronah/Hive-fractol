/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:18:34 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/16 19:05:30 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 600
# define WIN_HEIGHT 450
# define WHITE 0xFFFFFF

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

typedef struct s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vector	**vectors;
}				t_map;

typedef struct s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			line_bytes;
	int			endian;
}				t_image;

typedef struct s_angle
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	double		scale;
}				t_angle;

typedef struct s_mlx
{
	void		*mlxptr;
	void		*winptr;
	int			projection;
	int			end;
	t_map		*map;
	t_angle		*angle;
	t_image		*image;


	float				real_min;
	float				real_max;
	float				imag_min;
	float				imag_max;
	float				real_factor;
	float				imag_factor;
	float				z_real_2;
	float				z_imag_2;
	float				c_imag;
	float				c_real;
	float				z_real;
	float				z_imag;
	float				julia_c_imag;
	float				julia_c_real;
	unsigned short int	select;
	unsigned int		y;
	unsigned int		x;
	unsigned int		n;
	unsigned int		iter;
}				t_mlx;

typedef struct s_line_clip
{
	int			region1;
	int			region2;
	int			drawroutine;
	t_vector	tmp_vec;
}				t_line_clip;

void		print_error(char *reason);

//void		graphics(t_map *map, char *window_title);
void		graphics(t_mlx *mlx);


void		render(t_mlx *mlx);



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

void		menu(t_mlx *mlx);

t_image		*new_image(t_mlx *mlx);
t_image		*delete_image(t_mlx *mlx, t_image *img);
void		clear_image(t_image *image);
void		put_pixel_in_image(t_image *image, int x, int y, int color);

int			key_event(int key, t_mlx *mlx);

int		mouse_zoom(int key, int x, int y, t_mlx *mlx);
int		colour(int n);

void	mandelbrot(t_mlx *mlx);
void	tricorn(t_mlx *mlx);

int		mouse_events_julia(int x, int y, t_mlx *mlx);
void	julia(t_mlx *mlx);
#endif
