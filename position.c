#include "push_swap.h"

void	set_pos(t_list **stack)
{
	t_list	*head;
	int		i;

	head = *stack;
	i = 0;
	while (head)
	{
		head->position = i;
		head = head->next;
		i++;
	}
}

int	get_target(t_list **stack_a, int b_idx, int target_idx, int target_pos)
{
	t_list	*iter;

	iter = *stack_a;
	while (iter)
	{
		if (iter->index > b_idx && iter->index < target_idx)
		{
			target_pos = iter->position;
			target_idx = iter->index;
		}
		iter = iter->next;
	}
	if (target_idx != INT32_MAX)
		return (target_pos);
	iter = *stack_a;
	while (iter)
	{
		if (iter->index < target_idx)
		{
			target_pos = iter->position;
			target_idx = iter->index;
		}
		iter = iter->next;
	}
	return (target_pos);
}

void	get_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list *head;
	int		target_position;

	set_pos(stack_a);
	set_pos(stack_b);
	head = *stack_b;
	target_position = 0;
	while (head)
	{
		target_position = get_target(stack_a, head->index, INT32_MAX, target_position);
		head->target_position = target_position;
		head = head->next;
	}
}