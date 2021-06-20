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
	int		size;

	i = 2;
	head = ft_lstnew(ft_atoi(str[1]), NULL);
	size = 1;
	newlist = head;
	if (!check_argument(argc, str))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	else
	{
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
	}
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

t_struct	*ft_lstnew2(t_struct *struc)
{
	t_struct	*list;

	list = (struct s_struct *)malloc(sizeof(t_struct));
	if (list == NULL)
		return (NULL);
	list->nbr1 = struc->nbr1;
	list->nbr2 = struc->nbr2;
	list->next = NULL;
	return (list);
}
