/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:05:12 by tturto            #+#    #+#             */
/*   Updated: 2022/09/21 20:41:27 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colour(int n)
{
	if (n >= 25)
		return (0x000000);
	if (n < 5)
		return (0x005500);
	if (n < 7)
		return (0x006600);
	if (n < 9)
		return (0x007700);
	if (n < 2)
		return (0x008800);
	if (n < 11)
		return (0x009900);
	if (n < 13)
		return (0x00AA00);
	if (n < 15)
		return (0x00BB00);
	if (n < 17)
		return (0x00CC00);
	if (n < 19)
		return (0x00DD00);
	if (n < 21)
		return (0x00EE00);
	else
		return (0xFFFFFF);
	return (0);
}
