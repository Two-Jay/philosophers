/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:10 by jekim             #+#    #+#             */
/*   Updated: 2021/10/03 06:44:26 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_data(t_setting *set)
{
	int	ix;
	int	limit;

	ix = 0;
	limit = set->data->number_of_philo;
	while (ix < limit)
		pthread_mutex_destroy(&set->fork[ix++].fork_m);
	free(set->fork);
	ix = 0;
	while (ix < limit)
	{
		pthread_mutex_destroy(&set->philo[ix].philo_m);
		pthread_join(*set->philo[ix].tid, NULL);
		free(set->philo[ix].tid);
		ix++;
	}
	free(set->philo);
	ix = 0;
	while (ix < limit)
		free(set->monitor[ix++].tid);
	free(set->monitor);
	pthread_mutex_destroy(&set->data->isAnyoneDead_mtx);
	free(set->data);
	return (0);
}

int	run_monitor(t_setting *set)
{
	int	ix;

	ix = 0;
	while (ix < set->data->number_of_philo)
	{
		pthread_create(set->monitor[ix].tid,
			NULL,
			monitor_routine,
			(void *)&set->monitor[ix]);
		pthread_detach(*set->monitor[ix].tid);
		ix++;
	}
	return (0);
}

int	run_philo(t_setting *set)
{
	int				ix;

	ix = 0;
	set->data->start_time = get_time();
	while (ix < set->data->number_of_philo)
	{
		set->philo[ix].number_of_time_must_eat
			= set->data->number_of_time_must_eat;
		pthread_create(set->philo[ix].tid,
			NULL,
			philo_routine,
			(void *)&set->philo[ix]);
		pthread_detach(*set->philo[ix].tid);
		ix++;
	}
	return (0);
}

int	set_data(t_setting *set, int argc, char **argv)
{
	if (validate_argv(argc, argv)
		|| assign_data(set, argc, argv)
		|| assign_fork(set)
		|| assign_philo(set)
		|| assign_monitor(set)
		|| validate_assigned_data(set))
		return (ERROR_OCCURED);
	return (0);
}

int	main(int argc, char **argv)
{
	t_setting	set;

	if (set_data(&set, argc, argv)
		|| run_philo(&set)
		|| run_monitor(&set)
		|| check_isend(&set))
		return (ft_strerr("Error\n"));
	return (free_data(&set));
}
