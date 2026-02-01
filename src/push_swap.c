/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:48:58 by laviles           #+#    #+#             */
/*   Updated: 2026/01/25 11:34:12 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		arg_manager(argv[i], &stack_a, " ");
		if (!stack_a)
			return (1);
		i++;
	}
	if (it_is_sort(stack_a))
		return (clean_stack(&stack_a, &stack_b), 0);
	ft_nodes_index(stack_a);
	k_sort(&stack_a, &stack_b);
	clean_stack(&stack_a, &stack_b);
	return (0);
}

/*
void	print_stack(t_stack *head)

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
