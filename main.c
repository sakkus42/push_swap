#include "push_swap.h"

void	get_position(t_list **stack_a, t_list **stack_b);

void	display(t_list *stack_a, char c)
{
	while (stack_a)
	{
		printf("stack_%c->index => %d\n", c, stack_a->index);
		stack_a = stack_a->next;
	}
	printf("\n");
}

void	display_target(t_list *stack_a, char c)
{
	while (stack_a)
	{
		printf("stack_%c->target_position => %d | ", c, stack_a->target_position);
		stack_a = stack_a->next;
	}
	printf("\n");
}

int	get_lowest_index_position(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack_a;
	lowest_index = INT32_MAX;
	get_position(stack_a, stack_b);
	lowest_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static void	shift_stack(t_list **stack_a, t_list **stack_b)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_size(stack_a);
	lowest_pos = get_lowest_index_position(stack_a, stack_b);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	three_sort(t_list **stack_a)
{
	if (ft_numeric_cntrl(*stack_a))
		return ;
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
	if ((*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
	three_sort(stack_a);
}

void	up_to_3(t_list **stack_a, t_list **stack_b, int size)
{
	t_list *head;

	while (size > 6 && get_size(stack_a) != size / 2)
	{
		head = *stack_a;
		if (head->index <= size / 2)
			pb(stack_a, stack_b);
		else
		{
			if (get_size(stack_b) > 1 && (*stack_b)->index <= size / 2)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
	while (get_size(stack_a) != 3)
		pb(stack_a, stack_b);
}

void	get_position(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		size;
	int		i;

	size = get_size(stack_b);
	head = *stack_b;
	i = 0;
	while (size--)
	{
		head->position = i++;
		head = head->next;
	}
	size = get_size(stack_a);
	head = *stack_a;
	i = 0;
	while (size--)
	{
		head->position = i++;
		head = head->next;
	}
}

void	target_position(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*iter;
	int		i;
	int		size;

	head = *stack_b;
	size = get_size(stack_b);
	i = 0;
	while (size--)
	{
		iter = *stack_a;
		head->target_position = 0;
		while (iter)
		{
			if (head->index > iter->index)
			{
				head->target_position = iter->position + 1;
			}
			iter = iter->next;
		}
		head = head->next;
	}
}

void	cost(t_list **stack_a, t_list **stack_b)
{
	t_list *head_a;
	t_list *head_b;
	int		size_a;
	int		size_b;

	size_a = get_size(stack_a);
	size_b = get_size(stack_b);
	head_a = *stack_a;
	head_b = *stack_b;
	while (head_b)
	{
		head_b->cost_b = head_b->position;
		if (head_b->position > size_b / 2)
			head_b->cost_b = (size_b - head_b->position) * -1;
		head_b->cost_a = head_b->target_position;
		if (head_b->target_position > size_a / 2)
			head_b->cost_a = (size_a - head_b->target_position) * -1;
		head_b = head_b->next;
	}
}

int	ab_value(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	do_rotate(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	do_rev_rotate(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	do_rotate_a(t_list **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			ra(stack_a);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			rra(stack_a);
			(*cost)--;
		}
	}
}

void	do_rotate_b(t_list **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			rb(stack_a);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			rrb(stack_a);
			(*cost)--;
		}
	}
}

void	do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}

void	do_chp_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_b;
	int		cost_a;
	int		cost_b;
	int		chp;

	chp = INT32_MAX;
	head_b = *stack_b;
	while (head_b)
	{
		if (ab_value(head_b->cost_a) + ab_value(head_b->cost_a) < chp)
		{
			chp = ab_value(head_b->cost_a) + ab_value(head_b->cost_b);
			cost_a = head_b->cost_a;
			cost_b = head_b->cost_b;
		}
		head_b = head_b->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		size;

	size = get_size(stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		three_sort(stack_a);
	else
	{
		up_to_3(stack_a, stack_b, size);
		three_sort(stack_a);
		while (get_size(stack_b))
		{
			get_position(stack_a, stack_b);
			target_position(stack_a, stack_b);
			cost(stack_a, stack_b);
			do_chp_move(stack_a, stack_b);
		}
		shift_stack(stack_a, stack_b);
		// display(*stack_b, 'b');
		// display_target(*stack_b, 'b');
		// pause();
		display(*stack_a, 'a');
		// display_target(*stack_a, 'a');
	}
}


int	main(int ac, char *arv[])	
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		return (0);
	if (ft_gen_control(arv, ac))
		exit_fail(NULL, NULL);
	stack_a = fill_to_stack(arv + 1, ac);
	stack_b = NULL;
	if (ft_numeric_cntrl(stack_a))
		exit_fail(&stack_a, &stack_b);
	indexing(&stack_a);
	sort(&stack_a, &stack_b);
	// system("leaks push_swap");
	return (0);
}
