#include "push_swap.h"

// void	display(t_list *stack_a)
// {
// 	while (stack_a)
// 	{
// 		printf("stack_a => %d\n", stack_a->index);
// 		stack_a = stack_a->next;
// 	}
// }

// void	three_sort(t_list **stack_a)
// {
// 	if (ft_numeric_cntrl(*stack_a))
// 		return ;
// 	if ((*stack_a)->index > (*stack_a)->next->index)
// 		sa(stack_a);
// 	if ((*stack_a)->next->index > (*stack_a)->next->next->index)
// 	{
// 		sa(stack_a);
// 		ra(stack_a);
// 	}
// 	three_sort(stack_a);
// }


// void	sort(t_list **stack_a, t_list **stack_b)
// {
	
// }


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
	// sort(&stack_a, &stack_b);
	// display(stack_a);
	// display(stack_b);
	// system("leaks push_swap");
	return (0);
}
