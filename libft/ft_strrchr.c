/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:22:40 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/06 12:25:14 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int last;
	int i;

	last = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			last = i;
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char *)&str[i]);
	if (last == -1)
		return ((char *)0);
	return ((char *)&str[last]);
}
