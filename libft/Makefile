NAME = libft.a
SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_lstnew.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_strchr.c ./ft_strdup.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstadd_back.c ./ft_lstlast.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_putstr_fd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_split.c 
BONUS = ./ft_substr.c
OBJ = $(SRCS:.c=.o)
BONUSOBJ = $(BONUS:.c:.o)
CC = gcc
CFLAGS +=-Wextra -Werror -Wall -I./
$(NAME): 	$(OBJ)
	$(CC) $(FLAG) -c $(SRCS) 
	ar -rcs libft.a ${OBJ}
	ranlib ${NAME}
$(BONUS): 	$(BONUSOBJ)
	$(CC) $(FLAG) -c $(BONUS) 
	ar -rcs libft.a ${BONUSOBJ}
	ranlib ${BONUS}
all: $(NAME)
clean:
	rm -f ${OBJ}
fclean:	clean
		rm -f ${NAME}
bonus: $(BONUS)
re:	fclean all
.PHONY: all fclean clean re