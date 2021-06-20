#include "push_swap.h"

void	ft_sa(t_check *check)
{
	int	temp;

	if (check->a)
	{
		temp = check->a->nbr;
		check->a->nbr = check->a->next->nbr;
		check->a->next->nbr = temp;
	}
	write(1, "sa\n", 3);
}

void	ft_sb(t_check *check)
{
	int	temp;

	if (check->b)
	{
		temp = check->b->nbr;
		check->b->nbr = check->b->next->nbr;
		check->b->next->nbr = temp;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(t_check *check)
{
	ft_sa(check);
	ft_sb(check);
	write(1, "ss\n", 3);
}

void	ft_pa(t_check *check)
{
	int	tmp;

	if (check->b)
	{
		tmp = check->b->nbr;
		add_front(check, tmp, 'a');
		delit_front(check, 'b');
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_check *check)
{
	int	tmp;

	if (check->a)
	{
		tmp = check->a->nbr;
		add_front(check, tmp, 'b');
		delit_front(check, 'a');
	}
	write(1, "pb\n", 3);
}
