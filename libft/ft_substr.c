/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:10:08 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/13 17:10:51 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	int		i;
	int		l;

	l = 0;
	if (!str)
		return (NULL);
	while (str[l])
		l++;
	if (l < (int)start)
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	res = malloc((len + 1) * sizeof(char));
	i = 0;
	while (res && i < (int)len && str[i] != 0)
	{
		res[i] = str[i + start];
		i++;
	}
	if (res)
		res[i] = 0;
	return (res);
}
