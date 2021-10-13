/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 05:14:22 by jekim             #+#    #+#             */
/*   Updated: 2021/10/13 18:43:48 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_lfork(t_philo *philo)
{
	print_message_stdout(philo, FORK);
}

void	take_rfork(t_philo *philo)
{
	print_message_stdout(philo, FORK);
}

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		take_lfork(philo);
		take_rfork(philo);
	}
	else
	{
		take_rfork(philo);
		take_lfork(philo);
	}
	return (0);
}

int	leave_forks(t_philo *philo)
{
	(void)philo;
	return (0);
}

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

int	philo_routine(t_philo *philo)
{
	philo->last_eat_time = philo->data->start_time;
	philo->is_over = 0;
	while (1)
	{

		if (take_forks(philo)
			|| do_eat(philo, philo->data)
			|| check_nbr_must_eat(philo)
			|| leave_forks(philo)
			|| do_sleep_think(philo, philo->data))
			exit (1);
	}
	exit(0);
}