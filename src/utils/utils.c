/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:37:35 by laviles           #+#    #+#             */
/*   Updated: 2026/01/25 10:11:46 by laviles          ###   ########.fr       */
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

int	ft_stack_size(t_stack *stack)
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

int	get_k(int n_stack)
{
	if (n_stack <= 10)
		return (2);
	if (n_stack <= 100)
		return (15);
	if (n_stack <= 500)
		return (35);
	return (45);
}

bool	it_is_sort(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (!stack_a)
			return (true);
		if (stack_a->value < stack_a->next->value)
			stack_a = stack_a->next;
		else
			return (false);
	}
	return (true);
}
