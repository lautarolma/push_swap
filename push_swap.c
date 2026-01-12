/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:48:58 by laviles           #+#    #+#             */
/*   Updated: 2026/01/11 23:48:47 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;
	char	*delim = " ";
	int i;
	i = 1;

	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str_manager(argv[i], &stack_a, delim);
		i++;
	}
	ft_snode_add_back(&stack_b, ft_snode_new(10));
    ft_snode_add_back(&stack_b, ft_snode_new(20));
    ft_snode_add_back(&stack_b, ft_snode_new(30));
	ft_nodes_index(stack_a);
	ft_nodes_index(stack_b);
	printf(" ########################################################################################################### \n");
	printf(" 																						\n");
	printf(" 							Stacks													\n");
	printf("                                                                                        \n");
	printf(" ########################################################################################################### \n");
	print_stack(stack_a);
	print_stack(stack_b);
	printf(" ########################################################################################################### \n");
	printf(" 																											 \n");
	printf("			 				PUSH_A_TO_B													 \n");
	printf("                                                                                                           	 \n");
	printf(" ########################################################################################################### \n");
	push_a_to_b(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	return (0);
}

//1- Control de errores completo. Pendiente de modifi int overflows "Wrong Message".
//2- Estructuracion de la logica algoritmica:
// calcular "ventanas"/rangos de K(valor matematico) segun numero de enteros def if size <= 100 k = 15 / 18, else if
//calcular max index position. get_max_pos
