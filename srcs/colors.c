/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:56:20 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 14:32:46 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	set_colour2(int colour)
{
	if (colour == 1)
		return (A);
	if (colour == 3)
		return (B);
	if (colour == 6)
		return (C);
	if (colour == 9)
		return (D);
	if (colour == 12)
		return (E);
	if (colour == 15)
		return (F);
	if (colour == 18)
		return (G);
	if (colour == 21)
		return (H);
	if (colour == 24)
		return (I);
	if (colour == 27)
		return (J);
	return (0);
}

static int	set_colour3(int colour, int ret)
{
	if (colour == 30)
		return (K);
	if (colour == 33)
		return (L);
	if (colour == 36)
		return (M);
	if (colour == 39)
		return (N);
	if (colour == 42)
		return (O);
	if (colour == 45)
		return (P);
	if (colour == 48)
		return (Q);
	if (colour == 51)
		return (E);
	if (colour == 54)
		return (S);
	if (colour == 57)
		return (T);
	if (colour == 60)
		return (U);
	if (colour == 63)
		return (V);
	return (ret);
}

int	set_colour(int colour)
{
	int	ret;

	ret = 0;
	ret = set_colour2(colour);
	ret = set_colour3(colour, ret);
	if (colour > 63)
		return (BLACK);
	return (ret);
}
