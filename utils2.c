#include "push_swap.h"

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*list;

	list = (struct s_stack *)malloc(sizeof(t_stack));
	if (list == NULL)
		return (NULL);
	list->nbr = nbr;
	list->next = list;
	list->previous = list;
	return (list);
}

t_stack	*add_in_list(int argc, char **str)
{
	t_stack	*newlist;
	t_stack	*head;
	int		i;

	i = 1;
	newlist = ft_lstnew(0);
	head = newlist;
	if (newlist == 0)
		return (0);
	while (i < argc)
	{
		newlist->nbr = ft_atoi(str[i]);
		if (i != argc - 1)
			newlist->next = ft_lstnew(0);
		newlist = newlist->next;
		i++;
	}
	head->size = i - 1;
	head->previous = newlist;
	head->previous->next = head;
	return (head);
}

int	max_value(t_stack *stack, int size)
{
	int		temp;
	int		res;

	temp = 1;
	res = stack->nbr;
	while (temp <= size)
	{
		if (stack->nbr > res)
			res = stack->nbr;
		stack = stack->next;
		temp++;
	}
	return (res);
}

int	find_max(t_check *check, char name)
{
	t_stack	*stack;
	int		size;
	int		res;

	if (name == 'a')
	{
		stack = check->a;
		size = check->a->size;
	}
	else
	{
		stack = check->b;
		size = check->b->size;
	}
	res = max_value(stack, size);
	return (res);
}
