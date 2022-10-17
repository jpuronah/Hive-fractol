/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:20:33 by tturto            #+#    #+#             */
/*   Updated: 2022/08/08 17:41:09 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int		root;
	int		sqrt;

	root = 1;
	sqrt = 0;
	while (root <= nb / 2)
	{
		sqrt = root * root;
		if (sqrt == nb)
			return (root);
		root = root + 1;
	}
	return (0);
}
