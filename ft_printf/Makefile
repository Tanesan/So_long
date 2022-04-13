NAME		=	libftprintf.a

SRCS		=	ft_printf.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_strlen.c ft_utils.c ft_putnbr_unsigned_fd.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re