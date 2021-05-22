#include "push_swap.h"

t_stack	*ft_lstnew(int nbr, t_stack *previous)
{
	t_stack	*list;

	list = (struct s_stack *)malloc(sizeof(t_stack));
	if (list == NULL)
		return (NULL);
	list->nbr = nbr;
	list->next = NULL;
	list->previous = previous;
	return (list);
}

t_stack	*add_in_list(int argc, char **str)
{
	t_stack	*newlist;
	t_stack	*head;
	int		i;

	i = 2;
	head = ft_lstnew(ft_atoi(str[1]), NULL);
	// if (head == 0)
	// 	return (0);
	newlist = head;
	while (i < argc)
	{
		newlist->next = ft_lstnew(ft_atoi(str[i]), newlist);
		newlist = newlist->next;
		i++;
	}
	head->size = i - 1;
	newlist->next = head;
	head->previous = newlist;
	return (head);
}

int	max_value(t_stack *stack)
{
	int		max;
	t_stack	*end;
	t_stack	*tmp;

	tmp = stack;
	max = tmp->nbr;
	end = stack->previous;
	while (1)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
	return (max);
}

int	find_max(t_check *check, char name)
{
	t_stack	*stack;
	int		res;

	if (name == 'a')
	{
		stack = check->a;
	}
	else
	{
		stack = check->b;
	}
	res = max_value(stack);
	return (res);
}
