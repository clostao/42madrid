/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:12:27 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/13 13:53:11 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*aux;

	start = NULL;
	(void)del;
	if (lst)
	{
		start = ft_lstnew((*f)(lst->content));
		aux = start;
		while ((lst = lst->next))
		{
			aux->next = ft_lstnew((*f)(lst->content));
			aux = aux->next;
		}
		return (start);
	}
	return (NULL);
}
