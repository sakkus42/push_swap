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

	tmp = *stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	head = (*stack);
	*stack = (*stack)->next;
	head->next = NULL;
	tmp->next = head;
}

void	ra(t_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

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

void	rrr(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rrr\n", 4);
}