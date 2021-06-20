#include "push_swap.h"

int	if_sort(t_check *check)
{
	t_stack	*stackk;

	if (!check->a || check->b)
		return (0);
	stackk = check->a;
	while (stackk->next != check->a)
	{
		if (stackk->nbr > stackk->next->nbr)
			return (0);
		stackk = stackk->next;
	}
	return (1);
}

int	if_dups(t_check *check)
{
	t_stack	*stack1;
	t_stack	*stack2;
	int		size;

	size = check->a->size;
	stack1 = check->a;
	while (size--)
	{
		stack2 = stack1->next;
		while ((stack2->next != check->a))
		{
			if (stack1->nbr == stack2->nbr)
				return (1);
			stack2 = stack2->next;
		}
		stack1 = stack1->next;
	}
	return (0);
}

int	sorted(t_check *check)
{
	if (if_dups(check) || if_sort(check))
	{
		return (1);
	}
	return (0);
}
