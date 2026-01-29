#include "push_swap.h"

static	void execute_command(char *line, t_stack **a, t_stack **b)
{
	if (!strcmp(line, "sa\n")) sa(a);
	else if (!ft_strncmp(line, "sb\n", sizeof(line))) sb(b);
	else if (!strcmp(line, "ss\n")) ss(a, b);
	else if (!strcmp(line, "pa\n")) pa(b, a);
	else if (!strcmp(line, "pb\n")) pb(a, b);
	else if (!strcmp(line, "ra\n")) ra(a);
	else if (!strcmp(line, "rb\n")) rb(b);
	else if (!strcmp(line, "rr\n")) rr(a, b);
	else if (!strcmp(line, "rra\n")) rra(a);
	else if (!strcmp(line, "rrb\n")) rrb(b);
	else if (!strcmp(line, "rrr\n")) rrr(a, b);
	else
	{
		free(line);
		exit_with_error(a);
	}
}

int main(int argc, char *argv[])
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	char    *line;
	int     i = 1;

	if (argc < 2)
		return (0);
	while (i < argc)
	{
		arg_manager(argv[i++], &stack_a, " ");
		if (!stack_a)
			return (1);
	}
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
