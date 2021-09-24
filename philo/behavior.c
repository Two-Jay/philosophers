/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/25 04:32:43 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int take_forks(t_philo *philo)
{
	t_fork *lfork;
	t_fork *rfork;

	lfork = &philo->fork[philo->id - 1];
	rfork = &philo->fork[philo->id % philo->data->number_of_philo];
	if (philo->data->number_of_philo == 1)
		return (1);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&lfork->fork_m);
		philo->l_fork = lfork->id;
		pthread_mutex_lock(&rfork->fork_m);
		philo->r_fork = rfork->id;
	}
	else
	{
		pthread_mutex_lock(&rfork->fork_m);
		philo->r_fork = rfork->id;
		pthread_mutex_lock(&lfork->fork_m);
		philo->l_fork = lfork->id;
	}
	philo->state = FORK;
	print_messsage_stdout(philo);
	return (0);
}

int leave_forks(t_philo *philo)
{
	t_fork *rfork;
	t_fork *lfork;

	lfork = &philo->fork[philo->id - 1];
	rfork = &philo->fork[philo->id % philo->data->number_of_philo];
	philo->r_fork = 0;
	pthread_mutex_unlock(&rfork->fork_m);
	philo->l_fork = 0;
	pthread_mutex_unlock(&lfork->fork_m);
	if (!philo->data->isAnyoneDead)
	{
		philo->state = DFORK;
		print_messsage_stdout(philo);
	}
	return (0);
}

int do_sleep_think(t_philo *philo, t_data *data)
{
	philo->state = SLEEP;
	print_messsage_stdout(philo);
	get_sleep(data->time_to_sleep, data, philo);
	check_philo_health(philo, 0);
	philo->state = THINK;
	print_messsage_stdout(philo);
	check_philo_health(philo, 0);
	return (0);
}

int	do_eat(t_philo *philo, t_data *data)
{
	philo->state = EAT;
	print_messsage_stdout(philo);
	get_sleep(data->time_to_eat, data, philo);
	check_philo_health(philo, 1);
	if (philo->data->number_of_time_must_eat > 0)
		philo->data->number_of_time_must_eat -= 1;
	if (philo->data->number_of_time_must_eat == 0)
	{
		philo->state = END;
		print_messsage_stdout(philo);
		leave_forks(philo);
		philo->data->number_of_done_to_eat++;
		return (1);
	}
	return (0);
}

void	*routine(void *phl)
{
	t_philo	*philo;

	philo = (t_philo *)phl;
	while (1)
	{
		if (take_forks(philo)
			|| do_eat(philo, philo->data)
			|| leave_forks(philo)
			|| do_sleep_think(philo, philo->data))
			break ;
	}
	return (NULL);
}