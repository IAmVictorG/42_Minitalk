
SRCS	=	server.c client.c

OBJS	= ${SRCS:.c=.o}

CFLAGS	=  -Wall -Werror -Wextra

CC		= gcc

RM		= rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: server client

#$@ = all, $< = server / client

server: server.o
	make -C libft	
	$(CC)  -o $@ $< -Llibft -lft

client: client.o
	make -C libft
	$(CC) -o $@ $< -Llibft -lft

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	${RM} server client
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re