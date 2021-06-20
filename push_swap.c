#include "push_swap.h"

void	push_swap(t_check *check, int argc, char **argv)
{
	argc = argc - 1;
	if (!sorted(check))
	{
		if (argc <= 5)
			sort_five_or_less(check, argc);
		// else
		// 	sort_anything_else(check);
	}
	else
		ft_putstr("Error\n");
}

int	main(int argc, char **argv)
{
	t_check	*check;
	int		i;

	if (argc < 2)
		return (0);
	i = 1;
	check = (struct s_check *)malloc(sizeof(t_check));
	check->a = add_in_list(argc, argv);
	check->b = NULL;
	push_swap(check, argc, argv);
	while (check->a->next && i < argc)
	{
		printf("%d\n", check->a->nbr);
		check->a = check->a->next;
		i++;
	}
	return (0);
}


	// while (check->b && i < argc)
	// {
	// 	printf("%d\n", check->b->nbr);
	// 	check->b = check->b->next;
	// 	i++;
	// }





// int	main(int argc, char **argv)
// {
// 	t_check	*check;
//     int i;
//    	char *str[3] = {"5", "7", "8"};

//     i = 1;
//     check = (struct s_check *)malloc(sizeof(t_check));
// 	check->a = add_in_list(argc, argv);
// 	// printf("%p\n", check->a);
// 	check->b = NULL;
// 	ft_pb(check);
// 	// ft_sb(check);
// 	while (check->a->next && i < argc)
// 	{
// 		printf("%d\n", check->a->nbr);
// 		check->a = check->a->next;
//         i++;
// 	}
// 	// printf("%d\n", stack_b->num);
// 	// while (check->b && i < argc)
// 	// {
// 	// 	printf("%d\n", check->b->nbr);
// 	// 	check->b = check->b->next;
// 	// 	i++;
// 	// }
// }
