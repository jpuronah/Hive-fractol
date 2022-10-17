/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:38:32 by tturto            #+#    #+#             */
/*   Updated: 2021/11/25 16:19:11 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min_max(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	if (nb == 2147483647)
	{
		write(1, "2", 1);
		nb = 147483647;
	}
	return (nb);
}

static long int	get_size(int nb)
{
	int					len;
	unsigned long int	size;

	len = 1;
	size = len;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	while (len > 1)
	{
		size = size * 10;
		len--;
	}
	return (size);
}

void	ft_putnbr(int nb)
{
	unsigned long int	size;
	int					remainder;
	char				remainder_char;

	if (nb == -2147483648 || nb == 2147483647)
		nb = min_max(nb);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	size = get_size(nb);
	while ((size / 10) > 0)
	{
		size = size / 10;
		remainder = (nb / size) % 10;
		remainder_char = remainder + '0';
		write(1, &remainder_char, 1);
	}
}
