#include "push_swap.h"

void	push_swap(t_check *check, int len)
{
	if (!sorted(check))
	{
		if (len <= 5)
			sort_five_or_less(check, len);
		else
			sort_anything_else(check);
	}
	else
		ft_putstr("Error\n");
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (!(src[i] == '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	for_main(char **mas, char **argv, t_check *check, int argc)
{
	int		len_str;
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (i < argc)
	{
		len_str = ft_strlen(argv[i]);
		mas[n] = (char *)malloc(sizeof(char) * (len_str + 1));
		if (mas == 0)
			ft_free_everything(mas);
		ft_strcpy(mas[n], argv[i]);
		i++;
		n++;
	}
	mas[argc - 1] = 0;
	check->a = add_in_list(mas);
}

static void	for_main2(t_check **check, char **mas, int *len)
{
	*len = ft_strsize(mas);
	(*check)->b = NULL;
	(*check)->size_a = (*check)->a->size;
	ft_free_everything(mas);
}

int	main(int argc, char **argv)
{
	char	**mas;
	int		len;
	t_check	*check;

	len = 0;
	if (argc < 2)
		return (0);
	check = (struct s_check *)malloc(sizeof(t_check));
	if (!check)
		return (0);
	if (argc == 2)
	{
		mas = ft_split(argv[1], ' ');
		check->a = add_in_list(mas);
	}
	if (argc > 2)
	{
		mas = (char **)malloc(sizeof(char *) * argc);
		if (!mas)
			return (0);
		for_main(mas, argv, check, argc);
	}
	for_main2(&check, mas, &len);
	push_swap(check, len);
}
