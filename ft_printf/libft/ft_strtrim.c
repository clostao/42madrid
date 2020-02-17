/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:54:46 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/15 11:46:38 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		char_is_in_set(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_first_position(char const *s1, char const *set)
{
	int i;
	int setlen;

	i = 0;
	setlen = 0;
	while (set[setlen])
		setlen++;
	while (char_is_in_set(s1[i], (char *)set))
		i++;
	return (i);
}

static int		ft_last_position(char const *s1, char const *set)
{
	int slen;
	int setlen;

	setlen = 0;
	slen = 0;
	while (s1[slen])
		slen++;
	while (set[setlen])
		setlen++;
	slen--;
	while (char_is_in_set(s1[slen], (char *)set))
		slen--;
	return (slen);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int	first;
	int end;

	if (!s1 || !set)
		return (NULL);
	first = ft_first_position(s1, set);
	if (s1[first] == 0)
		return (ft_strdup(""));
	end = ft_last_position(s1, set);
	return (ft_substr((char *)s1, first, end - first + 1));
}
