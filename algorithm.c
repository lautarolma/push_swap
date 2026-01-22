/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:58:10 by laviles           #+#    #+#             */
/*   Updated: 2026/01/15 12:46:58 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int		first;
	int		second;
	int 	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (it_is_sort(*stack_a) == false)
	{
		if (first == 1)
		{
			sa(stack_a);
			ra(stack_a);
		}
		if (first == 2 && second == 3)
			rra(stack_a);
		if (first == 3 && second == 1)
			ra(stack_a);
		if (second == 2)
		{
			sa(stack_a);
			rra(stack_a);
		}
		if (third == 3)
			sa(stack_a);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*min;
	int			pos;
	int			size;

	while (size >= 3)
	{
		size = ft_stack_size(*stack_a);
		min = get_next_min(*stack_a);
		pos = get_pos_of_index(*stack_a, min->index);
		if ((*stack_a)->index == min->index)
			pb(stack_a, stack_b);
		else if (pos <= (size / 2))
			rb(stack_a);
		else
			rrb(stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	k_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_a_to_b(stack_a, stack_b);
	push_b_to_a(stack_b, stack_a);
}

void	push_a_to_b(t_stack **src, t_stack **dst)
{
	int		i;
	int		size;
	int		k;

	i = 0;
	size = ft_stack_size(*src);
	k = get_k(size);
	while (*src)
	{
		if ((*src)->index >= (k + i))
			ra(src);
		else if ((*src)->index <= i)
		{
			pb(src, dst);
			if (*src && (*src)->index > (k + i))
				rr(src, dst);
			else
				rb(dst);
			i++;
		}
		else if ((*src)->index <= (k + i))
		{
			pb(src, dst);
			i++;
		}
	}
}

void	push_b_to_a(t_stack **src, t_stack **dst)
{
	t_stack	*max_index;
	int		pos;
	
	while (*src)
	{
		max_index = get_next_max(*src);
		pos = get_pos_of_index(*src, max_index->index);
		while(*src != max_index)
		{
			if ((*src)->index == max_index->index - 1)
				pa(src, dst);
			else if (pos <= (ft_stack_size(*src) / 2))
				rb(src);
			else
				rrb(src);
 		}
		pa(src, dst);
		if ((*dst)->next && (*dst)->index > (*dst)->next->index)
			sa(dst);
	}
}
