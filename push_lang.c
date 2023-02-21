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

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	top_a = (*stack_a);
	top_b = (*stack_b);
	tmp = top_a->next;
	top_a->next = top_b;
	(*stack_a) = tmp;
	(*stack_b) = top_a;	
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;
}