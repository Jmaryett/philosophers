/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_creating_threads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:09:15 by jmaryett          #+#    #+#             */
/*   Updated: 2021/12/14 16:10:55 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	dead_or_alive(int i, t_all *all)
{
	if (get_current_time(all->start_time) > all->philos[i].time_to_die)
	{
		pthread_mutex_lock(&all->right_to_write);
		printf("%ld\t%d philosopher is dead\n",
			get_current_time(all->start_time), i + 1);
		return (0);
	}
	return (1);
}

void	observer(t_all *all)
{
	int	i;
	int	all_philos;

	while (1)
	{
		i = 0;
		all_philos = 0;
		while (i < all->nb_of_philos)
		{
			if (all->philos[i].eaten_meals >= all->nb_should_eat)
				all_philos++;
			if (!dead_or_alive(i, all))
				return ;
			i++;
		}
		if (all_philos == all->nb_of_philos)
		{
			pthread_mutex_lock(&all->right_to_write);
			return ;
		}
		usleep (100);
	}
}

void	creating_threads(t_all *all)
{
	int			i;
	pthread_t	philo_thread;

	i = 0;
	all->start_time = get_starting_time();
	while (i < all->nb_of_philos)
	{
		if (pthread_create(&philo_thread, NULL, eat_sleep_think,
				(void *)(all->philos + i)))
		{
			pthread_mutex_lock(&all->right_to_write);
			printf("Couldn't create a thread for %d philosopher\n", i);
			return ;
		}
		pthread_detach(philo_thread);
		i++;
	}
	observer(all);
}
