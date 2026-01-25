/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:58:10 by laviles           #+#    #+#             */
/*   Updated: 2026/01/25 11:28:21 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (it_is_sort(*stack_a))
		return ;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && first > third)
		ra(stack_a);
	else if (second > first && second > third)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		pos;
	int		size;

	while (ft_stack_size(*stack_a) > 3)
	{
		size = ft_stack_size(*stack_a);
		min = get_min_index(*stack_a);
		pos = get_pos_of_index(*stack_a, min->index);
		if ((*stack_a)->index == min->index)
			pb(stack_a, stack_b);
		else if (pos <= (size / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_three(stack_a);
	while (ft_stack_size(*stack_b) > 0)
	{
		pa(stack_b, stack_a);
		ft_stack_size(*stack_b);
	}
}

void	k_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) <= 3)
		sort_three(stack_a);
	else if (ft_stack_size(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else
	{
		push_a_to_b(stack_a, stack_b);
		push_b_to_a(stack_b, stack_a);
	}
}

void	push_a_to_b(t_stack **src, t_stack **dst)
{
	int		i;
	int		k;

	i = 0;
	k = get_k(ft_stack_size(*src));
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
		max_index = get_max_index(*src);
		pos = get_pos_of_index(*src, max_index->index);
		while (*src != max_index)
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
