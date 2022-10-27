/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:11 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/27 08:26:50 by jpuronah         ###   ########.fr       */
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
			fractal_type = MANDELBROT;
		if (ft_strcmp(av[1], "julia") == 0)
			fractal_type = JULIA;
		if (ft_strcmp(av[1], "tricorn") == 0)
			fractal_type = TRICORN;
	}
	if (ac != 2 || fractal_type == 0)
		print_error("Usage: ./fractol <fractal name> \
			(julia, mandelbrot, tricorn)");
	return (fractal_type);
}
