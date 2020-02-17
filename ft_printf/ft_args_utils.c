/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:19:48 by clostao-          #+#    #+#             */
/*   Updated: 2020/01/24 17:15:30 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags **flags)
{
	(*flags)->minwidth = -1;
	(*flags)->right = 0;
	(*flags)->sign = 0;
	(*flags)->spaces = 0;
	(*flags)->type = 0;
	(*flags)->zero = 0;
}

int		ft_print_spaces(t_flags **flags, int numsize)
{
	int		spaces;
	int		printed;
	int		res;
	char	a;

	spaces = ((*flags)->minwidth > numsize) ?
	(*flags)->spaces - (*flags)->minwidth : (*flags)->spaces - numsize;
	res = spaces;
	a = ((*flags)->zero) ? '0' : ' ';
	while (spaces-- > 0)
		write(1, &a, 1);
	return (res);
}

int		ft_print_spaceflag(int numb, t_flags **flags)
{
	int		spaces;
	int		res;
	char	a;
	int		sign;
	int		size;

	a = ((*flags)->zero) ? '0' : ' ';
	size = ft_nbrlen((numb < 0) ? -numb : numb, 10);
	if (numb == 0 && (*flags)->minwidth == 0)
		size = 0;
	sign = ((numb < 0) ? 1 : 0);
	spaces = (*flags)->spaces - ft_max(2, (*flags)->minwidth, size) - sign;
	res = spaces;
	while (spaces-- > 0)
		write(1, " ", 1);
	if (numb < 0 && !(*flags)->right)
	{
		write(1, "-", 1);
		res++;
	}
	return (res);
}

int		ft_print_zeros(int numb, t_flags **flags)
{
	int	spaces;
	int res;
	int	size;
	int sign;

	size = ft_nbrlen((numb < 0) ? -numb : numb, 10);
	sign = ((numb < 0) ? 1 : 0);
	spaces = (*flags)->spaces - ft_max(2, (*flags)->minwidth, size) - sign;
	res = spaces;
	if (sign)
	{
		write(1, "-", 1);
		res++;
	}
	while (spaces-- > 0)
		write(1, "0", 1);
	return (res);
}
