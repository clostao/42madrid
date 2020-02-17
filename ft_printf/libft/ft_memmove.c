/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:48:03 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/13 16:34:49 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t len)
{
	size_t		i;
	char		*dst;
	const char	*src;

	dst = dest;
	src = source;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			dst[i] = src[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
