/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:34:54 by tturto            #+#    #+#             */
/*   Updated: 2021/11/24 14:13:19 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = 0;
	len_src = 0;
	while (dst[len_dest] != '\0')
		len_dest++;
	while (src[len_src] != '\0')
		len_src++;
	if (destsize == 0)
		return (len_src);
	if (destsize >= len_dest)
		len_src = len_src + len_dest;
	else
		len_src = len_src + destsize;
	i = 0;
	while (src[i] != '\0' && len_dest < destsize - 1)
	{
		dst[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dst[len_dest] = '\0';
	return (len_src);
}
