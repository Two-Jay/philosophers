/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:24:09 by jekim             #+#    #+#             */
/*   Updated: 2021/09/22 00:30:29 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int test_take_forks(t_philo *philo)
{
	take_rfork(philo);
	take_lfork(philo);
	return (0);
}

int test_print_assigned_data(t_data *data)
{
	printf("=========================================\nthis simulation has runned with those arg\nnumber_of_philo : %d\ntime_to_die : %lu\ntime_to_eat : %lu\ntime_to_sleep : %lu\nmust_eat_time : %d\n=========================================\n",
		data->number_of_philo,
		data->time_to_die,
		data->time_to_eat,
		data->time_to_sleep,
		data->number_of_time_must_eat);
	return (0);
}