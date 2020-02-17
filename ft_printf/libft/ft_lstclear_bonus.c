/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:32:25 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/12 22:56:03 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while (lst && *lst && del)
	{
		aux = *lst;
		(*lst) = (*lst)->next;
		if (del)
			(*del)(aux->content);
		free(aux);
	}
	lst = NULL;
}
