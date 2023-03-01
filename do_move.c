/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:51 by sakkus            #+#    #+#             */
/*   Updated: 2023/03/01 16:30:53 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	again_rev_rotate(t_list **stack_a, t_list **stack_b,
											int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	again_rotate(t_list **stack_a, t_list **stack_b,
										int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	again_rot_a(t_list **stack, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			rra(stack);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			ra(stack);
			(*cost)--;
		}
	}
}

void	again_rot_b(t_list **stack, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			rrb(stack);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			rb(stack);
			(*cost)--;
		}
	}
}

void	do_move(t_list **stack_a, t_list **stack_b,
								int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		again_rev_rotate(stack_a, stack_b, &cost_a, &cost_b);
	if (cost_a > 0 && cost_b > 0)
		again_rotate(stack_a, stack_b, &cost_a, &cost_b);
	again_rot_a(stack_a, &cost_a);
	again_rot_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}
