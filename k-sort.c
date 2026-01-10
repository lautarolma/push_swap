/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:58:10 by laviles           #+#    #+#             */
/*   Updated: 2026/01/10 16:11:41 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	k-sort(t_stack stack_a, t_stack stack_b)
{
	int		i;
	int		size;
	int		k;

	size = ft_stack_size(t_stack *stack_a)
	k = get_k(size);
	while 
}

int		get_k(int n_stack)
{
	if (n_stack <= 10)
		return (2);
	if (n_stack <= 100)
		return (15);
	if (n_stack <= 500)
		return(15 + (n_stack - 100 * (30-15) / (500-100))
	return (30 + (n - 500) / 25);
}
