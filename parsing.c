#include "push_swap.h"
#include "libft.h"

//1-Rebuild str_manager with the alocation correct for the int result of atoi_safe.
//2-build a strchr with a string as second parameter
//3-Cc and run strtok with a tester from AI and implement to the program here.
//
void	str_manager(char *arg);
{
	char		*p_token;
	char		*c_token;
	t_list		*head;
	t_list		new_node;

	head = NULL;
	i = 0;
	*p_token = ft_strtok(arg[i], delim);
	if (ft_atoi_safe(p_token))
		c_token = ft_atoi_safe(p_token);
	if (!c_token)
		return (NULL);
	head = ft_lstnew(c_token);1
		if (!head)
			return (NULL);
	}
	while (p_token != NULL)
	{
		*p_token = ft_strtok(NULL, delim);
		add_back = strdup(token);
		token = NULL;
	}
	else
		tmp_lst_creator(arg[i])
	}
	i++;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_atoi_safe(const char *s)
{
	int		sign;
	long	nmb;

	if (!s || !*s)
		return (-1);
	sign = 1;
	if ((*s == '+' || *s == '-'))
	{
		if (!ft_isdigit(*(s + 1))
			return (-1);
		if (*s == '-')
			sign = -1;
	}
	nmb = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (-1);
		nmb = nmb * 10 + (*s - '0');
		if (sign == -1 && -nmb < INT_MIN 
			|| sign == 1 && nmb > INT_MAX)
			return (-1);
		s++;
	}
	return ((int)(nmb * sign));
}
