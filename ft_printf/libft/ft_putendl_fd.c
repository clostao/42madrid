/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:13:40 by iibarra-          #+#    #+#             */
/*   Updated: 2019/11/13 20:09:33 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int contador;
	int longitud;

	if (s)
	{
		contador = 0;
		while (s[contador] != '\0')
		{
			contador++;
		}
		longitud = contador;
		contador = 0;
		while (contador < longitud)
		{
			write(fd, &s[contador], 1);
			contador++;
		}
		ft_putchar_fd('\n', fd);
	}
}
