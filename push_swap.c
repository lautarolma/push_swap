/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:48:58 by laviles           #+#    #+#             */
/*   Updated: 2026/01/05 16:23:53 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_stack(t_stack *head)
{
	printf("Stack A: ");
	if (!head)
		printf("(vacío)");
	while (head)
	{
		printf("[%d] ", head->content);
		head = head->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a = NULL;
	char	*delim = " ,";
	int i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str_manager(argv[i], &stack_a, delim);
		i++;
	}
	print_stack(stack_a);
	return (0);
}
