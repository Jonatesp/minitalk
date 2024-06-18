SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBS	 = -L./libft -lft
LIBFT	 = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	make -C libft

$(SERVER) : server.o includes/minitalk.h
	$(CC) server.o $(LIBS) -o $@

$(CLIENT) : client.o includes/minitalk.h
	$(CC) client.o $(LIBS) -o $@

%.o : %.c
	$(CC) $(FLAGS) $< -c -I includes

clean :
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(SERVER) $(CLIENT)

re: fclean all