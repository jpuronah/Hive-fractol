/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:56:20 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/23 18:12:23 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	set_colour(int colour)
{
	int	ret;

	ret = 0;
	if (colour % 1 == 1)
		return (A);
	if (colour % 2 == 1)
		return (B);
	if (colour % 3 == 1)
		return (C);
	if (colour % 4 == 1)
		return (D);
	if (colour % 5 == 1)
		return (E);
	if (colour % 6 == 1)
		return (F);
	if (colour % 7 == 1)
		return (G);
	if (colour % 8 == 1)
		return (H);
	if (colour % 9 == 1)
		return (I);
	if (colour % 10 == 1)
		return (J);
	if (colour % 11 == 1)
		return (K);
	if (colour % 12 == 1)
		return (L);
	if (colour % 13 == 1)
		return (M);
	if (colour % 14 == 1)
		return (N);
	if (colour % 15 == 1)
		return (O);
	if (colour % 16 == 1)
		return (P);
	if (colour % 17 == 1)
		return (Q);
	if (colour % 18 == 1)
		return (E);
	if (colour % 19 == 1)
		return (S);
	if (colour % 20 == 1)
		return (T);
	if (colour % 21 == 1)
		return (U);
	if (colour % 22 == 1)
		return (V);
	if (colour % 22 == 1)
		return (W);
	if (colour % 23 == 1)
		return (X);
	if (colour % 24 == 1)
		return (Y);
	if (colour % 25 == 1)
		return (Z);
	if (colour % 26 == 1)
		return (AA);
	if (colour % 27 == 1)
		return (AB);
	if (colour % 28 == 1)
		return (AC);
	if (colour % 29 == 1)
		return (AD);
	if (colour % 30 == 1)
		return (AE);
	if (colour % 31 == 1)
		return (T);
	if (colour % 32 == 1)
		return (U);
	if (colour % 33 == 1)
		return (V);
	if (colour > 99)
		return (BLACK);
	return (ret);
}
