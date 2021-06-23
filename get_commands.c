#include "push_swap.h"

int	find_nbr_a(t_check *check, t_stack *stack_a, t_stack *stack_b)
{
	check->po = 0;
	init_get_com(check);
	for_get_com_1(check, &stack_a, &stack_b);
	if (check->nbr_a == 0)
	{
		if (stack_b->nbr < stack_a->nbr && stack_b->nbr > check->min_num_a)
		{
			while (stack_b->nbr < stack_a->nbr)
			{
				stack_a = stack_a->next;
				check->nbr_a++;
			}
			while (stack_b->nbr > stack_a->nbr)
			{
				stack_a = stack_a->next;
				check->po++;
			}
			check->nbr_a = check->nbr_a + check->po;
		}
	}
	if (check->nbr_a > check->size_a / 2)
		check->nbr_a = check->size_a - check->nbr_a;
	return (check->nbr_a);
}

void	get_commands(t_check *check)
{
	int		num1;
	int		num2;
	t_stack	*stack_a;
	t_stack	*stack_b;

	num2 = 0;
	stack_a = check->a;
	stack_b = check->b;
	check->len_b = check->size_b;
	check->arrcount = malloc(sizeof(int) * check->size_b);
	while (check->len_b != 0)
	{
		num1 = find_nbr_a(check, stack_a, stack_b);
		if (num2 <= check->size_b / 2)
			check->count = num1 + num2;
		else
			check->count = check->size_b - num2 + num1;
		check->arrcount[num2] = check->count;
		stack_b = stack_b->next;
		num2++;
		check->len_b--;
	}
}
