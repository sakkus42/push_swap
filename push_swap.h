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

void	swap_a(int *a);
void	swap_b(int *a);
void	swap_ss(int *a, int *b);
long int	ft_atoi(const char *str);
void	ra(s_list *t_list);
void	rb(s_list *t_list);
void	rr(s_list *t_list);
void	push(int *a, int len, int add);

#endif
