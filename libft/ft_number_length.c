/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:06:10 by jpuronah          #+#    #+#             */
/*   Updated: 2022/10/15 13:06:40 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_length(long long number)
{
	int	i;

	i = 1;
	if (number < 0)
	{
		number *= -1;
		i++;
	}
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	return (i);
}
