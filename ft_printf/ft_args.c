/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 08:47:47 by clostao-          #+#    #+#             */
/*   Updated: 2020/01/27 13:32:46 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(char **arg, t_flags **flags)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	if (!ft_strncmp(*arg, "d", 1) || !ft_strncmp(*arg, "i", 1))
		res = 1;
	else if (!ft_strncmp(*arg, "u", 1))
		res = 2;
	else if (!ft_strncmp(*arg, "f", 1))
		res = 3;
	else if (!ft_strncmp(*arg, "x", 1))
		res = 4;
	else if (!ft_strncmp(*arg, "X", 1))
		res = 5;
	else if (!ft_strncmp(*arg, "p", 1))
		res = 6;
	else if (!ft_strncmp(*arg, "c", 1))
		res = 7;
	else if (!ft_strncmp(*arg, "s", 1))
		res = 8;
	else if (!ft_strncmp(*arg, "%", 1))
		res = 9;
	return ((*flags)->type = res);
}

int	ft_flags(char **arg, t_flags **flags)
{
	int		flag;

	flag = 0;
	if (**arg != '0' && **arg != '+' && **arg != '-')
		return (0);
	while (**arg && !flag)
	{
		if (**arg == '0')
			(*flags)->zero = 1;
		else if (**arg == '+')
			(*flags)->sign = 1;
		else if (**arg == '-')
		{
			(*flags)->right = 1;
			(*flags)->zero = 0;
		}
		else
			flag = 1;
		(*arg)++;
	}
	if ((*flags)->right == 1)
		(*flags)->zero = 0;
	(*arg) -= flag;
	return (1);
}

int		ft_spaces(char **arg, t_flags **flags, va_list args)
{
	int flag;
	int aux;
	int res;
	int change;

	flag = 0;
	change = 0;
	res = ft_atoi(*arg, &flag);
	if (!flag)
	{
		change = 1;
		(*flags)->spaces = res;
		(*arg) += ft_nbrlen(res, 10);
	}
	else if (**arg == '*')
	{
		change = 1;
		aux = va_arg(args, int);
		(*flags)->right = (aux < 0) ? 1 : (*flags)->right;
		(*flags)->zero = ((*flags)->right) ? 0 : (*flags)->zero;
		(*flags)->spaces = (aux < 0) ? -aux : aux;
		(*arg)++;
	}
	return (change);
}

int		ft_minwidth(char **arg, t_flags **flags, va_list args)
{
	int flag;
	int res;
	int change;

	flag = 0;
	change = 0;
	res = ft_atoi((*arg + 1), &flag);
	if (**arg == '.')
	{
		if (*(*arg + 1) == '*')
		{
			(*flags)->minwidth = va_arg(args, int);
			(*arg) += 2;
		}
		else
		{
			(*arg)++;
			(*flags)->minwidth = res;
			while (ft_isdigit(**arg))
				(*arg)++;
		}
		(*flags)->zero = 0;
	}
	return (change);
}