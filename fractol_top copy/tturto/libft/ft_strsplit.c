/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:26:16 by tturto            #+#    #+#             */
/*   Updated: 2021/11/25 17:31:45 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_strs(char const *s, char c)
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

static int	ft_len_str(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_index(int i, char const *s, char c)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**mat_strs;
	int		k;
	int		i;

	if (!s)
		return (NULL);
	mat_strs = (char **)malloc(sizeof(char *) * (ft_nb_strs(s, c) + 1));
	if (!mat_strs)
		return (NULL);
	k = 0;
	i = 0;
	while (k < ft_nb_strs(s, c))
	{
		i = ft_index(i, s, c);
		mat_strs[k] = (char *)malloc(sizeof(char) * (ft_len_str(s + i, c) + 1));
		if (!mat_strs[k])
			return (NULL);
		ft_strncpy(mat_strs[k], &s[i], ft_len_str(s + i, c));
		mat_strs[k][ft_len_str(s + i, c)] = '\0';
		while (s[i] != c && s[i] != '\0')
			i++;
		k++;
	}
	mat_strs[k] = 0;
	return (mat_strs);
}
