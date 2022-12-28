# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct p_list{
	int *a;
	int *b;
}   t_list;

long int *arrays_atoi(char **str);
int arrays_len(char **str);

#endif