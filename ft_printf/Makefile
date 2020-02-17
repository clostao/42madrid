NAME = libftprintf.a

SRCS =	$(wildcard ft_*.c)
GCC = 	@gcc
LIBSRC = $(wildcard libft/*.c)

OBJECTS = $(wildcard *.o)


$(NAME): $(SRCS) ft_printf.h ./libft/libft.h
		-$(GCC) -I./ -c $(SRCS) $(LIBSRC) -I./libft/
		-@ar rc $(NAME) $(OBJECTS)
		-@ranlib $(NAME)

all: $(NAME)

clean:	
		-@rm -f *.o

fclean: clean
		-@rm -f $(NAME)

re: fclean $(NAME)
