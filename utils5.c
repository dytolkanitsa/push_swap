#include "push_swap.h"

void	ft_init_and_move(t_check *check, t_stack **stack_a, \
										t_stack **stack_b, int *temp)
{
	check->num1 = 0;
	check->size_b = check->a->size - 5;
	while (check->size_a != 5)
	{
		ft_pb(check);
		check->size_a--;
	}
	sort_five(check);
	(*stack_a) = check->a;
	(*stack_b) = check->b;
	*temp = check->size_b;
}

void	for_find_am_1(t_check *check, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (!((*stack_a)->nbr == check->min_num_a && \
					(*stack_b)->nbr > check->max_num_a))
	{	
		i = 0;
		while (i < check->size_a && (*stack_b)->nbr > (*stack_a)->nbr)
		{
			(*stack_a) = (*stack_a)->next;
			check->num1++;
			if (i == check->size_a && (*stack_b)->nbr > (*stack_a)->nbr)
				check->num1++;
			i++;
		}
	}
}

void	for_find_am_2(t_check *check, t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->nbr < (*stack_a)->nbr && (*stack_b)->nbr > check->min_num_a)
	{
		while ((*stack_b)->nbr < (*stack_a)->nbr)
		{
			(*stack_a) = (*stack_a)->next;
			check->num1++;
		}
		while ((*stack_b)->nbr > (*stack_a)->nbr)
		{
			(*stack_a) = (*stack_a)->next;
			check->po++;
		}
		check->num1 = check->num1 + check->po;
	}
}

void	for_find_am_3(t_check *check)
{
	if (check->num2 < check->size_b / 2)
	{
		while (check->num2--)
			ft_rb(check);
	}
	else
	{
		check->num2 = check->size_b - check->num2;
		while (check->num2--)
			ft_rrb(check);
	}
	if (check->num1 < check->size_a / 2)
	{
		while (check->num1--)
			ft_ra(check);
	}
	else
	{
		check->num1 = check->size_a - check->num1;
		while (check->num1--)
			ft_rra(check);
	}
}

void	for_find_am_4(t_check *check, t_stack **stack_b)
{
	int	i;

	check->num1 = 0;
	get_commands(check);
	i = 0;
	check->po = 0;
	check->num2 = first_min(check);
	while (i != check->num2)
	{
		(*stack_b) = (*stack_b)->next;
		i++;
	}
}
