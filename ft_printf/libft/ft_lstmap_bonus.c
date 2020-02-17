/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:12:27 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/15 11:56:37 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*start;
	t_list	*aux;

	start = NULL;
	(void)d;
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
