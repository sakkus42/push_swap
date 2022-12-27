NAME = push_swap
LIB = libft/libft.a ft_printf/libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): *.o $(LIB) 
	$(CC) $(FLAGS) -o $(NAME) *.o $(LIB)
	
*.o: *.c
	$(CC) $(FLAGS) -c *.c

$(LIB):
	@make -C ./libft
	@make -C ./ft_printf

clean:
	rm -f *.o
	@make clean -C ./libft
	@make clean -C ./ft_printf

fclean: clean
	rm -f push_swap
	@make fclean -C ./libft
	@make fclean -C ./ft_printf

re: fclean all
