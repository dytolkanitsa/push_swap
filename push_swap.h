#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	int				size;
	int				count;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_check
{
	int		*arrcount;
	char	**commands;
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;
	int		len_b;
	int		num1;
	int		num2;
	int		max_num_a;
	int		max_num;
	int		min_num_a;
	int		min_num_b;
	int		po;
	int		count;
	int		nbr_a;
}	t_check;

void		ft_sa(t_check *check);
void		ft_sb(t_check *check);
void		ft_ss(t_check *check);
void		ft_pa(t_check *check);
void		ft_pb(t_check *check);
void		ft_ra(t_check *check);
void		ft_rb(t_check *check);
void		ft_rr(t_check *check);
void		ft_rra(t_check *check);
void		ft_rrb(t_check *check);
void		ft_rrr(t_check *check);

void		sort_five_or_less(t_check *check, int len);
void		sort_anything_else(t_check *check);
int			sorted(t_check *check);

t_stack		*add_in_list(char **str);
t_stack		*ft_lstnew(int nbr, t_stack *previous);
void		push_swap(t_check *check, int argc);
void		init_check(t_check *check);
void		add_front(t_check *check, int value, char name);
void		delit_front(t_check *check, char name);
void		ft_putstr(char *str);
int			find_max(t_check *check, char name);
int			max_value(t_stack *stack);
int			find_min(t_check *check, char name);
int			min_value(t_stack *stack);
long int	ft_atoi(char *str);
int			ft_lstsize(t_check *check);
int			if_sort(t_check *check);
int			if_dups(t_check *check);
int			if_numbers(t_check *check);
int			ft_isdigit(char c);
int			check_argument(int argc, char **str);
int			ft_strlen(char *str);
void		*ft_free_everything(char **str);
int			ft_strsize(char **str);

void		get_commands(t_check *check);
void		sort_five(t_check *check);
char		**ft_split(char const *s, char c);
void		ft_init_and_move(t_check *check, t_stack **stack_a, \
										t_stack **stack_b, int *temp);
int			first_min(t_check *check);
void		for_find_am_1(t_check *check, t_stack **stack_a, t_stack **stack_b);
void		for_find_am_2(t_check *check, t_stack **stack_a, t_stack **stack_b);
void		for_find_am_3(t_check *check);
void		for_find_am_4(t_check *check, t_stack **stack_b);
void		for_find_am_5(t_check *check, t_stack **stack_a, t_stack **stack_b);

void		init_get_com(t_check *check);
void		for_get_com_1(t_check *check, t_stack **stack_a, t_stack **stack_b);
#endif	