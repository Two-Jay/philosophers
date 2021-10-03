/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:52:06 by jekim             #+#    #+#             */
/*   Updated: 2021/10/04 05:22:11 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assign_data(t_setting *set, int argc, char **argv)
{
	set->data = malloc(sizeof(t_data));
	if (!set->data)
		return (ERROR_OCCURED);
	set->data->number_of_philo = ft_atoi(argv[1]);
	set->data->time_to_die = ft_atoi(argv[2]);
	set->data->time_to_eat = ft_atoi(argv[3]);
	set->data->time_to_sleep = ft_atoi(argv[4]);
	set->data->isAnyoneDead = 0;
	pthread_mutex_init(&set->data->isAnyoneDead_mtx, NULL);
	set->data->number_of_time_must_eat = -1;
	set->data->number_of_done_to_eat = -1;
	if (argc == 6)
	{
		set->data->number_of_time_must_eat = ft_atoi(argv[5]);
		set->data->number_of_done_to_eat = 0;
	}
	return (0);
}

int	assign_fork(t_setting *set)
{
	int	ix;
	int	nbr_philo;

	nbr_philo = set->data->number_of_philo;
	ix = 0;
	set->fork = (t_fork *)malloc(sizeof(t_fork) * (nbr_philo));
	if (!set->fork)
		return (ERROR_OCCURED);
	while (ix < nbr_philo)
	{
		set->fork[ix].id = ix + 1;
		set->fork[ix].grabbedby = 0;
		pthread_mutex_init(&set->fork[ix].fork_m, NULL);
		ix++;
	}
	return (0);
}

int	assign_philo(t_setting *set)
{
	int		ix;
	int		nbr_philo;

	ix = 0;
	nbr_philo = set->data->number_of_philo;
	set->philo = (t_philo *)malloc(sizeof(t_philo) * (nbr_philo));
	if (!set->philo)
		return (ERROR_OCCURED);
	while (ix < nbr_philo)
	{
		memset(&set->philo[ix], 0, sizeof(t_philo));
		set->philo[ix].data = set->data;
		set->philo[ix].fork = set->fork;
		set->philo[ix].tid = (pthread_t *)malloc(sizeof(pthread_t));
		if (!set->philo[ix].tid)
			return (ERROR_OCCURED);
		pthread_mutex_init(&set->philo[ix].philo_m, NULL);
		set->philo[ix].id = ix + 1;
		ix++;
	}
	return (0);
}

int	assign_monitor(t_setting *set)
{
	int	ix;
	int	limit;

	ix = 0;
	limit = set->data->number_of_philo;
	set->monitor = (t_monitor *)malloc(sizeof(t_monitor) * (limit));
	if (!set->monitor)
		return (ERROR_OCCURED);
	while (ix < limit)
	{
		set->monitor[ix].tid = (pthread_t *)malloc(sizeof(pthread_t));
		if (!set->monitor[ix].tid)
			return (ERROR_OCCURED);
		set->monitor[ix].target_philo = &(set->philo[ix]);
		set->monitor[ix].id = ix + 1;
		ix++;
	}
	return (0);
}
