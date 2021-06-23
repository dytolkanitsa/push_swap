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
	int		i;
	int		n;
	int		temp;
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_init_and_move(check, &stack_a, &stack_b, &temp);
	i = 0;
	n = 0;
	temp = check->size_b;
	while (n < temp)
	{
		for_find_am_4(check, &stack_b);
		for_find_am_5(check, &stack_a, &stack_b);
		n++;
	}
	while (!if_sort(check))
		ft_ra(check);
}
