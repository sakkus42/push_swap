#include "push_swap.h"

void	set_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		size_a;
	int		size_b;

	size_a = get_size(stack_a);
	size_b = get_size(stack_b);
	head = *stack_b;
	while (head)
	{
		head->cost_b = head->position;
		if (head->cost_b > size_b / 2)
			head->cost_b = (size_b - head->position) * -1;
		head->cost_a = head->target_position;
		if (head->cost_a > size_a / 2)
			head->cost_a = (size_a - head->target_position) * -1;
		head = head->next;
	}
}

int		ab_val(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	do_chp_move(t_list **stack_a, t_list **stack_b)
{
	t_list *iter;
	int		chp;
	int		cost_a;
	int		cost_b;

	iter = *stack_b;
	chp = INT32_MAX;
	while (iter)
	{
		if (ab_val(iter->cost_a) + ab_val(iter->cost_b) < chp)
		{
			chp = ab_val(iter->cost_a) + ab_val(iter->cost_b);
			cost_a = iter->cost_a;
			cost_b = iter->cost_b;
		}
		iter = iter->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}