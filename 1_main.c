#include "philos.h"

void	starting_to_work(t_all *all)
{
	pthread_mutex_init(&all->right_to_write, NULL);
	set_philos(all);
	//all->start_time = get_starting_time();
	creating_threads(all);
	return ;
}

static int	init_all(int ac, char **av, t_all *all)
{
	if (ft_atoi(av[1]) <= 0)
	{
		errors("Error: Number of philosophers must be more than 0!\n", all);
		return (0);
	}
	else
		all->nb_of_philos = ft_atoi(av[1]);
	if (!init_time_and_nb_of_meals(ac, &av[2], all))
	{
		errors("time_to_die, time_to_eat and number_of_eaten_meals MUST be more than 0!\n", all);
		return (0);
	}
	if (!init_philos(all))
	{
		errors("Error: troubles with malloc!\n", all);
		return (0);
	}
	if (!init_forks(all))
	{
		errors("Error: troubles with malloc!\n", all);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_all	all;

	all.forks = NULL;
	all.philos = NULL;
	if (!check_valid_args(ac, av))
	{
		errors("Error: Wrong arguments!\n", &all);
		return (-1);
	}
	if (!init_all(ac - 1, av, &all))
		return (-1);
	starting_to_work(&all);
	free_all(&all);
	return (0);
}