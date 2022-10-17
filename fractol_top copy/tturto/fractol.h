/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:16:36 by tturto            #+#    #+#             */
/*   Updated: 2022/10/15 18:38:40 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# define WIDTH 600
# define HEIGHT 450

typedef struct s_struct
{
	void				*mlx;
	void				*win;
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
	unsigned int		y;
	unsigned int		x;
	unsigned int		n;
	unsigned int		iter;
	unsigned short int	select;
}	t_container;

void	initialize_min_max_iter(t_container *data);
int		key_events(int key, t_container *data);
int		colour(int n);
int		c_julia(int n);
int		mouse_events_julia(int x, int y, t_container *data);
int		mouse_zoom(int key, int x, int y, t_container *data);
void	mandelbrot(t_container data);
void	julia(t_container data);
void	tricorn(t_container data);

#endif
