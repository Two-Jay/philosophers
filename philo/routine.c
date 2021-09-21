/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 18:50:34 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_lfork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(fork);
	philo->l_fork = fork->id;
	fork->grabbedby = philo->id;
	pthread_mutex_unlock(fork);
	philo->state = FORK;
	print_messsage_stdout(philo);
}

void take_rfork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(fork);
	philo->r_fork = fork->id;
	fork->grabbedby = philo->id;
	pthread_mutex_unlock(fork);
	philo->state = FORK;
	print_messsage_stdout(philo);
}

void take_forks(t_philo *philo)
{
	pthread_mutex_lock(fork);
	philo->l_fork = fork->id;
	fork->grabbedby = philo->id;
	pthread_mutex_unlock(fork);
	philo->state = LFORK;
	print_messsage_stdout(philo);
	//
	pthread_mutex_lock(fork);
	philo->r_fork = fork->id;
	fork->grabbedby = philo->id;
	pthread_mutex_unlock(fork);
	philo->state = RFORK;
	print_messsage_stdout(philo);
}

void leave_forks(t_philo *philo, t_fork *lfork, t_fork *rfork)
{
	pthread_mutex_lock(lfork);
	pthread_mutex_lock(rfork);
	philo->r_fork = 0;
	philo->l_fork = 0;
	lfork->grabbedby = 0;
	rfork->grabbedby = 0;
	pthread_mutex_unlock(fork);
	pthread_mutex_unlock(fork);
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
	take_lfork(philo, fork[philo->id + 1]);
	take_rfork(philo, fork[philo->id]);
	philo->state = EAT;
	print_messsage_stdout(philo);
	usleep(data->time_to_eat);
	leave_forks(philo, fork[philo->id + 1], fork[philo->id]);
}

void	*routine(void *phl)
{
	t_philo *philo;

	philo = (t_philo *)phl;
	philo->data->time_to_start = fn_gettimenow();
	while (1)
	{
		if (eat()
			|| sleep()
			|| think())
			break ;
	}
	return (NULL);
}

int	run_philo(t_setting *set)
{
	int ix;
	struct timeval start;

	ix = 0;
	gettimeofday(&start, NULL);
	set->data->time_to_start_tv = start;
	while (ix < set->data->number_of_philo)
	{
		pthread_create(set->philo[ix].tid,
			NULL,
			routine,
			(void *)&set->philo[ix]);
		pthread_detach(*set->philo[ix].tid);
		usleep(100); // 순서보장
		ix++;
	}
	return (0);
}
