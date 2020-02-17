/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:25:07 by clostao-          #+#    #+#             */
/*   Updated: 2020/01/08 21:14:32 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
typedef	struct	s_flags
{
	int		zero;
	int		sign;
	int		right;
	int		minwidth;
	int		spaces;
	int		type;
}				t_flags;
void	ft_init_flags(t_flags **flags);
int		number_length(long int num, int base);
int		ft_type(char **arg, t_flags **flags);
int		ft_flags(char **arg, t_flags **flags);
int		ft_spaces(char **arg, t_flags **flags, va_list args);
int		ft_minwidth(char **arg, t_flags **flags, va_list args);
int		ft_printf(const char *format, ...);
int		ft_getformat(char **str, t_flags **flags, va_list args);
int		ft_print_formatted(t_flags **flags, va_list args);
void	set_extra_args(t_flags **flags, va_list args);
int		ft_print_zeros(int numb, t_flags **flags);
int		ft_print_spaceflag(int numb, t_flags **flags);
int		ft_putinteger(t_flags **flags, va_list args);
int		ft_print_spaces(t_flags **flags, int numsize);
int		ft_putunsignedinteger(t_flags **flags, va_list args);
int		ft_putfloat(t_flags **flags, va_list args);
int		ft_putstring(t_flags **flags, va_list args);
int		ft_putcharacter(t_flags **flags, va_list args);
int		ft_puthexadecimal(t_flags **flags, va_list args, int uppercase);
int		ft_putpointer(t_flags **flags, va_list args);
int 	ft_putpercent(t_flags **flags);
#endif
