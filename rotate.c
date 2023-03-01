/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:04:22 by sakkus            #+#    #+#             */
/*   Updated: 2023/03/01 17:04:23 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	head = (*stack);
	*stack = (*stack)->next;
	head->next = NULL;
	tmp->next = head;
}

void	ra(t_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
