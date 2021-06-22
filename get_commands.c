#include "push_swap.h"

int	find_nbr_a(t_check *check, t_stack *stack_a, t_stack *stack_b) // индекс куда поставить в а
{
	t_check	*stack;
	int		nbr_a;
	int		i;
	int		po;
	int		min_num_a;
	int		min_num_b;
	int		max_num;

	i = 0;
	nbr_a = 0;
	po = 0;
	stack = check;
	min_num_a = find_min(check, 'a');
	min_num_b = find_min(check, 'b');
	max_num = find_max(check, 'a');
	if (nbr_a == 0 && (stack_b->nbr < min_num_a || stack_b->nbr > max_num))
	{
		while (stack_a->nbr != min_num_a)
		{
			stack_a = stack_a->next;
			nbr_a++;
		}
	}
	i = 0;
	if (nbr_a == 0)
	{
		while (i < stack->size_a && stack_b->nbr > stack_a->nbr)
		{
			stack_a = stack_a->next;
			nbr_a++;
			if (i == stack->size_a && stack_b->nbr > stack_a->nbr)
				nbr_a++;
			i++;
		}
	}

	if (nbr_a == 0)
	{
		if (stack_b->nbr < stack_a->nbr && stack_b->nbr > min_num_a)
		{
			while (stack_b->nbr < stack_a->nbr)
			{
				stack_a = stack_a->next;
				nbr_a++;	
			}
			while (stack_b->nbr > stack_a->nbr)
			{
				stack_a = stack_a->next;
				po++;
			}
			nbr_a = nbr_a + po;
		}
	}
	if (nbr_a > check->size_a / 2)
		nbr_a = check->size_a - nbr_a;
	return (nbr_a);
}

void	get_commands(t_check *check)
{
	int	num1;
	int	num2;
	int	len_size_b;
	int	count;
	t_stack	*stack_a;
	t_stack	*stack_b;

	num2 = 0;
	stack_a = check->a;
	stack_b = check->b;
	len_size_b = check->size_b;
	check->arrcount = malloc(sizeof(int) * check->size_b);
	while (len_size_b != 0)
	{
		num1 = find_nbr_a(check, stack_a, stack_b);
		if (num2 <= check->size_b / 2)
			count = num1 + num2;
		else
			count = check->size_b - num2 + num1;
		check->arrcount[num2] = count;
		stack_b = stack_b->next;
		num2++;
		len_size_b--;
	}
}