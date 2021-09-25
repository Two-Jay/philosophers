/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:20:43 by jekim             #+#    #+#             */
/*   Updated: 2021/09/25 00:28:45 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*(s + i++))
		;
	return (i);
}

int	ft_strerr(char *err)
{
	if (err)
		write(2, err, ft_strlen(err));
	return (ERROR_OCCURED);
}

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
	static unsigned long	modf;
	static struct timeval	former_tv;
	struct timeval			now_tv;
	unsigned long			now_time;

	if (former_tv.tv_sec == 0 && former_tv.tv_usec == 0)
		former_tv = philo->data->time_to_start_tv;
	if ((modf++) % 2 == 0 || eat_flag == 1)
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
		usleep(data->number_of_philo / 4);
		if (check_philo_health(philo, 0))
			return (1);
	}
	return (0);
}