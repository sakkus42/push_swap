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

int	ft_numeric_cntrl(t_list *stack_a)
{
	t_list	*stack;
	t_list	*stack2;

	stack = stack_a;
	while (stack)
	{
		stack2 = stack->next;
		while (stack2)
		{
			if (stack->value > stack2->value)
				return (0);
			if (stack->value == stack2->value)
				return (1);
			stack2 = stack2->next;
		}
		stack = stack->next;
	}
	return (1);
}


void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}