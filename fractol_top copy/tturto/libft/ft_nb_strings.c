/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:06:24 by tturto            #+#    #+#             */
/*   Updated: 2021/12/03 12:23:06 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_strings(char const *s, char c)
{
	int	i;
	int	strings;

	i = 0;
	strings = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			strings++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (strings);
}
