#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h> // printf için bunu sil
#include <stdlib.h>

typedef struct s_list
{
	int		value;
	int		index;
	struct	s_list	*next;
}	t_list;

char	**ft_split(char const *s, char c);
int		ft_gen_control(char **arv, int ac);
long int	ft_atoi(char *str);


#endif
