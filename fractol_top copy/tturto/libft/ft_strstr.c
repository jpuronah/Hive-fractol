/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:05:01 by tturto            #+#    #+#             */
/*   Updated: 2021/11/24 14:16:55 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	int		len_needle;
	int		i;
	int		j;

	str = (char *)haystack;
	len_needle = 0;
	while (needle[len_needle] != '\0')
		len_needle++;
	if (len_needle == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[j + i] == needle[j])
		{
			if (j == len_needle - 1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
