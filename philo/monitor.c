/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:31:47 by jekim             #+#    #+#             */
/*   Updated: 2021/10/03 07:23:15 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *mon)
{
	t_monitor		*monitor;
	t_data			*data;
	unsigned long	limit;

	monitor = (t_monitor *)mon;
	data = monitor->target_philo->data;
	limit = monitor->target_philo->data->time_to_die;
	while (1)
	{
		pthread_mutex_lock(&monitor->target_philo->philo_m);
		if (monitor->target_philo->is_over)
			return (0);
		if (get_time() - monitor->target_philo->last_eat_time > limit)
		{
			monitor->target_philo->state = DIE;
			print_messsage_stdout(monitor->target_philo);
			return (0);
		}
		pthread_mutex_unlock(&monitor->target_philo->philo_m);
		usleep(1000);
	}
	return (0);
}

int	check_isend(t_setting *set)
{
	while (1)
	{
		if (set->data->isAnyoneDead
			|| (set->data->number_of_done_to_eat == set->data->number_of_philo))
			break ;
		usleep(50);
	}
	return (0);
}