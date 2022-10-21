/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:56:20 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 11:06:25 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	set_colour2(int colour)
{
	if (colour == 11)
		return (K);
	if (colour == 12)
		return (L);
	if (colour == 13)
		return (M);
	if (colour == 14)
		return (N);
	if (colour == 15)
		return (O);
	if (colour == 16)
		return (P);
	if (colour == 17)
		return (Q);
	if (colour == 18)
		return (E);
	if (colour == 19)
		return (S);
	if (colour == 20)
		return (T);
	if (colour == 21)
		return (U);
	if (colour == 22)
		return (V);
	return (0);
}

int	set_colour(int colour)
{
	int	ret;

	ret = 0;
	if (colour == 1)
		return (A);
	if (colour == 2)
		return (B);
	if (colour == 3)
		return (C);
	if (colour == 4)
		return (D);
	if (colour == 5)
		return (E);
	if (colour == 6)
		return (F);
	if (colour == 7)
		return (G);
	if (colour == 8)
		return (H);
	if (colour == 9)
		return (I);
	if (colour == 10)
		return (J);
	ret = set_colour2(colour);
	if (colour > 22)
		return (BLACK);
	return (ret);
}

/*
static int	set_colour3(int colour)
{
	if (colour == 11)
		return (K);
	if (colour == 12)
		return (L);
	if (colour == 13)
		return (M);
	if (colour == 14)
		return (N);
	if (colour == 15)
		return (O);
	if (colour == 16)
		return (P);
	if (colour == 17)
		return (Q);
	if (colour == 18)
		return (E);
	if (colour == 19)
		return (S);
	if (colour == 20)
		return (T);
	if (colour == 21)
		return (U);
	if (colour == 22)
		return (V);
	return (0);
}


static int	set_colour2(int colour)
{
	if (colour == 1)
		return (A);
	if (colour == 2)
		return (B);
	if (colour == 3)
		return (C);
	if (colour == 4)
		return (D);
	if (colour == 5)
		return (E);
	if (colour == 6)
		return (F);
	if (colour == 7)
		return (G);
	if (colour == 8)
		return (H);
	if (colour == 9)
		return (I);
	if (colour == 10)
		return (J);
	return (0);
}

int	set_colour(int colour)
{
	int	ret;

	ret = 0;
	ret = set_colour2(colour);
	ret = set_colour3(colour);
	if (colour > 22)
		return (BLACK);
	return (ret);
}
*/