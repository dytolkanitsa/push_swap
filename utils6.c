#include "push_swap.h"

void	for_find_am_5(t_check *check, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	check->min_num_a = find_min(check, 'a');
	check->max_num_a = find_max(check, 'a');
	if ((*stack_b)->nbr < check->min_num_a || \
					(*stack_b)->nbr > check->max_num_a)
	{
		while ((*stack_a)->nbr != check->min_num_a)
		{
			(*stack_a) = (*stack_a)->next;
			check->num1++;
		}
	}
	if (check->num1 == 0)
		for_find_am_1(check, stack_a, stack_b);
	if (check->num1 == 0)
		for_find_am_2(check, stack_a, stack_b);
	for_find_am_3(check);
	ft_pa(check);
	(*stack_b) = (*stack_b)->next;
	check->size_a++;
	check->size_b--;
	(*stack_a) = (*stack_a)->previous;
}

void	init_get_com(t_check *check)
{
	check->nbr_a = 0;
	check->min_num_a = find_min(check, 'a');
	check->min_num_b = find_min(check, 'b');
	check->max_num = find_max(check, 'a');
}

void	for_get_com_1(t_check *check, t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_check	*stack;

	stack = check;
	if (check->nbr_a == 0 && ((*stack_b)->nbr < check->min_num_a \
								|| (*stack_b)->nbr > check->max_num))
	{
		while ((*stack_a)->nbr != check->min_num_a)
		{
			(*stack_a) = (*stack_a)->next;
			check->nbr_a++;
		}
	}
	i = 0;
	if (check->nbr_a == 0)
	{
		while (i < stack->size_a && (*stack_b)->nbr > (*stack_a)->nbr)
		{
			(*stack_a) = (*stack_a)->next;
			check->nbr_a++;
			if (i == stack->size_a && (*stack_b)->nbr > (*stack_a)->nbr)
				check->nbr_a++;
			i++;
		}
	}
}
