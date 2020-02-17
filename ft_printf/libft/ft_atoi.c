/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:40:04 by clostao-          #+#    #+#             */
/*   Updated: 2019/12/12 09:43:57 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str, int *flag)
{
	int i;
	int sign;
	int res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
	|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	if (!ft_isdigit(str[i]))
		*flag = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (10 * res) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}
