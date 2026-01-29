/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:41:33 by laviles           #+#    #+#             */
/*   Updated: 2026/01/25 10:08:36 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack_a == NULL || *stack_a == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	current = *stack_a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack_a = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

void	clean_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b != NULL || *stack_b != NULL)
	{
		free_stack(stack_b);
	}
	if (stack_a != NULL || *stack_a != NULL)
	{
		free_stack(stack_a);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
