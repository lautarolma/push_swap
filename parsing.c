#include "push_swap.h"

char	*ft_strtok(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] >= 7 && arg[i] <= 13 || arg[i] == 32)
			i++;
		else if 
	
}



void	str_manager(char *arg);
{
	char		*token;
	char		*delim;
	t_list		*head;
	t_list		new_node;
	int			i;

	head = NULL;
	i = 0;
	while (arg[i++])
	{
		while (arg[i][j++])
		{
			if(ft_strchr(arg[i][j]))
			{
					*token = ft_strtok(arg[i], delim);
					head = token;
			}
				while (token != NULL)
				{
					*token = ft_strtok(arg[i]);
					new_node.content = strdup(token);
					token = NULL;
					:w
				}
			else
				tmp_lst_creator(arg[i])
		}
		i++;
	}
}

t_list	tmp_lst_creator(char *argv)
{
	char		**head;
	char		*next;
	char		*prev;
	t_lis		node;
	int			i;

	while(argv[i][0])
	{
		node.content = get_next_nbr(argv[i]);
		node.index = get_index(node.content, token_counter)
	if (!node.content)
		return (0);
	node.next = NULL;
	i++;
}
