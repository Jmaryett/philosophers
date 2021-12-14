/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:05:39 by jmaryett          #+#    #+#             */
/*   Updated: 2021/12/14 16:06:46 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	check_str_num(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[j])
	{
		while (s[j][i])
		{
			if (!ft_isdigit(s[j][i]))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_valid_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (!check_str_num(av))
		return (0);
	return (1);
}
