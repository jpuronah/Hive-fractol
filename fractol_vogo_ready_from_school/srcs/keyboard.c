/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:12:21 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 17:42:47 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_grid_reference(t_mlx *mlx)
{
	mlx_string_put(mlx->mlxptr, mlx->winptr,
		20, WIN_HEIGHT / 2, WHITE, "This is real -1");
	mlx_string_put(mlx->mlxptr, mlx->winptr,
		WIN_WIDTH / 2, 20, WHITE, "This is complex 1");
}

//draw_grid_reference(mlx);
void	menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 20,
		WHITE, "Press 'ESC' to EXIT PROGRAM");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 40,
		WHITE, "Press 'M' or 'N' to toggle MOUSE_MODE ON / OFF ");
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
	if (key == 53)
		exit_fdf(mlx);
	if (key == 65307)
		exit_fdf(mlx);
	if (key == 65361)
		mlx->x_offset += 100;
	if (key == 65363)
		mlx->x_offset -= 100;
	if (key == 65362)
		mlx->y_offset += 100;
	if (key == 65364)
		mlx->y_offset -= 100;
	menu(mlx);
	return (0);
}
