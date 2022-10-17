/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:23:36 by tturto            #+#    #+#             */
/*   Updated: 2021/11/25 16:18:46 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min_max(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		nb = 147483648;
	}
	if (nb == 2147483647)
	{
		write(fd, "2", 1);
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

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned long int	size;
	int					remainder;
	char				remainder_char;

	if (nb == -2147483648 || nb == 2147483647)
		nb = min_max(nb, fd);
	if (nb < 0)
	{
		nb = -nb;
		write (fd, "-", 1);
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	size = get_size(nb);
	while ((size / 10) > 0)
	{
		size = size / 10;
		remainder = (nb / size) % 10;
		remainder_char = remainder + '0';
		write(fd, &remainder_char, 1);
	}
}
