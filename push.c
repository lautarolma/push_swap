/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:13:00 by laviles           #+#    #+#             */
/*   Updated: 2026/01/09 12:40:52 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_b;
	t_stack	*first_a;
	t_stack	*second_b;
	t_stack	*second_a;
	

	if (!stack_a || !stack_b)
		return ;
	first_a = *stack_a;
	second_a = first_a->next;
	first_b = *stack_b;
	second_b = first_b->next;
	*stack_b = first_a;
	first_a->next = first_b;
	*stack_a = second_a;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
