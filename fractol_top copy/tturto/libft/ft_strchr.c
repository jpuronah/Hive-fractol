/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:59:42 by tturto            #+#    #+#             */
/*   Updated: 2021/11/19 11:04:30 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	a;

	str = (char *)s;
	a = (unsigned char)c;
	while (*str != a)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return (str);
}
