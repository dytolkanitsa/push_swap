#include "push_swap.h"

void	ft_sa(t_check *check)
{
	int	temp;

	if (check->a)
	{
		temp = check->a->nbr;  // temp = a
		check->a->nbr = check->a->next->nbr; // a = b
		check->a->next->nbr = temp; // b = temp
	}
	// write(1, "sa\n", 2);
}

void	ft_sb(t_check *check)
{
	int	temp;

	if (check->b)
	{
		temp = check->b->nbr;  // temp = a
		check->b->nbr = check->b->next->nbr; // a = b
		check->b->next->nbr = temp; // b = temp
	}
	// write(1, "sb\n", 2);
}

void	ft_ss(t_check *check)
{
	ft_sa(check);
	ft_sb(check);
	write(1, "ss\n", 2);
}

void	ft_pa(t_check *check)
{
	int	tmp;
	if (check->b)
	{
		tmp = check->b->nbr;
		add_front(check, tmp, 'a'); // добавляем новый элемент в список 
		delit_front(check, 'b'); // удаляем первый элемент из списка
		// я когда вот так подаю число это я подаю само число или значение, тип мне нужна временная переменная или нет
	}
	// write(1, "pa\n", 2);
}

void	ft_pb(t_check *check)
{
	if (check->a)
	{
		add_front(check, check->a->nbr, 'b'); // добавляем новый элемент в список 
		// я когда вот так подаю число это я подаю само число или значение, тип мне нужна временная переменная или нет
		delit_front(check, 'a'); // удаляем первый элемент из списка
	}
	// write(1, "pb\n", 2);
}
