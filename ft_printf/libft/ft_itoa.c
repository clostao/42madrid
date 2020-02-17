/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:37:15 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/15 11:47:26 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count_and_sign(int *len, int *sign, int *aux, long int *al)
{
	*sign = 0;
	if (*al < 0)
	{
		*sign = 1;
		*al *= -1;
	}
	*aux = *al;
	*len = 0;
	while (*aux != 0)
	{
		*aux /= 10;
		(*len)++;
	}
}

char		*ft_itoa(int a)
{
	int			sign;
	int			len;
	int			aux;
	char		*res;
	long int	al;

	if (a == 0)
		return (ft_strdup("0"));
	al = (long int)a;
	count_and_sign(&len, &sign, &aux, &al);
	res = malloc((len + sign) * sizeof(char) + 1);
	if (!res)
		return (res);
	aux = 0;
	if (sign == 1)
		res[aux++] = '-';
	while (al != 0)
	{
		res[(len + 2 * sign) - 1 - aux++] = al % 10 + '0';
		al /= 10;
	}
	res[aux] = '\0';
	return (res);
}
