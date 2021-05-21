#include "push_swap.h"

void	ft_ra(t_check *check)
{
	int		temp;
	int		size;
	int		top;
	t_stack	*p;

	p = check->a;
	size = check->a->size;
	temp = 1;
	top = check->a->nbr;
	while (temp < size)
	{
		p->nbr = p->next->nbr;
		p = p->next;
		p->nbr = p->next->nbr;
		temp++;
	}
	p->nbr = top;
	// write(1, "r\n", 2);
}

void	ft_rb(t_check *check)
{
	int		temp;
	int		size;
	int		top;
	t_stack	*p;

	p = check->b;
	size = check->b->size;
	temp = 1;
	top = check->b->nbr;
	while (temp < size)
	{
		p->nbr = p->next->nbr;
		p = p->next;
		p->nbr = p->next->nbr;
		temp++;
	}
	p->nbr = top;
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
	t_stack	*p;
	t_stack	*last;
	t_stack	*new;
	int		size;
	int		temp;

	p = check->a->previous;
	size = check->a->size;
	new = ft_lstnew(p->nbr);
	new->next = check->a;
	new->previous = p->previous;
	check->a = new;
	p->next = NULL;
	p->previous = NULL;
	// write(1, "rra\n", 3);
}

void	ft_rrb(t_check *check)
{
	t_stack	*p;
	t_stack	*last;
	t_stack	*new;
	int		size;
	int		temp;

	p = check->b->previous;
	size = check->b->size;
	new = ft_lstnew(p->nbr);
	new->next = check->b;
	new->previous = p->previous;
	check->b = new;
	p->next = NULL;
	p->previous = NULL;
	// write(1, "rrb\n", 3);
}
