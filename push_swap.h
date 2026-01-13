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
	int				value;
	int				index;
	struct s_stack	*next;
} t_stack;

int			ft_stack_size(t_stack *stack);
int			get_k(int n_stack);
int			get_pos_of_index(t_stack *stack, int target_index);
int			ft_atoi_safe(const char *s, bool *error);
bool		is_duplicated(t_stack *stack_a, int value);
void		str_manager(char *argv, t_stack **stack_a, char *delim);
void		exit_with_error(t_stack **stack_a);
void		ft_snode_add_back(t_stack **lst, t_stack *new);
void		ft_nodes_index(t_stack *stack);
void		ft_push(t_stack **src, t_stack **dst);
void		pa(t_stack **stack_b, t_stack **stack_a);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ft_swap(t_stack **stack);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rotate(t_stack **stack);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rev_rotate(t_stack **stack);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		push_a_to_b(t_stack **src, t_stack **dst);	
t_stack		*ft_snode_new(int content);
t_stack		*get_next_min(t_stack *stack);
t_stack		*get_next_max(t_stack *stack);

#endif
