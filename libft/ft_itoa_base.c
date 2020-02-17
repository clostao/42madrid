/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:17:45 by carlos            #+#    #+#             */
/*   Updated: 2020/01/08 21:49:52 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long int n, char *outbase)
{
	long int aux;
	int i;
	int size;
	int outlen;
	char *res;

	if (n == 0lu)
		return (ft_strdup("0"));
	size = 0;
	i = 0;
	outlen = ft_strlen(outbase);
	aux = (n > 0) ? (long int)n : (long int)(-1 * n);
	size = ft_nbrlen(((n > 0) ? n : -n), outlen);
	size += (n < 0) ? 1 : 0;
	res = malloc(size + 1);
	aux = (n > 0) ? (long int)n : (long int)(-1 * n);
	while (aux != 0)
	{
		res[size - i - 1] = outbase[aux % outlen];
		aux /= outlen;
		i++;
	}
	if (n < 0)
		res[size - i - 1] = '-';
	return (res);
}
