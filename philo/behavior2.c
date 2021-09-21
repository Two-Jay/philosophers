/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:39:02 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 15:51:50 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_lfork(t_philo *philo)
{
	t_fork *target;

	if (philo->id == 1)
        target = &philo->fork[0];
	target = &philo->fork[philo->id];
	pthread_mutex_lock(&target->fork_m);
	philo->l_fork = target->id;
	target->grabbedby = philo->id;
	pthread_mutex_unlock(&target->fork_m);
	philo->state = LFORK;
	print_messsage_stdout(philo);
    printf(" : %dth fork\n", philo->id);
}

void take_rfork(t_philo *philo)
{
	t_fork *target;

    if (philo->id == philo->data->number_of_philo)
        target = &philo->fork[0];
	target = &philo->fork[philo->id - 1];
	pthread_mutex_lock(&target->fork_m);
	philo->l_fork = target->id;
	target->grabbedby = philo->id;
	pthread_mutex_unlock(&target->fork_m);
	philo->state = RFORK;
	print_messsage_stdout(philo);
    printf(" : %dth fork\n", (philo->id == philo->data->number_of_philo) ? 0 : philo->id - 1);
}

void leave_forks(t_philo *philo)
{
	t_fork *rfork;
	t_fork *lfork;
	
	rfork = &philo->fork[philo->id + 1];
	lfork = &philo->fork[philo->id];
	pthread_mutex_lock(&rfork->fork_m);
	rfork->grabbedby = 0;
	philo->r_fork = 0;
	pthread_mutex_unlock(&rfork->fork_m);
	pthread_mutex_lock(&lfork->fork_m);
	lfork->grabbedby = 0;
	philo->l_fork = 0;
	pthread_mutex_unlock(&lfork->fork_m);
    philo->state = DFORK;
    print_messsage_stdout(philo);
}