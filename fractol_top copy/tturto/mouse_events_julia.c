/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:14:33 by tturto            #+#    #+#             */
/*   Updated: 2022/09/21 19:22:33 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_events_julia(int x, int y, t_container *data)
{
	data->julia_c_imag = (y - HEIGHT * 0.5) / (HEIGHT * 0.5f);
	data->julia_c_real = (x - WIDTH * 0.5) / (WIDTH * 0.5f);
	julia(*data);
	return (0);
}
