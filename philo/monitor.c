/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:31:47 by jekim             #+#    #+#             */
/*   Updated: 2021/10/13 19:25:09 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *set)
{
	int			ix;
	unsigned long limit;
	t_setting	*setting;
	
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
		if (setting->data->number_of_done_to_eat == setting->data->number_of_philo)
			return (0);
		usleep(100);
		ix++;
		if (ix == setting->data->number_of_philo)
			ix = 0;
	}	
	return (0);
}