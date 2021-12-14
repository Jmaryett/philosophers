/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:47:14 by jmaryett          #+#    #+#             */
/*   Updated: 2021/12/14 16:04:34 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	starting_to_work(t_all *all)
{
	pthread_mutex_init(&all->right_to_write, NULL);
	set_philos(all);
	creating_threads(all);
	return ;
}

static int	init_all(int ac, char **av, t_all *all)
{
	if (ft_atoi(av[1]) <= 0)
	{
		write(1, "Error: Number of philosophers must be more than 0!\n", 51);
		return (0);
	}
	else
		all->nb_of_philos = ft_atoi(av[1]);
	if (!init_time_and_nb_of_meals(ac, &av[2], all))
	{
		write(1, "time_to_die, time_to_eat and", 28);
		write(1, " number_of_eaten_meals MUST be more than 0!\n", 44);
		return (0);
	}
	if (!init_philos(all))
	{
		write(1, "Error: troubles with malloc!\n", 29);
		return (0);
	}
	if (!init_forks(all))
	{
		write(1, "Error: troubles with malloc!\n", 29);
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
		write(1, "Error: Wrong arguments!\n", 24);
		return (0);
	}
	if (!init_all(ac - 1, av, &all))
		return (0);
	starting_to_work(&all);
	free_all(&all);
	return (0);
}
