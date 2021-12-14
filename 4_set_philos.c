/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_set_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:08:36 by jmaryett          #+#    #+#             */
/*   Updated: 2021/12/14 16:09:06 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	assign_forks(int i, t_all *all)
{
	if (i == all->nb_of_philos - 1)
	{
		all->philos[i].first_fork = &all->forks[0];
		all->philos[i].second_fork = &all->forks[i];
	}
	else
	{
		all->philos[i].first_fork = &all->forks[i];
		all->philos[i].second_fork = &all->forks[i + 1];
	}
}

void	set_philos(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nb_of_philos)
	{
		all->philos[i].time_to_die = all->time_to_die;
		all->philos[i].right_to_write = &all->right_to_write;
		assign_forks(i, all);
		all->philos[i].all = all;
		all->philos[i].eaten_meals = 0;
		i++;
	}
}
