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

int		get_k(int n_stack)
{
	if (n_stack <= 10)
		return (2);
	if (n_stack <= 100)
		return (15);
	if (n_stack <= 500)
		return(35);
	return (45);
}

void	push_b_to_a(t_stack **src, t_stack **dst)
{
	t_stack	*max_index;
	int		size;
	int		max_pos;
	

	while (*src)
	{
		size = ft_stack_size(*src);
		max_index = get_next_max(*src);
		max_pos = get_pos_of_index(*src, max_index->index);
		while(max_index != *src)
		{
			if (max_pos <= (size / 2))
				rb(src);
			else
				rrb(src);
			max_pos--;
 		}
		pa(src, dst);
	}
}
