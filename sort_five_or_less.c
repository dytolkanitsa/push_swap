#include "push_swap.h"

static void	sort_three(t_check *check)
{
	t_stack	*p;
	t_check	*stack;
	int		max;

	stack = check;
	max = find_max(stack, 'a');
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
	int		max;
	t_check	*stack;
	t_stack	*p;

	stack = check;
	p = stack->a;
	min = find_min(check, 'a');
	while (1)
	{
		if (p->nbr != min)
		{
			ft_ra(stack);
			p = p->next;
		}
		else
			break ;
	}
	ft_pb(stack);
	sort_three(stack);
	ft_pa(stack);
}

static void	sort_five(t_check *check)
{
	int		max;
	int		min;
	t_check	*c;

	c = check;
	min = find_min(check, 'a');
	// printf("<%d>\n", min);
	// while (1)
	// {
	// 	if (stack->nbr != min)
	// 	{
	// 		ft_ra(check);
	// 	}
	// 	else
	// 		break ;
	// }
	// ft_pb(check);
	// sort_four(check);
	// ft_pa(check);
	// // printf("%s\n", "-----");
	ft_pb(c);
	ft_pb(c);
	// printf("<%s>\n", "-------");
	sort_three(c);
	printf("<%d>\n", c->b->nbr);
	printf("<%d>\n", c->a->nbr);
	printf("<%d>\n", c->a->previous->nbr);
	while (1)
	{
		if ((c->b->nbr > c->a->nbr))
		{
			// ft_pa(c);
			ft_ra(c);
			// break ;
		}
		else
		{
			ft_pa(c);
			break ;
		}
	}
	while (1)
	{
		if (c->a->nbr > min)
			ft_rra(c);
		else
			break ;
	}
}

void	sort_five_or_less(t_check *check, int argc)
{
	if (argc == 2)
	{
		if (check->a->nbr > check->a->next->nbr)
			ft_sa(check);
	}
	else if (argc == 3)
		sort_three(check);
	else if (argc == 4)
		sort_four(check);
	else if (argc == 5)
		sort_five(check);
}
