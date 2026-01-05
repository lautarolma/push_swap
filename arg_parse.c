#include "push_swap.h"
#include "libft/libft.h"

int	ft_atoi_safe(const char *s, bool *error)
{
	int		sign;
	long	nmb;

	if (!s || !*s)
		return (0);
	sign = 1;
	if ((*s == '+' || *s == '-'))
		if (*s++ == '-')
			sign = -1;
	if (!*s)
		return (*error = true, 0);
	nmb = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (*error = true, 0);
		nmb = nmb * 10 + (*s++ - '0');
		if ((sign == -1 && -nmb < INT_MIN) 
			|| (sign == 1 && nmb > INT_MAX))
			return (*error = true, write(2, "Number out of range\n", 20), 0);
	}
	return ((int)(nmb * sign));
}

bool	is_duplicated(t_list *stack_a, int nb)	
{
	while (stack_a)
	{
		if (stack_a->content == nb)
			return (true);
		stack_a = stack_a->next;
	}
	return (false);
}

void	str_manager(char *argv, t_list **stack_a, char *delim)
{
	char		*token;
	int			nb;
	bool		error;

	error = false;
	token = ft_strtok(argv, delim);
	while (token != NULL && !error)
	{
		nb = ft_atoi_safe(token, &error);
		if (!error)
		{
			if (is_duplicated(*stack_a, nb))
				error = true;
			else
				ft_lstadd_back(stack_a, ft_lstnew(nb));
		}
		token = ft_strtok(NULL, delim);
	}
	if (error)
		exit_with_error(stack_a);
}

void	exit_with_error(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*current;

	if (stack_a == NULL || *stack_a == NULL)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
	current = *stack_a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack_a = NULL;
	write(2, "Error\n", 6);
	exit(1);
}
