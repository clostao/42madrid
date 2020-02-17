/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:41:31 by clostao-          #+#    #+#             */
/*   Updated: 2019/12/13 13:21:20 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	char			*pointer;

	i = 0;
	pointer = (char *)str;
	while ((size_t)i < n)
	{
		pointer[i] = c;
		i++;
	}
	return (str);
}
