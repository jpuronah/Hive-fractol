/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:02:45 by tturto            #+#    #+#             */
/*   Updated: 2021/11/19 14:38:25 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*str;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	str = (char *)s1;
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
	if (len_s2 == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (s2[j] == str[j + i] && i + j < len)
		{
			if (len_s2 - 1 == j)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
