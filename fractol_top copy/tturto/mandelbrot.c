/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:20:56 by tturto            #+#    #+#             */
/*   Updated: 2022/10/15 22:24:18 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	z = z^2 + c
	Mandelbrot z-value is within boundaries of {(-2, 2), (-2, 2)}. The value
	represents the distance of 0 + 0i.
*/
void	mandelbrot(t_container data)
{
	printf("mandelbrot\n");
	while (data.y < HEIGHT)
	{
		data.c_imag = data.imag_max - data.y * data.imag_factor;
		data.x = 0;
		while (data.x < WIDTH)
		{
			data.c_real = data.real_min + data.x * data.real_factor;
			data.z_real = data.c_real;
			data.z_imag = data.c_imag;
			data.n = 0;
			while (data.n++ < data.iter)
			{
				data.z_real_2 = data.z_real * data.z_real;
				data.z_imag_2 = data.z_imag * data.z_imag;
				if (data.z_real_2 + data.z_imag_2 > 4)
					break ;
				data.z_imag = 2 * data.z_real * data.z_imag + data.c_imag;
				data.z_real = data.z_real_2 - data.z_imag_2 + data.c_real;
			}
			mlx_pixel_put(data.mlx, data.win, data.x, data.y, colour(data.n));
			data.x++;
		}
		data.y++;
	}
}
