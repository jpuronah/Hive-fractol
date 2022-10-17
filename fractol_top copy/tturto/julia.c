/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:21:17 by tturto            #+#    #+#             */
/*   Updated: 2022/09/21 20:45:35 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	z = z^2 + c
	In Julia, z should be constant, whereas C varies:
	data.julia_c_imag & data.julia_c_real vary based on the mouse coordinates.
*/
void	julia(t_container data)
{
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
				data.z_imag = 2 * data.z_real * data.z_imag + data.julia_c_imag;
				data.z_real = data.z_real_2 - data.z_imag_2 + data.julia_c_real;
			}
			mlx_pixel_put(data.mlx, data.win, data.x, data.y, c_julia(data.n));
			data.x++;
		}
		data.y++;
	}
}
