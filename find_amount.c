#include "push_swap.h"

void	drop_in_b(t_check *check)
{
	t_stack	*stack_a;
	t_check	*copy;

	copy = check;
	stack_a = check->a;
	while (stack_a->size != 5)
	{
		ft_pb(copy);
		stack_a->size--;
	}
}

int	find_nbr_a(t_check *check)
{
	t_check	*stack;
	int		nbr_a;

	nbr_a = 0;
	stack = check;
	while (stack->a->size > 0 && stack->b->nbr > stack->a->nbr)
	{
		stack->a = stack->a->next;
		nbr_a++;
		if (!stack->a->next && stack->b->nbr > stack->a->nbr)
			nbr_a++;
		stack->a->size--;
	}
	return (nbr_a);
}

void	get_list(t_check *check)
{
	int			nbr1;
	t_struct	*struc;
}
