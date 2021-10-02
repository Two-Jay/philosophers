/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:20:43 by jekim             #+#    #+#             */
/*   Updated: 2021/10/03 06:33:34 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	nowtv;

	gettimeofday(&nowtv, NULL);
	return ((nowtv.tv_sec * 1000) +(nowtv.tv_usec / 1000));
}

int	get_sleep(unsigned long sleep_time)
{
	unsigned long	target_time;

	target_time = sleep_time + get_time();
	while (target_time > get_time())
		;
	return (0);
}

int	print_messsage_stdout(t_philo *philo)
{
	char	*msg;

	if (philo->state == FORK)
		msg = "has taken a fork.\n";
	if (philo->state == EAT)
		msg = "is eating.\n";
	if (philo->state == SLEEP)
		msg = "is sleeping.\n";
	if (philo->state == THINK)
		msg = "is thinking.\n";
	if (philo->state == END)
		msg = "was eaten as the philo must eat.\n";
	if (philo->state == DIE)
		msg = "dead.\n";
	pthread_mutex_lock(&(philo->data->isAnyoneDead_mtx));
	printf("%lu ms %dth philo %s",
		get_time() - philo->data->start_time,
		philo->id,
		msg);
	if (philo->state == DIE)
		philo->data->isAnyoneDead++;
	else
		pthread_mutex_unlock(&(philo->data->isAnyoneDead_mtx));
	return (0);
}