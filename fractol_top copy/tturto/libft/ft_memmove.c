/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:54:51 by tturto            #+#    #+#             */
/*   Updated: 2021/11/24 14:18:16 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest_char;
	char	*src_char;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	dest_char = (char *)dst;
	src_char = (char *)src;
	i = 0;
	if (src_char < dest_char)
	{
		while (0 < len--)
			dest_char[len] = src_char[len];
	}
	else
	{
		while (len > i++)
			dest_char[i - 1] = src_char[i - 1];
	}
	return (dst);
}
