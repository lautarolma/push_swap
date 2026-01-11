/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:58:10 by laviles           #+#    #+#             */
/*   Updated: 2026/01/11 11:17:51 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		size;
	int		k;

	i = 0;
	size = ft_stack_size(*stack_a);
	k = get_k(size);
	while (*stack_a)
	{
		if ((*stack_a)->index <= k)
		{
			pa(stack_a, stack_b);
			i++;
		}
		else if ((*stack_b)->index <= (k + i) && (*stack_a)->index > k)
		{
			rr(stack_a, stack_b);
			i++;
		}
		else if ((*stack_b)->index <= (k + i))
		{
			ra(stack_a);
			i++;
		}
	}
}

int		get_k(int n_stack)
{
	if (n_stack <= 10)
		return (2);
	if (n_stack <= 100)
		return (15);
	if (n_stack <= 500)
		return(15 + (n_stack - 100 * (30-15) / (500-100)));
	return (30 + (n_stack - 500) / 25);
}
