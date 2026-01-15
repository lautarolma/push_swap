/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:48:58 by laviles           #+#    #+#             */
/*   Updated: 2026/01/15 17:13:50 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;
	char	*delim = " ";
	int 	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str_manager(argv[i], &stack_a, delim);
		i++;
	}
	if (it_is_sort(stack_a) == false)
	{
		ft_nodes_index(stack_a);
		push_a_to_b(&stack_a, &stack_b);
		push_b_to_a(&stack_b, &stack_a);
	}
	return (0);
}

bool	it_is_sort(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->value < stack_a->next->value)
			stack_a = stack_a->next;
		else
			return (false);
	}
	return (true);
}

/*
void	print_stack(t_stack *head)
{
	int		i;

	i = 0;
	printf("Stack :\n");
	if (!head)
		printf("(vacío)");
	while (head)
	{
		printf("Node%d Value[%d] Index[%d]\n", i++, head->value, head->index);
		head = head->next;
	}
	printf("\n");
}*/
