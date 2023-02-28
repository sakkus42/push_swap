#include "push_swap.h"

int	ft_control(char **arv)
{
	int	i;
	int	k;

	i = 0;
	while (arv[i])
	{
		k = 0;
		if (arv[i][k] == '-' || arv[i][k] == '+')
			k++;
		while (arv[i][k])
		{
			if (arv[i][k] <= '9' && arv[i][k] >= '0')
				k++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_gen_control(char **arv, int ac)
{
	char	**str;
	int	is;
	int	i;

	is = 0;
	str = 0;
	if (ac == 2)
	{
		str = ft_split(arv[1], ' ');
		if (ft_control(str))
			is = 1;
		i = 0;
		while (str[i])
			i++;
		free_str(str);
		if (i == 1)
			exit (1);
	}
	else if (ft_control(arv + 1))
		is = 1;
	return (is);
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
