/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:07:29 by carlos            #+#    #+#             */
/*   Updated: 2020/01/08 17:07:04 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_min(unsigned int argc, ...)
{
    int arg1;
    va_list args;
    int min;

    if (argc == 0)
        return (-1);    
    va_start(args, argc);
    min = va_arg(args, int);
    while (argc-- > 1)
    {
        arg1 = va_arg(args, int);
        if (arg1 < min)
            min = arg1;
    }
    return (min);   
}