/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:06:50 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/13 13:09:57 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	str = malloc(len + 1);
	if (!str)
		return (str);
	len = 0;
	while (s[len])
	{
		str[len] = (*f)((unsigned int)len, s[len]);
		len++;
	}
	str[len] = 0;
	return (str);
}
