#include "philos.h"

long	get_starting_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}

//returns how long have been program starting since it's launch in milisec

long	get_current_time(long start_time)
{
	struct timeval	start;
	time_t			current_time;

	current_time = 0;
	gettimeofday(&start, NULL);
	current_time = start.tv_sec * 1000 + start.tv_usec / 1000;
	return(current_time - start_time); 
}
