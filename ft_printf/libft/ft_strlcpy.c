/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:29:21 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/15 11:48:13 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	int		ret;

	if (!src)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	ret = i;
	i = 0;
	while (i < size - 1 && src[i] != '\0' && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return ((size_t)ret);
}
