/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:52 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/16 19:06:57 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	tricorn(t_mlx *mlx)
{
	printf("maissitriplana1\n");
	//clear_image(mlx->image);
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
				mlx->z_imag = -2 * mlx->z_real * mlx->z_imag + mlx->c_imag;
				mlx->z_real = mlx->z_real_2 - mlx->z_imag_2 + mlx->c_real;
			}
			mlx_pixel_put(mlx->mlxptr, mlx->winptr, mlx->x, mlx->y, colour(mlx->n));
			mlx->x++;
		}
		mlx->y++;
	}
	printf("maissitriplana1\n");
}
