#include "push_swap.h"

void	swaping(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!(*stack) && !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **stack)
{
	swaping(stack);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	swaping(stack);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swaping(stack_a);
	swaping(stack_b);
	write(1, "ss\n", 3);
}