/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:09:47 by tturto            #+#    #+#             */
/*   Updated: 2021/12/03 12:10:06 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_get_size(int nb)
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
