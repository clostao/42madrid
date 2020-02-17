/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 23:01:25 by clostao-          #+#    #+#             */
/*   Updated: 2020/01/08 23:14:29 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnstr_fd(char *str, int fd, int max)
{
	int contador;
	int longitud;

	longitud = 0;
	if (str)
	{
		contador = 0;
		while (str[contador] != '\0')
		{
			contador++;
		}
		longitud = contador;
		contador = 0;
		while (contador < longitud && contador < max)
		{
			write(fd, &str[contador], 1);
			contador++;
		}
	}
	else
		write(1, "(null)", (6 > max) ? max : 6);
}
