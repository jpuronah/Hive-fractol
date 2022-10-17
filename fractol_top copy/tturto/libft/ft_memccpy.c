/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:49:31 by tturto            #+#    #+#             */
/*   Updated: 2021/11/22 18:48:47 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	a;
	size_t			i;
	unsigned char	*src_char;
	unsigned char	*dest_char;

	a = (unsigned char)c;
	i = 0;
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		if (src_char[i] == a)
			return ((void *)(&dest_char[i + 1]));
		i++;
	}
	return (NULL);
}
