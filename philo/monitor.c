/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:31:47 by jekim             #+#    #+#             */
/*   Updated: 2021/10/03 05:34:16 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *monitor_routine(void *mon)
{
	t_monitor		*monitor;
	unsigned long	limit;

	monitor = (t_monitor *)mon;
	limit = monitor->target_philo->data->time_to_die;
	while (1)
	{
		pthread_mutex_lock(&monitor->target_philo->philo_m);
		if (get_time() - monitor->target_philo->last_eat_time > limit)
		{
			print_endmessage_stdout(monitor->target_philo);
			return (0);
		}
		pthread_mutex_unlock(&monitor->target_philo->philo_m);
	}
	return (0);
}

int	run_monitor(t_setting *set)
{
	int	ix;

	ix = 0;
	while (ix < set->data->number_of_philo)
	{
		pthread_create(set->monitor[ix].tid,
			NULL,
			monitor_routine,
			(void *)&set->monitor[ix]);
		pthread_detach(*set->monitor[ix].tid);
		ix++;
	}
	return (0);
}

int	assign_monitor(t_setting *set)
{
	int	ix;
	int	limit;

	ix = 0;
	limit = set->data->number_of_philo;
	set->monitor = (t_monitor *)malloc(sizeof(t_monitor) * (limit));
	if (!set->monitor)
		return (ERROR_OCCURED);
	while (ix < limit)
	{
		set->monitor[ix].tid = (pthread_t *)malloc(sizeof(pthread_t));
		if (!set->monitor[ix].tid)
			return (ERROR_OCCURED);
		set->monitor[ix].target_philo = &(set->philo[ix]);
		set->monitor[ix].id = ix + 1;
		ix++;
	}
	return (0);
}

// 내일 해야할 것
// 2. 모니터 관련로직 구현
// 3. 테스트
// 미니쉘 : tty 관련 함수군 정리
// 토크나이저 구현