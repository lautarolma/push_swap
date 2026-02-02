/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:46:14 by laviles           #+#    #+#             */
/*   Updated: 2026/02/02 17:39:36 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chomp_eol(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
	{
		s[len - 1] = '\0';
		len--;
	}
}

static int	build_stack_a(int argc, char *argv[], t_stack **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		arg_manager(argv[i++], a, " ");
		if (!*a)
			return (1);
	}
	return (0);
}

static void	execute_command2(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "rra"))
		rra(a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
	{
		free(line);
		exit_with_error(a);
	}
}

static void	execute_command(char *line, t_stack **a, t_stack **b)
{
	chomp_eol(line);
	if (!ft_strcmp(line, "sa"))
		sa(a);
	else if (!ft_strcmp(line, "sb"))
		sb(b);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa"))
		pa(b, a);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		ra(a);
	else if (!ft_strcmp(line, "rb"))
		rb(b);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b);
	else
		execute_command2(line, a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (build_stack_a(argc, argv, &stack_a) != 0)
		return (1);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_command(line, &stack_a, &stack_b);
		free(line);
	}
	if (it_is_sort(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clean_stack(&stack_a, &stack_b);
	return (0);
}
