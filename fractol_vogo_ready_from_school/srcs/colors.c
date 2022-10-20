/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:56:33 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/20 22:22:41 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	color_palette_a(int color)
{
	printf("%d\n", color);
	if (color >= 31)
		return (BLACK);
	if (color == 1)
		return (A);
	if (color == 2)
		return (B);
	if (color == 3)
		return (C);
	if (color == 4)
		return (D);
	if (color == 5)
		return (E);
	if (color == 6)
		return (F);
	if (color == 7)
		return (G);
	if (color == 8)
		return (H);
	if (color == 9)
		return (I);
	if (color == 10)
		return (J);
	return (-1);
}

static int	color_palette_b(int color)
{
	printf("%d\n", color);
	if (color == 11)
		return (K);
	if (color == 12)
		return (L);
	if (color == 13)
		return (M);
	if (color == 14)
		return (N);
	if (color == 15)
		return (O);
	if (color == 16)
		return (P);
	if (color == 17)
		return (Q);
	if (color == 18)
		return (E);
	if (color == 19)
		return (S);
	if (color == 20)
		return (T);
	if (color == 21)
		return (U);
	if (color == 22)
		return (V);
	return (-1);
}

static int	color_palette_c(int color)
{
	printf("%d\n", color);
	if (color == 23)
		return (W);
	if (color == 24)
		return (X);
	if (color == 25)
		return (Y);
	if (color == 26)
		return (Z);
	if (color == 27)
		return (AA);
	if (color == 28)
		return (AB);
	if (color == 29)
		return (AC);
	if (color == 30)
		return (AD);
	else
		return (AE);
}

int	set_colour(int color)
{
	int	ret1;
	int	ret2;
	int	ret3;

	ret1 = 0;
	ret2 = 0;
	ret3 = 0;
	ret1 = color_palette_a(color);
	ret2 = color_palette_b(color);
	ret3 = color_palette_c(color);
	printf("%d, %d, %d, %d\n", color, ret1, ret2, ret3);
	if (ret1 > 0)
		return (ret1);
	if (ret2 > 0)
		return (ret2);
	if (ret3 > 0)
		return (ret3);
}

/*
int	set_colour(int color)
{
	if (color >= 31)
		return (BLACK);
	if (color == 1)
		return (A);
	if (color == 2)
		return (B);
	if (color == 3)
		return (C);
	if (color == 4)
		return (D);
	if (color == 5)
		return (E);
	if (color == 6)
		return (F);
	if (color == 7)
		return (G);
	if (color == 8)
		return (H);
	if (color == 9)
		return (I);
	if (color == 10)
		return (J);
	if (color == 11)
		return (K);
	if (color == 12)
		return (L);
	if (color == 13)
		return (M);
	if (color == 14)
		return (N);
	if (color == 15)
		return (O);
	if (color == 16)
		return (P);
	if (color == 17)
		return (Q);
	if (color == 18)
		return (E);
	if (color == 19)
		return (S);
	if (color == 20)
		return (T);
	if (color == 21)
		return (U);
	if (color == 22)
		return (V);
	if (color == 23)
		return (W);
	if (color == 24)
		return (X);
	if (color == 25)
		return (Y);
	if (color == 26)
		return (Z);
	if (color == 27)
		return (AA);
	if (color == 28)
		return (AB);
	if (color == 29)
		return (AC);
	if (color == 30)
		return (AD);
	else
		return (AE);
	return (0);
}*/


int	set_colour_julia(int color)
{
	if (color >= 40)
		return (BLACK);
	if (color == 1)
		return (A);
	if (color == 2)
		return (B);
	if (color == 3)
		return (C);
	if (color == 4)
		return (D);
	if (color == 5)
		return (E);
	if (color == 6)
		return (F);
	if (color == 7)
		return (G);
	if (color == 8)
		return (H);
	if (color == 9)
		return (I);
	if (color == 10)
		return (J);
	if (color == 11)
		return (K);
	if (color == 12)
		return (L);
	if (color == 13)
		return (M);
	if (color == 14)
		return (N);
	if (color == 15)
		return (O);
	if (color == 16)
		return (P);
	if (color == 17)
		return (Q);
	if (color == 18)
		return (E);
	if (color == 19)
		return (S);
	if (color == 20)
		return (T);
	if (color == 21)
		return (U);
	if (color == 22)
		return (V);
	if (color == 23)
		return (W);
	if (color == 24)
		return (X);
	if (color == 25)
		return (Y);
	if (color == 26)
		return (Z);
	if (color == 27)
		return (AA);
	if (color == 28)
		return (AB);
	if (color == 29)
		return (AC);
	if (color == 30)
		return (AD);
	else
		return (AE);
	return (0);
}
