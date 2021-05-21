#include "push_swap.h"

int	min_value(t_stack *stack, int size)
{
	int		temp;
	int		res;

	temp = 1;
	res = stack->nbr;
	while (temp <= size)
	{
		if (stack->nbr < res)
			res = stack->nbr;
		stack = stack->next;
		temp++;
	}
	return (res);
}

int	find_min(t_check *check, char name)
{
	t_stack	*stack;
	int		size;
	int		res;

	if (name == 'a')
	{
		stack = check->a;
		size = check->a->size;
	}
	else
	{
		stack = check->b;
		size = check->b->size;
	}
	res = min_value(stack, size);
	return (res);
}
