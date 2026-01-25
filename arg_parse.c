/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:35:27 by laviles           #+#    #+#             */
/*   Updated: 2026/01/24 18:40:17 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (((sign == -1) && (-nmb < INT_MIN))
			|| ((sign == 1) && (nmb > INT_MAX)))
			return (*error = true, 0);
	}
	return ((int)(nmb * sign));
}

bool	is_duplicated(t_stack *stack_a, int nb)
{
	while (stack_a)
	{
		if (stack_a->value == nb)
			return (true);
		stack_a = stack_a->next;
	}
	return (false);
}

void	arg_manager(char *argv, t_stack **stack_a, char *delim)
{
	char		*token;
	int			nb;
	bool		error;

	error = false;
	token = ft_strtok(argv, delim);
	if (!token)
		error = true;
	while (token != NULL && !error)
	{
		nb = ft_atoi_safe(token, &error);
		if (!error)
		{
			if (is_duplicated(*stack_a, nb))
				error = true;
			else
				ft_snode_add_back(stack_a, ft_snode_new(nb));
		}
		token = ft_strtok(NULL, delim);
	}
	if (error)
		exit_with_error(stack_a);
}
