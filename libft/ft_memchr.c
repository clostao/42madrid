/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:30:40 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/09 19:45:19 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	int		i;
	char	*iterator;
	int		final;

	i = 0;
	final = 0;
	iterator = (char *)str;
	while (i < (int)n && final == 0)
	{
		if (iterator[i] == c)
			final = 1;
		i++;
	}
	if (final == 0)
		return (NULL);
	return (&iterator[i - 1]);
}
