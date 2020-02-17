/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 11:35:48 by clostao-          #+#    #+#             */
/*   Updated: 2020/01/08 18:11:38 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbrlen(long int num, int base)
{
	int res;

	if (num == 0)
		return (1);
	res = (num < 0) ? 1 : 0;
	while (num != 0)
	{
		num /= base;
		res++;
	}
	return (res);
}
