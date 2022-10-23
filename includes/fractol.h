/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:18:34 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 13:40:25 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# include "../libft/libft.h"
# include "../includes/colors.h"
# include <mlx.h>

typedef struct s_mlx
{
	void			*mlxptr;
	void			*winptr;

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

/* ----------------------------- Controls ----------------------------------- */

int			key_event(int key, t_mlx *mlx);
int			mouse_actions(int key, int x, int y, t_mlx *mlx);

/* ---------------------------- Fractals ------------------------------------ */

void		mandelbrot_calculus(t_mlx mlx);
void		optional_fractal_calculus(t_mlx mlx);
int			julia_coordinates(int x, int y, t_mlx *mlx);
#endif
