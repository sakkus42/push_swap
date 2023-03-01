/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:32:41 by sakkus            #+#    #+#             */
/*   Updated: 2023/03/01 16:32:43 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int	*index, int len)
{
	int	k;
	int	i;
	int	tmp;

	i = 0;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (index[i] > index[k])
			{
				tmp = index[i];
				index[i] = index[k];
				index[k] = tmp;
			}
			k++;
		}
		i++;
	}
}

int	*creat_array(t_list **stack)
{
	int	size;
	int	*index;

	size = get_size(stack);
	index = malloc(sizeof(int) * size);
	if (!index)
		exit(1);
	return (index);
}

void	fill_to_array(t_list **stack, int	*index)
{
	t_list	*iter;
	int		i;

	i = 0;
	iter = *stack;
	while (iter)
	{
		index[i++] = iter->value;
		iter = iter->next;
	}
}

void	indexing(t_list **stack)
{
	t_list	*iter;
	int		*index;
	int		i;
	int		size;

	index = creat_array(stack);
	iter = *stack;
	size = get_size(stack);
	fill_to_array(stack, index);
	sort_array(index, size);
	iter = *stack;
	i = 0;
	while (iter && i < size)
	{
		if (iter->value == index[i])
		{
			iter->index = i;
			iter = *stack;
			i++;
		}
		else
			iter = iter->next;
	}
	free(index);
}

int	get_low_pos(t_list **stack)
{
	t_list	*iter;
	int		indx;
	int		pos;

	set_pos(stack);
	indx = INT32_MAX;
	iter = *stack;
	while (iter)
	{
		if (iter->index < indx)
		{
			indx = iter->index;
			pos = iter->position;
		}
		iter = iter->next;
	}
	return (pos);
}
