#include "libft.h"
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	void	*content;
	int		index;
	void	*next;
	t_list;
}

int		ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

#endif
