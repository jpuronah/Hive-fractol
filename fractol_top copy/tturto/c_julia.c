/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:51:41 by tturto            #+#    #+#             */
/*   Updated: 2022/09/21 20:42:33 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	c_julia(int n)
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
