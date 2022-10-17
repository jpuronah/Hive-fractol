/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection2_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:16 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/16 19:07:41 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	colour_julia(int n)
{
	if (n >= 40)
		return (0x00FF00);
	if (n < 2)
		return (0x220000);
	if (n < 4)
		return (0x440000);
	if (n < 6)
		return (0x660000);
	if (n < 8)
		return (0x880000);
	if (n < 10)
		return (0xAA0000);
	if (n < 12)
		return (0xBB0000);
	if (n < 14)
		return (0xCC0000);
	if (n < 16)
		return (0xDD0000);
	if (n < 18)
		return (0xFF0000);
	else
		return (0x000000 << (n % 20));
}

void	julia(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->y < WIN_HEIGHT)
	{
		mlx->c_imag = mlx->imag_max - mlx->y * mlx->imag_factor;
		mlx->x = 0;
		while (mlx->x < WIN_WIDTH)
		{
			mlx->c_real = mlx->real_min + mlx->x * mlx->real_factor;
			mlx->z_real = mlx->c_real;
			mlx->z_imag = mlx->c_imag;
			mlx->n = 0;
			while (mlx->n++ < mlx->iter)
			{
				mlx->z_real_2 = mlx->z_real * mlx->z_real;
				mlx->z_imag_2 = mlx->z_imag * mlx->z_imag;
				if (mlx->z_real_2 + mlx->z_imag_2 > 4)
					break ;
				mlx->z_imag = 2 * mlx->z_real * mlx->z_imag + mlx->julia_c_imag;
				mlx->z_real = mlx->z_real_2 - mlx->z_imag_2 + mlx->julia_c_real;
			}
			mlx_pixel_put(mlx->mlxptr, mlx->winptr, mlx->x, mlx->y, colour_julia(mlx->n));
			mlx->x++;
		}
		mlx->y++;
	}
}

int	mouse_events_julia(int x, int y, t_mlx *mlx)
{
	mlx->julia_c_imag = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
	mlx->julia_c_real = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	julia(mlx);
	return (0);
}
