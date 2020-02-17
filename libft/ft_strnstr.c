/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:06:09 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/13 09:30:01 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char			*ft_strnstr(char *str, char *to_find, size_t size)
{
	int i;
	int to_find_len;
	int j;

	i = (int)str[0];
	i = 0;
	while (to_find[i])
		i++;
	to_find_len = i;
	i = 0;
	if (to_find_len == 0)
		return (str);
	while (i <= ((int)size - to_find_len))
	{
		j = 0;
		while (j < (int)size && str[i + j] == to_find[j])
		{
			if (j == to_find_len - 1)
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
