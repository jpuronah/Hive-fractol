/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:11 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 13:14:18 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(char *reason)
{
	ft_putendl(reason);
	exit(0);
}

int	check_fractal_type(int ac, char **av)
{
	int			fractal_type;

	fractal_type = 0;
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			fractal_type = 1;
		if (ft_strcmp(av[1], "julia") == 0)
			fractal_type = 2;
		if (ft_strcmp(av[1], "tricorn") == 0)
			fractal_type = 3;
	}
	if (ac != 2 || fractal_type == 0)
		print_error("Usage: ./fractol <fractal name> \
			(julia, mandelbrot, tricorn)");
	return (fractal_type);
}
