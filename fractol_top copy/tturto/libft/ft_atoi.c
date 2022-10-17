/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:08:46 by tturto            #+#    #+#             */
/*   Updated: 2021/11/24 15:35:01 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;
	unsigned long	ret;

	sign = 1;
	i = 0;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		ret = ret * 10 + str[i] - '0';
		if (ret > 9223372036854775807 && sign == 1)
			return (-1);
		if (ret > 9223372036854775808u && sign == -1)
			return (0);
		i++;
	}
	return (ret * sign);
}
