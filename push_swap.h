#include "libft.h"
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
} t_list;

int		ft_atoi_safe(const char *s, bool *error);
void	str_manager(char *argv, t_list **stack_a, char *delim);
bool	is_duplicated(t_list stack_a, int value);
void	exit_with_error(t_list stack_a);

#endif
