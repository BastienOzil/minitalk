NAME_SERVER = server

NAME_CLIENT = client

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS_SERVER = server.c utils/ft_printf.c utils/ft_atoi.c

SRCS_CLIENT = client.c utils/ft_printf.c utils/ft_atoi.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
