/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:57:57 by iibarra-          #+#    #+#             */
/*   Updated: 2019/12/17 16:51:31 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
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
		while (contador < longitud)
		{
			write(fd, &str[contador], 1);
			contador++;
		}
	}
	else
		write(1, "(null)", 6);
}
