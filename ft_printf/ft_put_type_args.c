/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:09:14 by carlos            #+#    #+#             */
/*   Updated: 2020/01/27 13:44:40 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putinteger(t_flags **flags, va_list args)
{
	int numb;
	int width;
	int size;
	int sign;

	numb = va_arg(args, int);
	size = ft_nbrlen((numb < 0) ? -(long int)numb : (long int)numb, 10);
	if (numb == 0 && (*flags)->minwidth == 0)
		size = 0;
	sign = (numb < 0) ? 1 : 0;
	width = (*flags)->minwidth - size;
	if ((*flags)->zero)
		ft_print_zeros(numb, flags);
	else if (!(*flags)->right)
		ft_print_spaceflag(numb, flags);
	if (numb < 0 && (*flags)->right)
		write(1, "-", 1);
	while (width-- > 0)
		write(1, "0", 1);
	if (numb != 0 || (*flags)->minwidth != 0)
		ft_putnbr_fd((numb < 0) ? -(long int)numb : (long int)numb, 1);
	if ((*flags)->right)
		ft_print_spaceflag(numb, flags);
	return (ft_max(3, size + sign,
	(*flags)->minwidth + sign, (*flags)->spaces));
}

int		ft_putunsignedinteger(t_flags **flags, va_list args)
{
	int				size;
	int				aux;
	int				spaces;
	unsigned int	numb;
	int				i;

	numb = va_arg(args, unsigned int);
	size = ft_nbrlen(numb, 10);
	if ((*flags)->minwidth == 0 && numb == 0)
		size = 0;
	if (!((*flags)->right))
		aux = ft_print_spaces(flags, size);
	spaces = (*flags)->minwidth - size;
	while (spaces-- > 0)
		write(1, "0", 1);
	if (numb != 0 || (*flags)->minwidth != 0)
		ft_putnbr_fd(numb, 1);
	if (((*flags)->right))
		aux = ft_print_spaces(flags, size);
	if (numb == 0 && (*flags)->minwidth == 0)
		return (aux);
	return (ft_max(3, (*flags)->spaces, (*flags)->minwidth, size));
}

int		ft_putstring(t_flags **flags, va_list args)
{
	int		spaces;
	int		strlen;
	char	a;
	int		size;
	char	*str;

	a = ((*flags)->zero) ? '0' : ' ';
	str = va_arg(args, char *);
	strlen = ft_strlen(str);
	size = strlen;
	if ((*flags)->minwidth == -1)
		(*flags)->minwidth = 2147483647;
	size = ft_min(2, strlen, (*flags)->minwidth);
	spaces = (*flags)->spaces - ft_min(2, strlen, (*flags)->minwidth);
	while (!(*flags)->right && spaces-- > 0)
		write(1, &a, 1);
	ft_putnstr_fd(str, 1, (*flags)->minwidth);
	while ((*flags)->right && spaces-- > 0)
		write(1, &a, 1);
	return (ft_max(2, size, (*flags)->spaces));
}

int		ft_putcharacter(t_flags **flags, va_list args)
{
	int		spaces;
	char	str;

	str = va_arg(args, int);
	spaces = (*flags)->spaces - 1;
	if (!(*flags)->right)
		while (spaces-- > 0)
			write(1, " ", 1);
	ft_putchar_fd(str, 1);
	while (spaces-- > 0)
		write(1, " ", 1);
	return (ft_max(2, 1, (*flags)->spaces));
}

int		ft_puthexadecimal(t_flags **flags, va_list args, int uppercase)
{
	int				size;
	char			*str;
	int				spaces;
	unsigned int	numb;

	numb = va_arg(args, unsigned int);
	size = (numb == 0) ? 1 : ft_nbrlen(numb, 16);
	if (numb == 0 && (*flags)->minwidth == 0)
		size = 0;
	if (!((*flags)->right))
		ft_print_spaces(flags, size);
	spaces = (*flags)->minwidth - size;
	if (numb < 0)
		write(1, "-", 1);
	while (spaces-- > 0)
		write(1, "0", 1);
	str = ft_itoa_base(numb, (uppercase)
	? "0123456789ABCDEF" : "0123456789abcdef");
	if (numb != 0 || (*flags)->minwidth != 0)
		ft_putstr_fd(str, 1);
	if (str)
		free(str);
	if (((*flags)->right))
		ft_print_spaces(flags, size);
	return (ft_max(3, (*flags)->spaces, (*flags)->minwidth, size));
}

int		ft_putpointer(t_flags **flags, va_list args)
{
	int				size;
	char			*str;
	int				spaces;
	unsigned long	numb;
	int				i;

	i = 0;
	numb = (unsigned long)va_arg(args, void *);
	size = ((numb) ? ft_nbrlen(numb, 16) : 1) + 2;
	if (!numb && !(*flags)->minwidth)
		size = 2;
	if ((*flags)->zero)
		write(1, "0x", 2);
	if (!((*flags)->right))
		ft_print_spaces(flags, size);
	if (!(*flags)->zero)
		write(1, "0x", 2);
	if (!numb && !(*flags)->minwidth)
		return (ft_max(2, (*flags)->spaces, 2));
	spaces = (*flags)->minwidth - size + 2;
	while (spaces-- > 0)
		write(1, "0", 1);
	str = ft_itoa_base(numb, "0123456789abcdef");
	ft_putstr_fd(str, 1);
	if (str)
		free(str);
	if (((*flags)->right))
		ft_print_spaces(flags, size);
	return (ft_max(3, (*flags)->spaces, (*flags)->minwidth + 2, size));
}

int		ft_putpercent(t_flags **flags)
{
	(*flags)->minwidth = 0;
	if (!(*flags)->right)
		ft_print_spaces(flags, 1);
	write(1, "%", 1);
	if ((*flags)->right)
		ft_print_spaces(flags, 1);
	return (ft_max(2, 1, (*flags)->spaces));
}
