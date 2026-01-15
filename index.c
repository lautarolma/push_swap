/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:30:51 by laviles           #+#    #+#             */
/*   Updated: 2026/01/15 08:55:15 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_next_min(t_stack *stack)
{
	t_stack		*min_index;
	t_stack		*current;

	current = stack;
	min_index = NULL;
	while (current)
	{
		if ((current->index == -1) && (!min_index || current->value < min_index->value))
			min_index = current;	
		current = current->next;
	}
	return (min_index);
}

void	ft_nodes_index(t_stack *stack)
{
	int		i;
	int		size;
	t_stack *node;

	i = 0;
	size = ft_stack_size(stack);
	while (i < size)
	{
		node = get_next_min(stack);
		if (node)
			node->index = i;
		i++;
	}
}

t_stack	*get_next_max(t_stack *stack)
{
	t_stack		*max_index;
	t_stack		*current;

	current = stack;
	max_index = NULL;
	while (current)
	{
		if (!max_index || current->index > max_index->index)
			max_index = current;	
		current = current->next;
	}
	return (max_index);
}
