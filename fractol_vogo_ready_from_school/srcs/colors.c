/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:56:33 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/21 10:44:06 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*int	set_colour3(int colour)
{
	if (colour == 23)
		return (W);
	if (colour == 24)
		return (X);
	if (colour == 25)
		return (Y);
	if (colour == 26)
		return (Z);
	if (colour == 27)
		return (AA);
	if (colour == 28)
		return (AB);
	if (colour == 29)
		return (AC);
	if (colour == 30)
		return (AD);
	if (colour == 31)
		return (AE);
	if (colour > 31) //31
		return (BLACK);
	return (0);
}*/
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define BLUE 0x0000FF
# define GRAY 0x808080
# define GREEN 0x008000
# define PURPLE 0x800080
# define RED 0xFF0000
# define ALICEBLUE 0xF0F8FF
# define CORAL 0xFF7F50
# define FIREBRICK 0xB22222
# define HOTPINK 0xFF69B4
# define LEMONCHIFFON 0xFFFACD

int	set_colour4(int colour)
{
	if (colour == 32)
		return (LEMONCHIFFON);
	if (colour == 33)
		return (HOTPINK);
	if (colour == 34)
		return (FIREBRICK);
	if (colour == 35)
		return (CORAL);
	if (colour == 36)
		return (ALICEBLUE);
	if (colour == 37)
		return (RED);
	if (colour == 38)
		return (PURPLE);
	if (colour == 39)
		return (GREEN);
	if (colour == 40)
		return (BLUE);
	return (0);
}

int	set_colour3(int colour)
{
	if (colour == 23)
		return (W);
	if (colour == 24)
		return (X);
	if (colour == 25)
		return (Y);
	if (colour == 26)
		return (Z);
	if (colour == 27)
		return (AA);
	if (colour == 28)
		return (AB);
	if (colour == 29)
		return (AC);
	if (colour == 30)
		return (AD);
	if (colour == 31)
		return (AE);
	return (0);
}

int	set_colour2(int colour)
{
	if (colour == 10)
		return (J);
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
	int ret;

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
	ret = set_colour2(colour);
	//ret = set_colour3(colour);
	//ret = set_colour4(colour);
	if (colour > 40) //31
		return (BLACK);
	return (ret);
}

/*
int	set_colour_julia(int colour)
{
	if (colour >= 40)
		return (BLACK);
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
	if (colour == 23)
		return (W);
	if (colour == 24)
		return (X);
	if (colour == 25)
		return (Y);
	if (colour == 26)
		return (Z);
	if (colour == 27)
		return (AA);
	if (colour == 28)
		return (AB);
	if (colour == 29)
		return (AC);
	if (colour == 30)
		return (AD);
	else
		return (AE);
	return (0);
}*/
