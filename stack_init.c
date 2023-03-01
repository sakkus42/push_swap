/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:04:37 by sakkus            #+#    #+#             */
/*   Updated: 2023/03/01 17:04:39 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!res)
		return (NULL);
	res->index = 0;
	res->value = 0;
	res->position = 0;
	res->target_position = 0;
	res->next = NULL;
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
	stack = new_struct(str[i]);
	res = stack;
	while (str[i])
	{
		if (ft_atoi(str[i]) > INT32_MAX || ft_atoi(str[i]) < INT32_MIN)
			exit_fail(&stack);
		stack->value = (int)ft_atoi(str[i]);
		stack->next = new_struct(str[++i]);
		stack = stack->next;
	}
	if (ac == 2)
		free_str(str);
	return (res);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while ((*stack) != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	exit_fail(t_list **stack_a)
{
	if (stack_a)
		free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}
