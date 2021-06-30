/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:07:29 by lgarg             #+#    #+#             */
/*   Updated: 2021/06/26 12:43:29 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_front1(t_stack **head, int nbr)
{
	t_stack	*tmp;

	tmp = (struct s_stack *)malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->next = *head;
	tmp->previous = (*head)->previous;
	(*head)->previous = tmp;
	tmp->previous->next = tmp;
	tmp->nbr = nbr;
	*head = (*head)->previous;
}

void	add_front(t_check *check, int nbr, char name)
{
	t_stack	**head;

	if (name == 'a')
		head = &check->a;
	else
		head = &check->b;
	if (*head)
	{
		for_front1(head, nbr);
	}
	else
	{
		*head = (struct s_stack *)malloc(sizeof(t_stack));
		if (!(*head))
			return ;
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
			tmp->previous = (*head)->previous;
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

long int	ft_atoi(char *str)
{
	long int	sign;
	long int	nbr;

	sign = 1;
	nbr = 0;
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
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
