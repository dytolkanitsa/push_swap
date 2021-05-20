#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_check
{
	t_stack	*a;
	t_stack	*b;
	// char	*arg; //цифры из аргумента
	// char	*oper; //operation
	// проверка на разделители??? split?
	// int		flag; // если мы вызываем фунецию ft_sa и ей подобные, то меняем флаг на 1 и тогда райтим
}	t_check;

void	ft_sa(t_check *check);
void	ft_sb(t_check *check);
void	ft_ss(t_check *check);
void	ft_pa(t_check *check);
void	ft_pb(t_check *check);
void	ft_ra(t_check *check);
void	ft_rb(t_check *check);
void	ft_rr(t_check *check);
void	ft_rra(t_check *check);
void	ft_rrb(t_check *check);
void	ft_rrr(t_check *check);

void	add_front(t_check *check, int value, char name);
void	delit_front(t_check *check, char name);
int		ft_atoi(char *str);
#endif