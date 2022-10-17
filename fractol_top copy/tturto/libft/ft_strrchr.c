/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:03:54 by tturto            #+#    #+#             */
/*   Updated: 2021/11/19 17:17:36 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		k;

	str = (char *)s;
	i = 0;
	k = -1;
	if (c == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (str + i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
			k = i;
		i++;
	}
	if (k >= 0)
		return (str + k);
	else
		return (NULL);
}
