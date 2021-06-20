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
	int		min;
	t_check	*c;

	c = check;
	min = find_min(check, 'a');
	while (1)
	{
		if (c->a->nbr != min)
		{
			ft_ra(c);
			c->a = c->a->next;
		}
		else
			break ;
	}
	ft_pb(c);
	sort_four(c);
	ft_pa(c);
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
