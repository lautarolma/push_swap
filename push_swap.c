/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:48:58 by laviles           #+#    #+#             */
/*   Updated: 2026/01/13 14:30:27 by laviles          ###   ########.fr       */
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
	int 	i;
	int		max_index_pos;
	int		size;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str_manager(argv[i], &stack_a, delim);
		i++;
	}
	ft_nodes_index(stack_a);
	push_a_to_b(&stack_a, &stack_b);
	printf("stack_a·\n");
	printf("stack_b\n");
	size = (ft_stack_size(stack_b)- 1);
	print_stack(stack_b);
	rb(&stack_b);
	max_index_pos = get_pos_of_index(stack_b, size);
	printf("max index position%d", max_index_pos);
	
	return (0);
}

//1- Control de errores completo. Pendiente de modifi int overflows "Wrong Message".
//2- Estructuracion de la logica algoritmica:
// calcular "ventanas"/rangos de K(valor matematico) segun numero de enteros def if size <= 100 k = 15 / 18, else if
//calcular max index position. get_max_pos
