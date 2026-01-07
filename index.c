/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:30:51 by laviles           #+#    #+#             */
/*   Updated: 2026/01/07 16:40:02 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_next_min(t_stack *stack)
{
	t_stack		*min_value;
	t_stack		*current;

	current = stack;
	min_value = NULL;
	while (current)
	{
		if ((current->index == -1) && (!min_value || current->value < min_value->value))
			min_value = current;	
		current = current->next;
	}
	return (min_value);
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
