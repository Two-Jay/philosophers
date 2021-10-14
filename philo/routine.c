/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/10/14 19:50:52 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_sleep_think(t_philo *philo, t_data *data)
{
	print_message_stdout(philo, SLEEP);
	get_sleep(data->time_to_sleep);
	print_message_stdout(philo, THINK);
	return (0);
}

int	do_eat(t_philo *philo, t_data *data)
{
	print_message_stdout(philo, EAT);
	philo->last_eat_time = get_time();
	get_sleep(data->time_to_eat);
	if (++(philo->eat_cnt) == data->number_of_time_must_eat)
		data->number_of_done_to_eat++;
	return (0);
}

void	*philo_routine(void *phl)
{
	t_philo	*philo;

	philo = (t_philo *)phl;
	philo->is_over = 0;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (1)
	{
		if (take_forks(philo)
			|| do_eat(philo, philo->data)
			|| leave_forks(philo)
			|| do_sleep_think(philo, philo->data))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
