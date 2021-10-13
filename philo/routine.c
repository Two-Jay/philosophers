/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/10/13 18:44:44 by jekim            ###   ########.fr       */
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
	return (0);
}

int	check_nbr_must_eat(t_philo *philo)
{
	if (philo->number_of_time_must_eat == 0)
	{
		print_message_stdout(philo, END);
		leave_forks(philo);
		philo->is_over++;
		philo->data->number_of_done_to_eat++;
		return (1);
	}
	else if (philo->number_of_time_must_eat > 0)
		philo->number_of_time_must_eat -= 1;
	return (0);
}

void	*philo_routine(void *phl)
{
	t_philo	*philo;

	philo = (t_philo *)phl;
	philo->last_eat_time = philo->data->start_time;
	philo->is_over = 0;
	while (1)
	{
		if (take_forks(philo)
			|| do_eat(philo, philo->data)
			|| check_nbr_must_eat(philo)
			|| leave_forks(philo)
			|| do_sleep_think(philo, philo->data))
			break ;
	}
	return (NULL);
}
