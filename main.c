#include "push_swap.h"

void	display(t_list *stack_a)
{
	while (stack_a)
	{
		printf("stack_a => %d\n", stack_a->index);
		stack_a = stack_a->next;
	}
}

void	push_b(t_list **stack_a, t_list **stack_b, int size)
{
	t_list *head;

	head = *stack_a;
	while (head && get_size(stack_a) != 3)
	{
		head = *stack_a;
		if (head->index < size - 3)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

void	push_a(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*head;

	head = *stack_b;
	while (head && get_size(stack_b) != 0)
	{
		head = *stack_b;
		if (head->index == size - 4)
		{
			size--;
			pa(stack_a, stack_b);
		}
		else
		{
			rb(stack_b);
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

void	stack_b_opt(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*iter;
	(void)stack_a;

	iter = *stack_b;
	while (iter && size != (size - 4) / 2)
	{
		if (iter->index == (size - 4) / 2)
			size = iter->index;
		iter = iter->next;
	}
	iter = *stack_b;
	while (iter && size != 0)
	{
		iter = *stack_b;
		if (iter->index >= size)
		{
			size--;
			rrb(stack_b);
		}
		else
			ra(stack_b);
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	
	size = get_size(stack_a);
	push_b(stack_a, stack_b, size);
	three_sort(stack_a);
	display(*stack_b);
	pause();
	stack_b_opt(stack_a, stack_b, size);
	push_a(stack_a, stack_b, size);
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
	stack_b = stack_creat(stack_a);
	if (ft_numeric_cntrl(stack_a))
		exit_fail(&stack_a, &stack_b);
	indexing(&stack_a);
	sort(&stack_a, &stack_b);
	// display(stack_a);
	// display(stack_b);
	// system("leaks push_swap");
	return (0);
}
