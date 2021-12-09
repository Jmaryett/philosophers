#include "philos.h"

void	take_forks(t_philos *philo)
{
	pthread_mutex_lock(philo->first_fork);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\t%d philosopher took first fork\n", get_current_time(philo->all->start_time), philo->number);
	pthread_mutex_unlock(philo->right_to_write);
	pthread_mutex_lock(philo->second_fork);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\t%d philosopher took second fork\n", get_current_time(philo->all->start_time), philo->number);
	pthread_mutex_unlock(philo->right_to_write);
}

void	eating(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\t%d philosopher is eating\n", get_current_time(philo->all->start_time), philo->number);
	pthread_mutex_unlock(philo->right_to_write);
	ft_usleep(philo->all->time_to_eat, philo->all->start_time);
	philo->time_to_die = get_current_time(philo->all->start_time)
		 + philo->all->time_to_die;
	philo->eaten_meals++;
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

void	sleeping(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\t%d philosopher is sleeping\n", get_current_time(philo->all->start_time), philo->number);
	pthread_mutex_unlock(philo->right_to_write);
	ft_usleep(philo->all->time_to_sleep, philo->all->start_time);
}

void	thinking(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\t%d philosopher is thinking\n", get_current_time(philo->all->start_time), philo->number);
	pthread_mutex_unlock(philo->right_to_write);
}

void	*eat_sleep_think(void *arg)
{
	t_philos	*philo = (t_philos*)arg;

	//not sure if it needed here
	philo->time_to_die = get_current_time(philo->all->start_time)
						+ philo->all->time_to_die;
	if (philo->number % 2 == 0)
		ft_usleep(philo->all->time_to_eat / 10, philo->all->start_time);
	while (1)
	{
		take_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}