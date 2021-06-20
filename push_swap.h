#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	int				size;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_struct
{
	int				nbr1;
	int				nbr2;
	char			commands;
	struct s_struct	*next;
}	t_struct;

typedef struct s_check
{
	t_stack	*a;
	t_stack	*b;
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

void	sort_five_or_less(t_check *check, int argc);
int		sorted(t_check *check);

t_stack	*add_in_list(int argc, char **str);
t_stack	*ft_lstnew(int nbr, t_stack *previous);
void	push_swap(t_check *check, int argc);
void	init_check(t_check *check);
void	add_front(t_check *check, int value, char name);
void	delit_front(t_check *check, char name);
void	ft_putstr(char *str);
int		find_max(t_check *check, char name);
int		max_value(t_stack *stack);
int		find_min(t_check *check, char name);
int		min_value(t_stack *stack);
int		ft_atoi(char *str);
int		ft_lstsize(t_check *check);
int		if_sort(t_check *check);
int		if_dups(t_check *check);
int		if_numbers(t_check *check);
int		ft_isdigit(char c);
int		check_argument(int argc, char **str);
#endif