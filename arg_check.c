#include "push_swap.h"

int	is_dig(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_gen_control(char **arv, int ac)
{
	char	**str;
	int	i;

	str = arv + 1;
	if (ac == 2)
		str = ft_split(arv[1], ' ');
	i = 0;
	while (str[i])
	{
		if (is_dig(str[i++]))
			return (1);
	}
	if (ac == 2)
		free_str(str);
	return (0);
}

int	rep_nbr(t_list **stack_a)
{
	t_list	*stack;
	t_list	*stack2;
	int		is;
	
	stack = *stack_a;
	is = 1;
	while (stack)
	{
		stack2 = stack->next;
		while (stack2)
		{
			if (stack->value > stack2->value)
				is = 0;
			if (stack->value == stack2->value)
				exit_fail(stack_a);
			stack2 = stack2->next;
		}
		stack = stack->next;
	}
	return (is);
}


void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	is_sorted(t_list **stack)
{
	t_list	*iter;

	iter = *stack; 
	while (iter && iter->next)
	{
		if (iter->index > iter->next->index)
			iter = iter->next;
		else
			return (0);
	}
	return (1);
}
