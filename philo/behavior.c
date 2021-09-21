/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 04:55:37 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_lfork(t_philo *philo)
{
	t_fork *target;

	target = &philo->fork[philo->id];
	pthread_mutex_lock(&target->fork_m);
	philo->l_fork = target->id;
	target->grabbedby = philo->id;
	pthread_mutex_unlock(&target->fork_m);
	philo->state = FORK;
	print_messsage_stdout(philo);
}

void take_rfork(t_philo *philo)
{
	t_fork *target;

	target = &philo->fork[philo->id + 1];
	pthread_mutex_lock(&target->fork_m);
	philo->l_fork = target->id;
	target->grabbedby = philo->id;
	pthread_mutex_unlock(&target->fork_m);
	philo->state = FORK;
	print_messsage_stdout(philo);
}

void leave_forks(t_philo *philo, t_fork *lfork, t_fork *rfork)
{
	pthread_mutex_lock(rfork);
	philo->r_fork = 0;
	rfork->grabbedby = 0;
	pthread_mutex_unlock(rfork);
	pthread_mutex_lock(lfork);
	philo->l_fork = 0;
	lfork->grabbedby = 0;
	pthread_mutex_unlock(lfork);
}

int sleep(t_philo *philo, t_data *data)
{
	philo->state = SLEEP;
	print_messsage_stdout(philo);
	usleep(data->time_to_sleep);
}

int think(t_philo *philo)
{
	philo->state = THINK;
	print_messsage_stdout(philo);
}

int eat(t_philo *philo, t_data *data)
{
	take_lfork(philo);
	take_rfork(philo);
	if (fn_gettimenow(philo) > philo->last_eat_time)
	{
		leave_forks(philo, fork[philo->id + 1], fork[philo->id]);
		return (ERROR_OCCURED);
	}
	else
	{
		usleep(data->time_to_eat);
		philo->state = EAT;
		print_messsage_stdout(philo);
		leave_forks(philo, fork[philo->id + 1], fork[philo->id]);
	}
	return (0);
}

