/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:16:34 by carlos            #+#    #+#             */
/*   Updated: 2019/12/13 21:16:57 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ft_is_in_set(char c, char *set)
{
    int i;

    i = 0;
    while (set[i])
        if(set[i] == c)
            return (i);
        else
            i++;
    return (-1);
}

int ft_atoi_base(char *str, char *inbase)
{
    int res;
    int pos;
    int sign;
    int inbaselen;
    int i;

    res = 0;
    inbaselen = strlen(inbase);
    i = (str[0] == '-' || str[0] == '+')?1:0;
    if(str[0] == '-')
        sign = -1;
    while ((pos = ft_is_in_set(str[i], inbase)) != -1)
    {
        res = (inbaselen * res) + pos;
        i++;
    }
    return (res * sign);
}
