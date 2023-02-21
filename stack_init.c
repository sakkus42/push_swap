#include "push_swap.h"

int	get_size(t_list **stack)
{
	t_list	*tmp;
	int		i;

	if (!(*stack))
		return (0);
	tmp = (*stack);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_list	*new_struct(char *str)
{
	t_list	*res;

	if (!str)
		return (NULL);
	res = malloc(sizeof(t_list));
	res->index = 0;
	res->value = 0;
	res->next = NULL;
	return (res);
}

t_list	*stack_creat(t_list *stack_a)
{
	t_list	*head;
	t_list	*res;
	int		i;

	res = NULL;
	head = res;
	i = get_size(&stack_a);
	while (i--)
	{
		res = new_struct("a");
		res = res->next;
	}
	return (head);
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
	stack = new_struct(str[i]);
	res = stack;
	while (str[i])
	{
		if (ft_atoi(str[i]) > INT32_MAX || ft_atoi(str[i]) < INT32_MIN)
			exit_fail(&stack, 0);
		stack->value = (int)ft_atoi(str[i]);
		stack->next = new_struct(str[++i]);
		stack = stack->next;
	}
	if (ac == 2)
		free_str(str);
	return (res);
}
