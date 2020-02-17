/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:07:29 by carlos            #+#    #+#             */
/*   Updated: 2019/12/13 13:15:13 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_max(unsigned int argc, ...)
{
    int arg1;
    va_list args;
    int max;

    if (argc == 0)
        return (-1);    
    va_start(args, argc);
    max = va_arg(args, int);
    while (argc-- > 1)
    {
        arg1 = va_arg(args, int);
        if (arg1 > max)
            max = arg1;
    }
    return (max);   
}