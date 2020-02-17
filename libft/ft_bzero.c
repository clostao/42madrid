/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:06:46 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/09 19:54:32 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *str, int n)
{
	int				i;
	unsigned char	*pointer;

	pointer = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		pointer[i] = 0;
		i++;
	}
}
