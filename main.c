#include "push_swap.h"

void	push_b(t_list **stack_a, t_list **stack_b, int size)
{
	t_list *head;

	printf("%d\n", size - 3);
	head = *stack_a;
	while (head && get_size(stack_a) != 3)
	{
		if (head->index < size - 3)
		{
			pb(stack_a, stack_b);
			head = *stack_a;
		}
		else
			rra(&head);
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b, get_size(stack_a));
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
	while (stack_a)
	{
		printf("stack_a => %d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("stack_b => %d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	// system("leaks push_swap");
	return (0);
}
