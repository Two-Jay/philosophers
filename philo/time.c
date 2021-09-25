/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:20:43 by jekim             #+#    #+#             */
/*   Updated: 2021/09/25 17:32:30 by jekim            ###   ########.fr       */
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

int	check_philo_health(t_philo *philo, int eat_flag)
{
	static struct timeval	former_tv;
	struct timeval			now_tv;
	unsigned long			now_time;

	if (former_tv.tv_sec == 0 && former_tv.tv_usec == 0)
		former_tv = philo->data->time_to_start_tv;
	if (eat_flag == 1)
	{
		gettimeofday(&now_tv, NULL);
		now_time = time_diff(&former_tv, &now_tv);
		if (now_time > philo->data->time_to_die)
		{
			philo->state = DIE;
			philo->data->isAnyoneDead++;
			print_messsage_stdout(philo);
			leave_forks(philo);
			return (1);
		}
		if (eat_flag == 1)
			former_tv = now_tv;
	}
	return (0);
}

int	get_sleep(unsigned long sleep_time, t_data *data, t_philo *philo)
{
	unsigned long		target_time;

	target_time = sleep_time + time_from_start(data);
	while (target_time > time_from_start(data))
	{
		if (check_philo_health(philo, 0))
			return (1);
	}
	return (0);
}

int	print_messsage_stdout(t_philo *philo)
{
	char *msg;

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
	pthread_mutex_lock(&(philo->data->isAnyoneDead_mtx));
	printf("%lu ms %dth philo %s",
		time_from_start(philo->data),
		philo->id,
		msg);
	if (philo->data->isAnyoneDead == 0)
		pthread_mutex_unlock(&(philo->data->isAnyoneDead_mtx));
	return (0);
}
