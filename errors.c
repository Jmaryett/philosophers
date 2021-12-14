/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:16:42 by jmaryett          #+#    #+#             */
/*   Updated: 2021/12/14 16:17:42 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

//here destroy created mutex and pointers

void	free_all(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nb_of_philos)
	{
		if (all->forks)
			pthread_mutex_destroy(&(all->forks[i]));
		i++;
	}
	if (all->forks)
		free(all->forks);
	if (all->philos)
		free(all->philos);
	pthread_mutex_destroy(&all->right_to_write);
}

int	errors(char *s, t_all *all)
{
	free_all(all);
	printf("%s\n", s);
	return (0);
}
