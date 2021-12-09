#ifndef PHILOS_H

# define PHILOS_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <time.h>
#include <limits.h>

typedef struct s_all	t_all;

typedef struct	s_philos
{
	int				eaten_meals;
	t_all			*all;
	int				number;
	time_t			time_to_die;
	pthread_mutex_t	*right_to_write;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
}				t_philos;

//to send this params to a thread we'll unite them to a structure

typedef struct s_all
{
	int			nb_should_eat;
	int			nb_of_philos;
	t_philos	*philos;
	long		start_time;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	right_to_write;
}				t_all;

//utils and validation

int	errors(char *s, t_all *all);
int	ft_atoi(const char *str);
int	check_valid_args(int ac, char **av);
void	free_all(t_all *all);

//init structure and mutexes
int	init_forks(t_all *all);
int	init_philos(t_all *all);
int	init_time_and_nb_of_meals(int ac, char **input, t_all *all);
void set_philos(t_all *all);

//creating threads and working with them
void	creating_threads(t_all *all);
void	*eat_sleep_think(void *arg);

//funcs to get time in miliseconds and own usleep
long	get_starting_time(void);
long	get_current_time(long start_time);
void	ft_usleep(time_t milisec, long start_time);

#endif