/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:07:17 by jmaryett          #+#    #+#             */
/*   Updated: 2021/12/14 16:08:20 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	init_forks(t_all *all)
{
	int	i;

	i = 0;
	all->forks = malloc(sizeof(pthread_mutex_t) * (all->nb_of_philos));
	if (!all->forks)
		return (0);
	while (i < all->nb_of_philos)
	{
		pthread_mutex_init(&(all->forks[i]), NULL);
		i++;
	}
	return (1);
}

int	init_philos(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	all->philos = malloc(sizeof(t_philos) * all->nb_of_philos);
	if (!(all->philos))
		return (0);
	while (i < all->nb_of_philos)
	{
		i++;
		all->philos[j].number = i;
		j++;
	}
	return (1);
}

int	init_time_and_nb_of_meals(int ac, char **input, t_all *all)
{
	all->time_to_die = ft_atoi(input[0]);
	all->time_to_eat = ft_atoi(input[1]);
	all->time_to_sleep = ft_atoi(input[2]);
	if (ac == 5)
	{
		all->nb_should_eat = ft_atoi(input[3]);
		if (all->time_to_die <= 0 || all->time_to_eat <= 0
			|| all->nb_should_eat <= 0)
			return (0);
	}
	else
	{
		all->nb_should_eat = INT_MAX;
		if (all->time_to_die <= 0 || all->time_to_eat <= 0)
			return (0);
	}
	return (1);
}
