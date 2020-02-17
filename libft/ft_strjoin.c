/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:54:15 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/15 11:48:24 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	charcount(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size = charcount((char *)s1);
	i = charcount((char *)s2);
	res = malloc(sizeof(char) * (size + i + 1));
	i = 0;
	if (res == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i - size] != 0)
	{
		res[i] = s2[i - size];
		i++;
	}
	res[i] = 0;
	return (res);
}
