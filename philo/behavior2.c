/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:39:02 by jekim             #+#    #+#             */
/*   Updated: 2021/09/25 17:12:34 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_lfork(t_philo *philo)
{
	t_fork	*target;

	target = &philo->fork[philo->id - 1];
	pthread_mutex_lock(&target->fork_m);
	philo->l_fork = target->id;
	target->grabbedby = philo->id;
}

void	take_rfork(t_philo *philo)
{
	t_fork	*target;

	target = &philo->fork[philo->id % philo->data->number_of_philo];
	pthread_mutex_lock(&target->fork_m);
	philo->r_fork = target->id;
	target->grabbedby = philo->id;
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
	philo->state = FORK;
	print_messsage_stdout(philo);
	return (0);
}

int	leave_forks(t_philo *philo)
{
	t_fork	*rfork;
	t_fork	*lfork;

	lfork = &philo->fork[philo->id - 1];
	rfork = &philo->fork[philo->id % philo->data->number_of_philo];
	rfork->grabbedby = 0;
	philo->r_fork = 0;
	pthread_mutex_unlock(&rfork->fork_m);
	lfork->grabbedby = 0;
	philo->l_fork = 0;
	pthread_mutex_unlock(&lfork->fork_m);
	if (!philo->data->isAnyoneDead)
	{
		philo->state = DFORK;
		print_messsage_stdout(philo);
	}
	return (0);
}
