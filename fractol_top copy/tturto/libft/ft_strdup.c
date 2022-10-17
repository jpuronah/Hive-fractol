/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:08:23 by tturto            #+#    #+#             */
/*   Updated: 2021/11/19 19:36:39 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (s1[len] != '\0')
		len++;
	ptr = (char *)malloc(sizeof(const char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		ptr[len] = s1[len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}
