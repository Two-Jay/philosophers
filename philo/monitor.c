/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:31:47 by jekim             #+#    #+#             */
/*   Updated: 2021/10/13 21:24:51 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_die_message_stdout(t_philo *philo)
{
	char	*msg;

	msg = "dead\n";
	pthread_mutex_lock(&(philo->data->print_m));
	printf("%lu %d %s",
		get_time() - philo->data->start_time,
		philo->id,
		msg);
	philo->data->isAnyoneDead++;
	return (0);
}

int	print_end_message_stdout(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->print_m));
	printf("%lu All of philo done to eat\n",
		get_time() - philo->data->start_time);
	return (0);
}

void	*monitor_routine(void *set)
{
	unsigned int	ix;
	unsigned long	limit;
	t_setting		*setting;

	setting = (t_setting *)set;
	limit = setting->data->time_to_die;
	ix = 0;
	while (++ix >= 0)
	{
		if (ix == (unsigned int)setting->data->number_of_philo)
			ix = 0;
		if (setting->data->number_of_done_to_eat
			== setting->data->number_of_philo)
		{
			print_end_message_stdout(&setting->philo[ix]);
			return (0);
		}
		if (get_time() - setting->philo[ix].last_eat_time > limit)
		{
			print_die_message_stdout(&setting->philo[ix]);
			return (0);
		}
		usleep(200);
	}	
	return (0);
}
