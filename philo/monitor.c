/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:31:47 by jekim             #+#    #+#             */
/*   Updated: 2021/10/13 20:48:12 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_die_message_stdout(t_philo *philo)
{
	char	*msg;

	msg = "dead.\n";
	pthread_mutex_lock(&(philo->data->print_m));
	printf("%lu ms %dth philo %s",
		get_time() - philo->data->start_time,
		philo->id,
		msg);
	philo->data->isAnyoneDead++;
	return (0);
}

int	print_end_message_stdout(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->print_m));
	printf("%lu ms All of philo done to eat\n",
		get_time() - philo->data->start_time);
	return (0);
}

void	*monitor_routine(void *set)
{
	int				ix;
	unsigned long	limit;
	t_setting		*setting;

	setting = (t_setting *)set;
	limit = setting->data->time_to_die;
	ix = 0;
	while (1)
	{
		if (get_time() - setting->philo[ix].last_eat_time > limit)
		{
			print_die_message_stdout(&setting->philo[ix]);
			return (0);
		}
		if (setting->philo[ix].is_over == 1)
			setting->data->number_of_done_to_eat += 1;
		if (setting->data->number_of_done_to_eat
			== setting->data->number_of_philo)
		{
			print_end_message_stdout(&setting->philo[ix]);
			return (0);
		}
		usleep(100);
		ix++;
		if (ix == setting->data->number_of_philo)
			ix = 0;
	}	
	return (0);
}


