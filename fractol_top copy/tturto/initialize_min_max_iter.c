/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_min_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:49:02 by tturto            #+#    #+#             */
/*   Updated: 2022/09/21 20:40:11 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_min_max_iter(t_container *data)
{
	data->y = 0;
	if (data->select == 1 || data->select == 3)
	{
		data->iter = 50;
		data->real_min = -2;
		data->real_max = 1;
		data->imag_min = -1.3;
		data->imag_max = 1.3;
	}
	if (data->select == 2)
	{
		data->iter = 80;
		data->real_min = -2;
		data->real_max = 2;
		data->imag_min = -2;
		data->imag_max = 2;
	}
}
