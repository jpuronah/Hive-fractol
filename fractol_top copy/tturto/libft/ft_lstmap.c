/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:17:41 by tturto            #+#    #+#             */
/*   Updated: 2021/12/03 12:03:50 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*newlst;

	if (lst == NULL)
		return (NULL);
	node = f(lst);
	newlst = node;
	while (lst->next != NULL)
	{
		lst = lst->next;
		node->next = (t_list *)malloc(sizeof(t_list));
		if (node->next == NULL)
			return (NULL);
		node->next = f(lst);
		node = node->next;
	}
	return (newlst);
}
