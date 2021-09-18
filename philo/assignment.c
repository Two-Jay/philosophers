/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:52:06 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 02:29:29 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assign_data(t_data *data, int argc, char **argv)
{
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->isAnyoneDead = 0;
	if (argc == 6)
		data->number_of_time_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_time_must_eat = 0;
	if (data->number_of_philo < 2
		|| data->number_of_philo > 200
		|| data->number_of_time_must_eat < 0)
		return (ERROR_OCCURED);
	return (0);
}

int	assign_philo(t_data *data)
{
	int	ix;

	ix = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->philo)
		return (ERROR_OCCURED);
	while (ix < data->number_of_philo)
	{
		data->philo[ix].tid = (pthread_t *)malloc(sizeof(pthread_t));
		if (!data->philo[ix].tid)
			return (ERROR_OCCURED);
		data->philo[ix].id = ix + 1;
		data->philo[ix].l_fork = ix;
		data->philo[ix].r_fork = ix;
		data->philo[ix].last_eat_time = 0;
		data->philo[ix].state = 0;
		ix++;
	}
	return (0);
}