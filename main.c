/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:24:43 by sakkus            #+#    #+#             */
/*   Updated: 2023/03/01 16:24:45 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **stack_a)
{
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->index > (*stack_a)->next->next->index
		&& (*stack_a)->index > (*stack_a)->next->index)
		ra(stack_a);
	else if ((*stack_a)->index < (*stack_a)->next->next->index
		&& (*stack_a)->index < (*stack_a)->next->index)
		rra(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->next->index
		&& (*stack_a)->index < (*stack_a)->next->index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	up_to_3(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = get_size(stack_a);
	i = 0;
	pushed = 0;
	while (size > 5 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	shift_stack(t_list **stack_a)
{
	int		pos;
	int		size;

	size = get_size(stack_a);
	set_pos(stack_a);
	pos = get_low_pos(stack_a);
	if (pos > size / 2)
	{
		while (pos < size)
		{
			rra(stack_a);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	up_to_3(stack_a, stack_b);
	three_sort(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		set_cost(stack_a, stack_b);
		do_chp_move(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		shift_stack(stack_a);
}

int	main(int ac, char *arv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		return (0);
	if (ft_gen_control(arv, ac))
		exit_fail(NULL);
	stack_a = fill_to_stack(arv + 1, ac);
	stack_b = NULL;
	if (rep_nbr(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	indexing(&stack_a);
	if (get_size(&stack_a) == 2)
		sa(&stack_a);
	else if (get_size(&stack_a) == 3)
		three_sort(&stack_a);
	else
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
