/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:48:58 by laviles           #+#    #+#             */
/*   Updated: 2026/01/04 05:21:51 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *head)
{
	printf("Stack A: ");
	if (!head)
		printf("(vacío)");
	while (head)
	{
		printf("[%d] ", head->value);
		head = head->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_list *stack_a = NULL;
	int i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < ac)
	{
		str_manager(argv[i], &stack_a);
		i++;
	}
	print_stack(stack_a);
	return (0);
}
