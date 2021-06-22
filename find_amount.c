#include "push_swap.h"

int	get_min_num_arr(t_check *check)
{
	int	i;
	int	min_num;

	i = 0;
	min_num = check->arrcount[i];
	while (i < check->size_b)
	{
		if (min_num > check->arrcount[i])
			min_num = check->arrcount[i];
		i++;
	}
	return (min_num);
}

int	first_min(t_check *check)
{
	int	i;
	int	min_num;

	i = 0;
	min_num = get_min_num_arr(check);
	while (i < check->size_b)
	{
		if (check->arrcount[i] == min_num)
			return (i);
		i++;
	}
	return (i);
}

void	sort_anything_else(t_check *check)
{
	int	i;
	int	n;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	num1;
	int	num2;
	int	max_num_a;
	int	min_num_a;
	int	temp;
	int	po;

	i = 0;
	n = 0;
	num1 = 0;
	check->size_b = check->a->size - 5;
	while (check->size_a != 5)
	{
		ft_pb(check);
		check->size_a--;
	}
	temp = check->size_b;
	sort_five(check);
	stack_a = check->a;
	stack_b = check->b;
	check->a = stack_a;
	check->b = stack_b;
	while (n < temp)
	{
		num1 = 0;
		get_commands(check);
		i = 0;
		po = 0;

		i = 0;
		num2 = first_min(check);
		while (i != num2)
		{
			stack_b = stack_b->next;
			i++;
		}
		i = 0;
		min_num_a = find_min(check, 'a');
		max_num_a = find_max(check, 'a');
		if (stack_b->nbr < min_num_a || stack_b->nbr > max_num_a)
		{
			while (stack_a->nbr != min_num_a)
			{
				stack_a = stack_a->next;
				num1++;
			}
		}
		if (num1 == 0)
		{
			if (!(stack_a->nbr == min_num_a && stack_b->nbr > max_num_a))
			{	
				i = 0;
				while (i < check->size_a && stack_b->nbr > stack_a->nbr)
				{
					stack_a = stack_a->next;
					num1++;
					if (i == check->size_a && stack_b->nbr > stack_a->nbr)
						num1++;
					i++;
				}
			}
		}
		if (num1 == 0)
		{
			if (stack_b->nbr < stack_a->nbr && stack_b->nbr > min_num_a)
			{
				while (stack_b->nbr < stack_a->nbr)
				{
					stack_a = stack_a->next;
					num1++;	
				}
				while (stack_b->nbr > stack_a->nbr)
				{
					stack_a = stack_a->next;
					po++;
				}
				num1 = num1 + po;
			}
		}
		if (num2 < check->size_b / 2)
		{
			while (num2--)
				ft_rb(check);
		}
		else
		{
			num2 = check->size_b - num2;
			while (num2--)
				ft_rrb(check);
		}
		if (num1 < check->size_a / 2)
		{
			while (num1--)
				ft_ra(check);
		}
		else
		{
			num1 = check->size_a - num1;
			while (num1--)
				ft_rra(check);
		}
		ft_pa(check);
		stack_b = stack_b->next;
		check->size_a++;
		check->size_b--;
		stack_a = stack_a->previous;
		n++;
	}
	while (!if_sort(check))
		ft_ra(check);
}
