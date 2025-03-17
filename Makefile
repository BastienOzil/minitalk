NAME_SERVER = server

NAME_CLIENT = client

NAME_SERVER_B = server_bonus

NAME_CLIENT_B = client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = server.c utils/ft_printf.c utils/ft_atoi.c

SRCS_CLIENT = client.c utils/ft_printf.c utils/ft_atoi.c

BONUS_S = bonus/server_bonus.c utils/ft_printf.c utils/ft_atoi.c

BONUS_C = bonus/client_bonus.c utils/ft_printf.c utils/ft_atoi.c

BOB_S = $(BONUS_S:.c=.o)

BOB_C = $(BONUS_C:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

bonus: $(NAME_SERVER_B) $(NAME_CLIENT_B)
	
$(NAME_SERVER_B): $(BOB_S)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_B) $(BOB_S)

$(NAME_CLIENT_B): $(BOB_C)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_B) $(BOB_C)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(BOB_S) $(BOB_C)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_B) $(NAME_CLIENT_B)

re: fclean all

.PHONY: all clean fclean re
