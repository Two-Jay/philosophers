/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:35:41 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 15:40:13 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_message_by_state(t_state state)
{
	if (state == LFORK)
		return ("has taken a fork on the left\n");
	if (state == RFORK)
		return ("has taken a fork on the right\n");
	if (state == DFORK)
		return ("laid down his forks\n");
	if (state == EAT)
		return ("is eating\n");
	if (state == SLEEP)
		return ("is sleeping\n");
	if (state == THINK)
		return ("is thinking\n");
	if (state == END)
		return ("was eaten as the philo must eat\n");
	if (state == DIE)
		return ("died  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	return (0);
}

int	print_messsage_stdout(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->isAnyoneDead_mtx));
	printf("%lu ms %dth philo %s",
		fn_gettimenow(philo->data),
		philo->id,
		get_message_by_state(philo->state));
	if (philo->data->isAnyoneDead == 0)
		pthread_mutex_unlock(&(philo->data->isAnyoneDead_mtx));
	return (0);
}

int test_print_assigned_data(t_data *data)
{
	printf("=========================================\nthis simulation has runned with those arg\nnumber_of_philo : %d\ntime_to_dir : %lu\ntime_to_eat : %lu\ntime_to_sleep : %lu\nmust_eat_time : %d\n=========================================\n",
		data->number_of_philo,
		data->time_to_die,
		data->time_to_eat,
		data->time_to_sleep,
		data->number_of_time_must_eat);
	return (0);
}