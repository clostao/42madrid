/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:04:52 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/13 15:39:13 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *s1, void *s2, int ch, size_t n)
{
	unsigned char	*dest;
	unsigned char	*orig;
	unsigned char	c;
	int				final;
	int				i;

	c = (unsigned char)ch;
	dest = s1;
	orig = s2;
	i = 0;
	final = 0;
	while (i < (int)n && !final)
	{
		dest[i] = orig[i];
		if (orig[i] == c)
			final = 1;
		i++;
	}
	if (final == 1)
		return (&dest[i]);
	return (NULL);
}
