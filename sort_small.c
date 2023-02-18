#include "push_swap.h"

void	three(s_list *s_stack)
{
	int	*a;

	a = s_stack->stack_a;
	if (a[1] < a[0] && a[1] < a[2] && a[0] < a[2])
		sa(s_stack);
	else if (a[0] > a[2] && a[0] > a[1] && a[1] > a[2])
	{
		sa(s_stack);
		rra(s_stack);
	}
	else if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
		ra(s_stack);
	else if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		sa(s_stack);
		ra(s_stack);
	}
	else if (a[0] > a[2] && a[0] < a[1] && a[1] > a[2])
		rra(s_stack);
}

void	five(s_list *s_stack)
{
	while (s_stack->sorted[2] <= s_stack->stack_a[0])
		ra(s_stack);
	if (s_stack->sorted[2] > s_stack->stack_a[0])
		pb(s_stack);
	while (s_stack->sorted[2] <= s_stack->stack_a[0])
		ra(s_stack);
	if (s_stack->sorted[2] > s_stack->stack_a[0])
		pb(s_stack);
	three(s_stack);
	if (s_stack->stack_b[0] < s_stack->stack_b[1])
		sb(s_stack);
	pa(s_stack);
	pa(s_stack);
}

void	sort_small(s_list *s_stack)
{
	if (s_stack->a_len == 3)
		three(s_stack);
	else if (s_stack->a_len == 2)
		sa(s_stack);
	else if (s_stack->a_len == 5)
		five(s_stack);
}