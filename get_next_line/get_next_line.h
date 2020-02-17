/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:28:43 by clostao-          #+#    #+#             */
/*   Updated: 2019/12/05 20:34:46 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef struct	s_node
{
	int				fd;
	char			*read;
	struct s_node	*next;
}				t_node;
int				ft_strlen(char *str);
char			*ft_strdup(char *src, int mem);
int				breakline_is_in_str(char *str);
char			*ft_substr(char *str, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
static t_node	*node_of_fd(int fd);
static int		put_next_line(t_node **node, char **line, int fd);
int				get_next_line(int fd, char **line);
#endif
