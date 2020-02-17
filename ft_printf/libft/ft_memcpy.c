/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:08:32 by clostao-          #+#    #+#             */
/*   Updated: 2019/12/13 13:20:49 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int		i;
	char	*dest;
	char	*ori;

	i = 0;
	if (!str1 && !str2)
		return (NULL);
	dest = (char *)str1;
	ori = (char *)str2;
	while (i < (int)n)
	{
		dest[i] = ori[i];
		i++;
	}
	return (str1);
}
