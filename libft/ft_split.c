/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:41:28 by clostao-          #+#    #+#             */
/*   Updated: 2019/11/15 12:14:33 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_next_pos(char const *s, int i, char c)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static char			**add_str_to_tab(char **tab, char *str)
{
	int		len;
	char	**tabcpy;

	if (!str)
		return (NULL);
	len = 0;
	while (tab[len])
		len++;
	tabcpy = malloc(sizeof(char *) * (len + 2));
	len = 0;
	while (tab[len])
	{
		tabcpy[len] = ft_strdup(tab[len]);
		len++;
	}
	tabcpy[len] = str;
	tabcpy[len + 1] = 0;
	free(tab);
	return (tabcpy);
}

char				**ft_split(char const *s, char c)
{
	char	**tab;
	int		first;
	int		i;

	tab = malloc(sizeof(char *));
	if (!s || !tab)
		return (NULL);
	first = ft_next_pos(s, 0, c);
	i = first;
	tab[0] = NULL;
	while (s[i])
		if (s[i] == c)
		{
			tab = add_str_to_tab(tab, ft_substr(s, first, i - first));
			if (!tab)
				return (tab);
			first = ft_next_pos(s, i, c);
			i = first;
		}
		else
			i++;
	if (i > 0 && s[i - 1] != c)
		tab = add_str_to_tab(tab, ft_substr(s, first, i - first));
	return (tab);
}
