#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*end;
	t_list	*tmp;

	head = *stack;
	end = head;
	while (end && end->next)
		end = end->next;
	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;
	end->next = head;
	tmp->next = NULL;
	(*stack) = end;
}

void	rra(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}