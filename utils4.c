#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	check_argument(int len, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] != '-' && !ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
