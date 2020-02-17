/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:05:49 by clostao-          #+#    #+#             */
/*   Updated: 2019/12/05 20:06:27 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src, int mem)
{
	char	*dest;
	int		srclen;

	srclen = 0;
	if (!src)
		return (ft_strdup("", 0));
	while (src[srclen])
		srclen++;
	dest = (char	*)malloc(srclen + 1);
	if (!dest)
		return (NULL);
	while (srclen >= 0)
	{
		dest[srclen] = src[srclen];
		srclen--;
	}
	if (mem && src)
		free(src);
	return (dest);
}

int		breakline_is_in_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ('\n' == str[i] || '\r' == str[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
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
		res[0] = 0;
	}
	i = 0;
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < (int)len && str[i + start] != 0)
	{
		res[i] = str[i + start];
		i++;
	}
	free(str);
	res[i] = 0;
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*res;
	int			size;
	int			i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1);
	res = malloc(sizeof(char) * (size + ft_strlen(s2) + 1));
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
	free(s1);
	return (res);
}
