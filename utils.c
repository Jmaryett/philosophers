/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:14:57 by jmaryett          #+#    #+#             */
/*   Updated: 2021/12/14 16:14:57 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static	unsigned long	attoi(char *str)
{
	unsigned long	n;

	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

long	ft_atoi(const char *str)
{
	int				count;
	unsigned long	n;

	n = 0;
	count = 1;
	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	n = attoi((char *)str);
	if (n > 9223372036854775807 && count == 1)
		return (-1);
	if (n > 9223372036854775807 && count == -1)
		return (0);
	return (count * n);
}

void	ft_usleep(time_t milisec, long start_time)
{
	time_t	stop;
	time_t	start;

	stop = get_current_time(start_time) + milisec;
	start = get_current_time(start_time);
	while (start < stop)
	{
		usleep(25);
		start = get_current_time(start_time);
	}
}
