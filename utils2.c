#include "push_swap.h"

t_stack	*ft_del(t_stack *stack)
{
	t_stack	*prev;
	t_stack	*next;

	prev = stack->previous;
	next = stack->next;
	prev->next = stack->next;
	next->previous = stack->previous;
	free(stack);
	return (prev);
}