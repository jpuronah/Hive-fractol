/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:12:21 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 11:11:35 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_grid_reference(t_mlx *mlx)
{
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, WIN_HEIGHT / 2, WHITE, "This is real -1");
	mlx_string_put(mlx->mlxptr, mlx->winptr, WIN_WIDTH / 2, 20, WHITE, "This is complex 1");
}

void	menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 20,
		WHITE, "Press 'ESC' to EXIT PROGRAM");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 40,
		WHITE, "Press 'M' or 'N' to toggle MOUSE_MODE ON / OFF ");
	draw_grid_reference(mlx);
}

static int	exit_fdf(t_mlx *mlx)
{
	delete_image(*mlx, mlx->image);
	mlx_destroy_window(mlx->mlxptr, mlx->winptr);
	exit (EXIT_SUCCESS);
}

int	key_event(int key, t_mlx *mlx)
{
	printf("key: %d\n", key);
	if (key == 53)//key == 65307
	{
		exit_fdf(mlx);
		//mlx_destroy_window(mlx->mlxptr, mlx->winptr);
		//exit(0);
	}
	if (key == 65307)//key == 65307
	{
		exit_fdf(mlx);
		//mlx_destroy_window(mlx->mlxptr, mlx->winptr);
		//exit(0);
	}
	menu(mlx);
	return (0);
}
