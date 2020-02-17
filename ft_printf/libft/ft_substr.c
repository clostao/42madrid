/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:10:08 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/15 12:06:10 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		return (ft_strdup(""));
	res = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!res)
		return (NULL);
	while (i < (int)len && str[i + start] != 0)
	{
		res[i] = str[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}
