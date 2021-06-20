#include "push_swap.h"

int	max_value(t_stack *stack)
{
	int		max;
	t_stack	*end;
	t_stack	*tmp;

	tmp = stack;
	max = tmp->nbr;
	end = stack->previous;
	while (1)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
	return (max);
}

int	find_max(t_check *check, char name)
{
	t_stack	*stack;
	int		res;

	if (name == 'a')
	{
		stack = check->a;
	}
	else
	{
		stack = check->b;
	}
	res = max_value(stack);
	return (res);
}

int	min_value(t_stack *stack)
{
	int		min;
	t_stack	*end;
	t_stack	*tmp;

	tmp = stack;
	min = tmp->nbr;
	end = stack->previous;
	while (1)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
	return (min);
}

int	find_min(t_check *check, char name)
{
	t_stack	*stack;
	int		size;
	int		res;

	if (name == 'a')
	{
		stack = check->a;
	}
	else
	{
		stack = check->b;
	}
	res = min_value(stack);
	return (res);
}
