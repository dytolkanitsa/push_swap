#include "push_swap.h"

static void	sort_three(t_check *check, int max)
{
	// int	max;
	t_stack *p;
	t_check *stack;

	stack = check;
	p = stack->a;
	if (stack->a->nbr == max)
		ft_ra(stack);
	if (stack->a->next->nbr == max)
		ft_rra(stack);
	if (stack->a->nbr > stack->a->next->nbr)
		ft_sa(stack);
}

static void	sort_four(t_check *check)
{
	int		min;
	t_stack	*stack;
	int		max;

	max = find_max(check, 'a');
	stack = check->a;
	min = find_min(check, 'a');
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
	sort_three(check, max);
	ft_pa(check);
}

static void	sort_five(t_check *check)
{
	int		max;
	int		min;
	t_stack	*stack;

	min = find_min(check, 'a');
	stack = check->a;
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
	sort_four(check);
	// printf("%s\n", "-----");
	// while (1)
	// {
	// 	if (check->a->nbr < check->b->nbr)
	// 	{
	// 		ft_pa(check);
	// 		// ft_rb(check);
	// 	}
	// 	else if (check->a->nbr < check->b->nbr)
	// 		ft_ra(check);
	// 	else
	// 		break ;
	// }
}

void	sort_five_or_less(t_check *check, int argc)
{
	int		max;

	max = find_max(check, 'a');
	if (argc == 2)
	{
		if (check->a->nbr > check->a->next->nbr)
			ft_sa(check);
	}
	else if (argc == 3)
		sort_three(check, max);
	else if (argc == 4)
		sort_four(check);
	else if (argc == 5)
		sort_five(check);
}
