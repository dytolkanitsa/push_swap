#include "push_swap.h"

static void	sort_three(t_check *check)
{
	int	max;
	int	i = 0;

	while (check->a->next && i < 3)
	{
		printf("%d\n", check->a->nbr);
		check->a = check->a->next;
        i++;
	}
	max = find_max(check, 'a');
	// printf("<%d>", max);
	if (check->a->nbr == max)
		ft_ra(check);
	if (check->a->next->nbr == max)
		ft_rra(check);
	if (check->a->nbr > check->a->next->nbr)
		ft_sa(check);
}

static void	sort_four(t_check *check)
{
	int		min;
	t_stack	*stack;
	int		size;
	int		max;

	max = find_max(check, 'a');
	size = check->a->size;
	stack = check->a;
	min = find_min(check, 'a');
	// printf("<%d>\n", stack->nbr);
	// printf("<%d>\n", min);
	while (1)
	{
		if (stack->nbr != min)
		{
			ft_ra(check);
		}
		else
			break ;
	}
	ft_pb(check);
	printf("%--s\n", "---");
	if (check->a->nbr == max)
		ft_ra(check);
	if (check->a->next->nbr == max)
		ft_rra(check);
	printf("--%d", check->a->nbr);
	printf("----%d", check->a->next->nbr);
	if (check->a->nbr > check->a->next->nbr)
		ft_sa(check);
	printf("%--s\n", "---");
	ft_pa(check);
	// while (1)
	// {
	// 	if (stack->nbr == min)
	// 		ft_pb(check);
	// 	else if (stack->nbr != min)
	// 		ft_ra(check);
	// 	else
	// 		break ;
	// }
	// ft_pb(check);
	// sort_three(check);
	// ft_pa(check);
}

static void	sort_five(t_check *check)
{
	int		max;
	int		min;
	t_stack	*temp;

	max = find_max(check, 'a');
	min = find_min(check, 'a');
	ft_pb(check);
	ft_pb(check);
	sort_three(check);
	if (check->b->nbr < check->b->next->nbr)
		ft_sb(check);
	ft_pa(check);
	ft_pa(check);
}

void	sort_five_or_less(t_check *check, int argc)
{
	if (argc == 2)
	{
		if (check->a->nbr > check->a->next->nbr)
			ft_sa(check);
	}
	else if (argc == 3)
	// printf("%d", 10);
		sort_three(check);
	else if (argc == 4)
		sort_four(check);
	else if (argc == 5)
		sort_five(check);
}
