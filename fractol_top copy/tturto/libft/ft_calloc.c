/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:28:57 by tturto            #+#    #+#             */
/*   Updated: 2021/12/03 12:43:16 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	product;

	ret = NULL;
	if (!count || !size)
		return (ret);
	product = count * size;
	ret = malloc(product);
	if (ret == NULL)
		return (ret);
	ft_bzero(ret, product);
	return (ret);
}
