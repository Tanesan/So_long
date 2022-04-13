NAME		=	so_long

SRCS		=	main.c src/error/check_error.c src/error/check_error2.c src/error/put_error.c src/game/event.c \
				src/init/init.c src/init/put_image.c src/init/read.c  src/utils/utils.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

LIBFT		=	libft.a

LIBFTDIR	=	libft

FT_PRINTF	=	libftprintf.a

FT_PRINTFDIR=	ft_printf

MINILIBX = -I /usr/X11/include -g -L ./mlx -lmlx -framework OpenGL -framework AppKit

RM			=	rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT): $(LIBFTDIR)
	make all -sC $(LIBFTDIR)
	make all -sC $(FT_PRINTFDIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(SRCS) $(MINILIBX) $(LIBFTDIR)/$(LIBFT) $(FT_PRINTFDIR)/$(FT_PRINTF) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -sC $(LIBFTDIR)
	make clean -sC $(FT_PRINTFDIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -sC $(LIBFTDIR)
	make fclean -sC $(FT_PRINTFDIR)

re: fclean all

.PHONY: all clean fclean re