#include "push_swap.h"

void	exit_fail(t_list **stack_a, t_list **stack_b)
{
	if (!(stack_a) && !(stack_b))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	write(1, "Error\n", 6);
	exit(1);
}

t_list	*new_stack(char *str)
{
	t_list	*res;

	if (!str)
		return (NULL);
	res = malloc(sizeof(t_list));
	res->index = 0;
	res->value = 0;
	return (res);
}

t_list	*fill_to_stack(char **arv, int ac)
{
	t_list	*stack;
	t_list	*res;
	char	**str;
	int		i;
	str = arv;
	if (ac == 2)
		str = ft_split(arv[0], ' ');
	i = 0;
	stack = new_stack(str[i]);
	res = stack;
	while (str[i])
	{
		if (ft_atoi(str[i]) > INT32_MAX || ft_atoi(str[i]) < INT32_MIN)
			exit_fail(&stack, 0);
		stack->value = (int)ft_atoi(str[i]);
		stack->next = new_stack(str[++i]);
		stack = stack->next;
	}
	if (ac == 2)
		free(str);
	return (res);
}

// int	main(int ac, char *arv[])	
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;

// 	if (ac == 1)
// 		return (0);
// 	if (ft_gen_control(arv, ac))
// 		exit_fail(NULL, NULL);
// 	stack_b = NULL;
// 	stack_a =  fill_to_stack(arv + 1, ac);
// 	while (stack_a)
// 	{
// 		printf("%d\n", stack_a->value);
// 		stack_a = stack_a->next;
// 	}
// 	return (0);
// }
