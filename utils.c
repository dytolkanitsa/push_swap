#include "push_swap.h"

void	add_front(t_check *check, int nbr, char name)
{
	t_stack	**head;
	t_stack	*tmp;

	if (name == 'a')
		head = &check->a;
	else
		head = &check->b;
	if (*head)
	{
		tmp = (struct s_stack *)malloc(sizeof(t_stack));
		//if (!(*tmp))
			// функция для ошибок i guess
		tmp->next = *head;
		tmp->previous = (*head)->previous;
		(*head)->previous = tmp;
		tmp->previous->next = (*head)->next;
		tmp->nbr = nbr;
		*head = (*head)->previous;
		
	}
	else
	{
		*head = (struct s_stack *)malloc(sizeof(t_stack));
		//if (!(*head))
			// функция для ошибок i guess
		(*head)->next = *head;
		(*head)->previous = *head;
		(*head)->nbr = nbr;
	}
}

void	delit_front(t_check *check, char name)
{
	t_stack	**head;
	t_stack	*tmp;

	if (name == 'a')
		head = &check->a;
	else
		head = &check->b;
	if (*head)
	{
		if ((*head)->next == *head)
		{
			free(*head);
			*head = NULL;
		}
		else
		{
			tmp = *head;
			*head = (*head)->next;
			tmp->previous->next = *head;
			(*head)->previous = tmp->previous;
			free(tmp);
		}
	}
}

static int	if_if(char *str)
{
	int	i;

	i = 0;
	return (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;
	int	num;

	sign = 1;
	nbr = 0;
	num = 19;
	while (if_if(str))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (!num--)
			return ((1 + sign) / (-2));
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}