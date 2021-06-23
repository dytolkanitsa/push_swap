#include "push_swap.h"

t_stack	*ft_lstnew(int nbr, t_stack *previous)
{
	t_stack	*list;

	list = (struct s_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->nbr = nbr;
	list->next = NULL;
	list->previous = previous;
	return (list);
}

static void	for_add_in_list(char **str, t_stack **head_pointer, \
						 t_stack *newlist, int argc)
{
	int			size;
	t_stack		*head;
	int			i;

	i = 2;
	head = *head_pointer;
	size = 1;
	while (i < argc)
	{
		newlist->next = ft_lstnew(ft_atoi(str[i]), newlist);
		newlist = newlist->next;
		i++;
		size++;
	}
	head->size = size;
	newlist->next = head;
	head->previous = newlist;
	*head_pointer = head;
}

t_stack	*add_in_list(int argc, char **str)
{
	t_stack	*newlist;
	t_stack	*head;

	head = ft_lstnew(ft_atoi(str[1]), NULL);
	newlist = head;
	if (!check_argument(argc, str))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	else
		for_add_in_list(str, &head, newlist, argc);
	return (head);
}

int	ft_lstsize(t_check *check)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = check->a;
	if (head)
	{
		while (head != check->a)
		{
			head = head->next;
			i++;
		}
	}
	return (i);
}
