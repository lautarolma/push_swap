#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
} t_stack;

int			ft_atoi_safe(const char *s, bool *error);
bool		is_duplicated(t_stack *stack_a, int value);
void		str_manager(char *argv, t_stack **stack_a, char *delim);
void		exit_with_error(t_stack **stack_a);
void		ft_snode_add_back(t_stack **lst, t_stack *new);
t_stack		*ft_snode_new(int content);


#endif
