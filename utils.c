/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:37:35 by laviles           #+#    #+#             */
/*   Updated: 2026/01/13 14:05:03 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_snode_new(int nb)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = nb;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	ft_snode_add_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

int		ft_stack_size(t_stack *stack)
{
	int		size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int		get_pos_of_index(t_stack *stack, int target_index)
{
	int		pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return(pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
