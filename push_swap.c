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

static t_stack	*add_in_list(int argc, char **str)
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

int	main(int argc, char **argv)
{
	t_check	*check;
    int i;
   	char *str[3] = {"5", "7", "8"};

    i = 1;
    check = (struct s_check *)malloc(sizeof(t_check));
	check->a = add_in_list(argc, argv);
	// check->b = add_in_list(argc, argv);
	ft_rra(check);
	// ft_sb(check);
	printf("-------\n");
	while (check->a->next && i < argc)
	{
		printf("%d\n", check->a->nbr);
		check->a = check->a->next;
        i++;
	}
// 	printf("%d\n", stack_b->num);
// 	while (check->b && i < argc)
// 	{
// 		printf("%d\n", check->b->nbr);
// 		check->b = check->b->next;
// 		i++;
// 	}
}
