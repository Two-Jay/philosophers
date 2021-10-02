/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:39:02 by jekim             #+#    #+#             */
/*   Updated: 2021/10/03 04:47:13 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_lfork(t_philo *philo)
{
	t_fork	*lfork;

	lfork = &philo->fork[philo->id - 1];
	pthread_mutex_lock(&lfork->fork_m);
	philo->l_fork = lfork->id;
	lfork->grabbedby = philo->id;
	philo->state = FORK;
	print_messsage_stdout(philo);
}

void	take_rfork(t_philo *philo)
{
	t_fork	*rfork;

	rfork = &philo->fork[philo->id % philo->data->number_of_philo];
	pthread_mutex_lock(&rfork->fork_m);
	philo->r_fork = rfork->id;
	rfork->grabbedby = philo->id;
	philo->state = FORK;
	print_messsage_stdout(philo);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_m);
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
	pthread_mutex_unlock(&philo->philo_m);
	return (0);
}

int	leave_forks(t_philo *philo)
{
	t_fork	*rfork;
	t_fork	*lfork;

	pthread_mutex_lock(&philo->philo_m);
	lfork = &philo->fork[philo->id - 1];
	rfork = &philo->fork[philo->id % philo->data->number_of_philo];
	rfork->grabbedby = 0;
	philo->r_fork = 0;
	pthread_mutex_unlock(&rfork->fork_m);
	lfork->grabbedby = 0;
	philo->l_fork = 0;
	pthread_mutex_unlock(&lfork->fork_m);
	pthread_mutex_unlock(&philo->philo_m);
	return (0);
}
