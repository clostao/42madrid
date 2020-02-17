/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:48:29 by clostao-          #+#    #+#             */
/*   Updated: 2020/01/08 23:03:57 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
int				ft_atoi(const char *str, int *flag);
void			ft_bzero(void *str, int n);
void			*ft_calloc(size_t num, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int a);
int				ft_isprint(int c);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t size);
char			*ft_strrchr(const char *str, int c);
char			*ft_substr(const char *str, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_tolower(int c);
char			*ft_itoa(int a);
int				ft_toupper(int c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **alst, t_list *ne);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *ne);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *alst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(long int nb, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putnstr_fd(char *str, int fd, size_t max);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
int				ft_max(unsigned int argc, ...);
int     		ft_min(unsigned int argc, ...);
void			ft_putfloat_fd(double nb, int fd, int precision);
int				ft_pow(int base, int exp);
int				ft_atoi_base(char *str, char *inbase);
char			*ft_itoa_base(long int n, char *outbase);
int				ft_nbrlen(long int num, int base);
#endif
