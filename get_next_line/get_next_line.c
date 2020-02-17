/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:22:17 by clostao-          #+#    #+#             */
/*   Updated: 2019/12/05 20:07:36 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*node_of_fd(int fd)
{
	static t_node	**first;
	t_node			*cursor;
	t_node			*next;

	if (!first)
	{
		first = malloc(sizeof(t_node *));
		cursor = malloc(sizeof(t_node));
		*first = cursor;
		cursor->fd = fd;
		cursor->read = ft_strdup("", 0);
		cursor->next = NULL;
		return (cursor);
	}
	cursor = *first;
	while (cursor->next && cursor->fd != fd)
		cursor = cursor->next;
	if (cursor->fd == fd)
		return (cursor);
	next = malloc(sizeof(t_node));
	cursor->next = next;
	next->fd = fd;
	next->next = NULL;
	return (next);
}

int		put_next_line(t_node **node, char **line, int fd)
{
	int		readlen;
	int		brpos;
	char	buf[BUFFER_SIZE + 1];

	if (!((*line) = ft_strdup((*node)->read, 1)))
		return (-1);
	while ((brpos = breakline_is_in_str(*line)) == -1 &&
	(readlen = read(fd, buf, BUFFER_SIZE)))
	{
		buf[readlen] = 0;
		(*line) = ft_strjoin((*line), buf);
		if (!(*line))
			return (-1);
	}
	if (!readlen)
	{
		if (((*node)->read = ft_strdup("", 0)))
			return (0);
		return (-1);
	}
	(*node)->read = ft_strdup((*line) + brpos + 1, 0);
	if (((*line) = ft_substr((*line), 0, brpos)) && (*node)->read)
		return (1);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	t_node		*fdnode;

	fdnode = node_of_fd(fd);
	if (fd < 0 || !line | read(fd, line, 0) || BUFFER_SIZE < 1)
		return (-1);
	return (put_next_line(&fdnode, line, fd));
}
