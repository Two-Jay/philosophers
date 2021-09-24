/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:20:43 by jekim             #+#    #+#             */
/*   Updated: 2021/09/25 04:56:56 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	time_from_start(t_data *data)
{
	struct timeval	now_tv;
	struct timeval	start_tv;

	start_tv = data->time_to_start_tv;
	gettimeofday(&now_tv, NULL);
	return (((now_tv.tv_sec - start_tv.tv_sec) * 1000)
		+ ((now_tv.tv_usec - start_tv.tv_usec) / 1000));
}

unsigned long	time_diff(struct timeval *start, struct timeval *end)
{
	struct timeval	gaptime_tv;

	gaptime_tv.tv_sec = end->tv_sec - start->tv_sec;
	gaptime_tv.tv_usec = end->tv_usec - start->tv_usec;
	return (gaptime_tv.tv_sec * 1000 + gaptime_tv.tv_usec / 1000);
}

int check_philo_health(t_philo *philo, int eat_flag)
{
	struct timeval			now_tv;
	unsigned long			now_time;

	if (philo->lasteat_tv.tv_sec == 0 && philo->lasteat_tv.tv_usec == 0)
		philo->lasteat_tv = philo->data->time_to_start_tv;
	gettimeofday(&now_tv, NULL);
	now_time = time_diff(&philo->lasteat_tv, &now_tv);
	if (now_time > philo->data->time_to_die)
	{
		printf("\n\n%lu || %lu  %d philo died.....\n\n", now_time, philo->data->time_to_die, philo->id);
		philo->state = DIE;
		philo->data->isAnyoneDead++;
		print_messsage_stdout(philo);
		leave_forks(philo);
		return (1);
	}
	if (eat_flag)
		philo->lasteat_tv = now_tv;
	return (0);
}

int	get_sleep(unsigned long sleep_time, t_data *data, t_philo *philo)
{
	unsigned long			target_time;
	unsigned long			now_time;
	static unsigned long	modf;

	now_time = time_from_start(data);
	target_time = sleep_time + now_time;
	while (target_time > time_from_start(data))
	{
		usleep(30);
		if (check_philo_health(philo, 0))
			break ;
	}
	return (0);
}

int	print_messsage_stdout(t_philo *philo)
{
	char	*msg;

	pthread_mutex_lock(&(philo->data->isAnyoneDead_mtx));
	if (philo->state == FORK)
		msg = "has taken a fork.\n";
	if (philo->state == DFORK)
		msg = "has dropped a fork.\n";
	if (philo->state == EAT)
		msg = "is eating.\n";
	if (philo->state == SLEEP)
		msg = "is sleeping.\n";
	if (philo->state == THINK)
		msg = "is thinking.\n";
	if (philo->state == END)
		msg = "was eaten as the philo must eat.\n";
	if (philo->state == DIE)
		msg = "died.\n";
	printf("%lu ms %dth philo %s",
		time_from_start(philo->data),
		philo->id,
		msg);
	if (philo->data->isAnyoneDead == 0)
		pthread_mutex_unlock(&(philo->data->isAnyoneDead_mtx));
	return (0);
}