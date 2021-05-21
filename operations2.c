#include "push_swap.h"

void	ft_ra(t_check *check)
{
	if (check->a)
	{
		printf("<%d>\n", check->a->previous->nbr);
		// check->a->previous = 
		check->a = check->a->next;
	}
	// write(1, "ra\n", 2);
}

void	ft_rb(t_check *check)
{
	if (check->b)
	{
		check->b = check->b->next;
	}
	// write(1, "rb\n", 2);
}

void	ft_rr(t_check *check)
{
	ft_ra(check);
	ft_rb(check);
// 	write(1, "rr\n", 2);
}

void	ft_rra(t_check *check)
{
	if (check->a)
	{
		check->a = check->a->previous;
	}
	// write(1, "rra\n", 3);
}

void	ft_rrb(t_check *check)
{
	if (check->b)
	{
		check->b = check->b->previous;
	}
	// write(1, "rrb\n", 3);
}
