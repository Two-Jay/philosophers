/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/10/13 20:49:33 by jekim            ###   ########.fr       */
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
	philo->eat_cnt++;
	return (0);
}

void	*philo_routine(void *phl)
{
	t_philo	*philo;

	philo = (t_philo *)phl;
	philo->is_over = 0;
	while (1)
	{
		if (take_forks(philo)
			|| do_eat(philo, philo->data)
			|| leave_forks(philo)
			|| do_sleep_think(philo, philo->data))
			return (NULL);
	}
	return (NULL);
}
