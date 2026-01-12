/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:58:10 by laviles           #+#    #+#             */
/*   Updated: 2026/01/12 14:33:40 by laviles          ###   ########.fr       */
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
	while ((*src)->next != NULL)
	{
		if ((*src)->index >= (k + i))
			ra(src);
		else if ((*src)->index <= i)
		{
			pb(src, dst);
			if (*src != NULL && (*src)->index >= (k + i))
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
		return(15 + (n_stack - 100 * (30-15) / (500-100)));
	return (30 + (n_stack - 500) / 25);
}
