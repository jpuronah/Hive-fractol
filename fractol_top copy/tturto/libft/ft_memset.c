/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:02:38 by tturto            #+#    #+#             */
/*   Updated: 2021/11/19 11:02:22 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned char	a;
	size_t			i;

	str = (char *) b;
	a = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		str[i] = a;
		i++;
	}
	return (str);
}
