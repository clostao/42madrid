/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:56:36 by clostao-          #+#    #+#             */
/*   Updated: 2020/01/24 16:20:11 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		res;
	va_list ap;
	char	*cursor;
	t_flags *flags;

	res = 0;
	va_start(ap, format);
	cursor = (char *)format;
	flags = malloc(sizeof(t_flags));
	while (*cursor && flags)
	{
		if (*(cursor) == '%')
			res += ft_getformat(&cursor, &flags, ap);
		else
		{
			write(1, cursor, 1);
			res++;
		}
		cursor++;
		free(flags);
		flags = malloc(sizeof(t_flags));
	}
	free(flags);
	return (res);
}

int		ft_getformat(char **str, t_flags **flags, va_list args)
{
	char	*cursor;
	int		flag;

	flag = 1;
	cursor = *str + 1;
	ft_init_flags(flags);
	while (!(ft_isalpha(*cursor)) && flag)
	{
		flag = 0;
		flag += ft_flags(&cursor, flags);
		flag += ft_spaces(&cursor, flags, args);
		flag += ft_minwidth(&cursor, flags, args);
	}
	set_extra_args(flags, args);
	ft_type(&cursor, flags);
	if ((*flags)->type)
		(*str) = cursor;
	else
		(*str)++;
	return (ft_print_formatted(flags, args));
}

int		ft_print_formatted(t_flags **flags, va_list args)
{
	int	type;

	type = (*flags)->type;
	if (type == 1)
		return (ft_putinteger(flags, args));
	if (type == 2)
		return (ft_putunsignedinteger(flags, args));
	if (type == 4)
		return (ft_puthexadecimal(flags, args, 0));
	if (type == 5)
		return (ft_puthexadecimal(flags, args, 1));
	if (type == 6)
		return (ft_putpointer(flags, args));
	if (type == 7)
		return (ft_putcharacter(flags, args));
	if (type == 8)
		return (ft_putstring(flags, args));
	if (type == 9)
		return (ft_putpercent(flags));
	return (1);
}

void	set_extra_args(t_flags **flags, va_list args)
{
	if ((*flags)->minwidth < -1)
		(*flags)->minwidth = -1;
	if ((*flags)->spaces < 0)
		(*flags)->spaces = 0;
}
