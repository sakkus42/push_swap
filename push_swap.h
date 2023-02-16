#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h> // printf için bunu sil
#include <stdlib.h>

typedef struct stack 
{
	int	*stack_a;
	int	*stack_b;
	int	a_len;
	int b_len;
}	s_list;

void	sa(s_list *s_stack);
void	sb(s_list *s_stack);
void	ss(s_list *s_stack);
long int	ft_atoi(const char *str);
void	ra(s_list *t_list);
void	rb(s_list *t_list);
void	rr(s_list *t_list);
void	pa(s_list *stack);
void	pb(s_list *stack);
void	rra(s_list *t_list);
void	rrb(s_list *t_list);
void	rrr(s_list *t_list);
void	sort_small(s_list *s_stack);

#endif
