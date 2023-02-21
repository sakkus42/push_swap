#include "push_swap.h"

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
	rotate(&stack_a);
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
