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
			return (0); // не отсортирован
		stackk = stackk->next;
	}
	return (1); // отсортирован
}

int	if_dups(t_check *check)
{
	t_stack	*stack1;
	t_stack	*stack2;
	int		size; // для общего стэка

	size = check->a->size;
	stack1 = check->a;
	while (size--)
	{
		stack2 = stack1->next;
		while ((stack2->next != check->a))
		{
			if (stack1->nbr == stack2->nbr)
				return (1); // есть дубликат
			stack2 = stack2->next;
		}
		stack1 = stack1->next;
	}
	return (0); // нет дубликата
}
// {
// 	t_stack	*stack1;
// 	int		duplicate;
// 	int		size; // для общего стэка

// 	size = check->a->size;
// 	duplicate = check->a->nbr;
// 	while (size--) // пока стэк
// 	{
// 		stack1 = check->a->next;
// 		while (stack1->next != check->a)
// 		{
// 			if (duplicate == stack1->nbr)
// 				return (1); // есть дубликат
// 			stack1 = stack1->next;
// 		}
// 		if (size)
// 			duplicate = check->a->next->nbr;
// 		check->a = check->a->next;
// 	}
// 	return (0); // нету дубликата
// }

int	sorted(t_check *check)
{
	if (if_dups(check) || if_sort(check))
	{
		return (1); // отсортирован (плохо)
	}
	return (0); // не отсортирован (хорошо)
}
