#include "philos.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	check_str_num(char **s)
{
	int	i = 0;
	int	j = 1;
	while (s[j])
	{
		while (s[j][i])
		{
			if (!ft_isdigit(s[j][i]))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_valid_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (!check_str_num(av))
		return (0);
	return (1);
}