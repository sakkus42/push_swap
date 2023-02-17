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
	if (s_stack->stack_b[0] > s_stack->stack_a[2])
	{
		pa(s_stack);
		ra(s_stack);	
	}
	else if (s_stack->stack_b[0] < s_stack->stack_a[0])
		pa(s_stack);
	else if (s_stack->stack_b[0] > s_stack->stack_a[0] &&
		s_stack->stack_b[0] < s_stack->stack_a[1])
	{
		pa(s_stack);
		sa(s_stack);
	}
}

void	sort_small(s_list *s_stack)
{
	if (s_stack->a_len == 3)
	{
		three(s_stack);
		return ;
	}
	else if (s_stack->a_len == 5)
	{
		pb(s_stack);
		pb(s_stack);
		three(s_stack);
		if (s_stack->stack_b[0] < s_stack->stack_b[1])
			sb(s_stack);
		five(s_stack);
		five(s_stack);
	}
}