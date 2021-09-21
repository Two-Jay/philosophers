/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:52:06 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 04:51:37 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assign_data(t_setting *set, int argc, char **argv)
{
	set->data->number_of_philo = ft_atoi(argv[1]);
	set->data->time_to_die = ft_atoi(argv[2]);
	set->data->time_to_eat = ft_atoi(argv[3]);
	set->data->time_to_sleep = ft_atoi(argv[4]);
	set->data->isAnyoneDead = 0;
	pthread_mutex_init(&set->data->isAnyoneDead_mtx, NULL);
	if (argc == 6)
		set->data->number_of_time_must_eat = ft_atoi(argv[5]);
	else
		set->data->number_of_time_must_eat = 0;
	return (0);
}

int validate_assigned_data(t_setting *set)
{
	if (set->data->number_of_philo < 2
		|| set->data->number_of_philo > 200
		|| set->data->number_of_time_must_eat < 0)
		return (ERROR_OCCURED);	
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
	t_state	stat;

	ix = 0;
	nbr_philo = set->data->number_of_philo;
	stat = 0;
	set->philo = (t_philo *)malloc(sizeof(t_philo) * (nbr_philo));
	if (!set->philo)
		return (ERROR_OCCURED);
	while (ix < nbr_philo)
	{
		set->philo[ix].data = set->data;
		set->philo[ix].fork = set->fork;
		set->philo[ix].tid = (pthread_t *)malloc(sizeof(pthread_t));
		if (!set->philo[ix].tid)
			return (ERROR_OCCURED);
		set->philo[ix].id = ix + 1;
		set->philo[ix].l_fork = 0;
		set->philo[ix].r_fork = 0;
		set->philo[ix].last_eat_time = 0;
		set->philo[ix].state = stat;
		ix++;
	}
	return (0);
}