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

t_list		*fill_to_stack(char **arv, int ac);
t_list		*new_struct(char *str);
t_list		*stack_creat(t_list *stack_a);
int			ft_gen_control(char **arv, int ac);
int			ft_numeric_cntrl(t_list *stack_a);
long int	ft_atoi(char *str);
char		**ft_split(char const *s, char c);
void		free_str(char **str);
void		exit_fail(t_list **stack_a, t_list **stack_b);
int			get_size(t_list **stack);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		sb(t_list **stack);
void		sa(t_list **stack);
void		rotate(t_list **stack);


#endif
