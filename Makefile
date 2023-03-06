
SRCS	=	server.c client.c

OBJS	= ${SRCS:.c=.o}

CFLAGS	=  -Wall -Werror -Wextra

CC		= gcc

RM		= rm -f

NAME 	= server client

#$@ = all, $< = server / client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C libft
	$(CC) -o server server.o -Llibft -lft
	$(CC) -o client client.o -Llibft -lft

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	${RM} server client
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re