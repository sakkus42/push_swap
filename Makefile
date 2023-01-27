NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): *.o $(LIB) 
	$(CC) $(FLAGS) -o $(NAME) *.o

*.o: *.c
	$(CC) $(FLAGS) -c *.c

clean:
	rm -f *.o

fclean: clean
	rm -f push_swap

re: fclean all
