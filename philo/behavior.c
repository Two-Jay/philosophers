/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/25 00:30:01 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int do_sleep_think(t_philo *philo, t_data *data)
{
	philo->state = SLEEP;
	print_messsage_stdout(philo);
	get_sleep(data->time_to_sleep, data, philo);
	check_philo_health(philo, 0);
	philo->state = THINK;
	print_messsage_stdout(philo);
	check_philo_health(philo, 0);
	return (0);
}

int do_eat(t_philo *philo, t_data *data)
{
	philo->state = EAT;
	print_messsage_stdout(philo);
	get_sleep(data->time_to_eat, data, philo);
	check_philo_health(philo, 1);
	return (0);
}

void	*routine(void *phl)
{
	t_philo *philo;

	philo = (t_philo *)phl;
	while (1)
	{
		if (take_forks(philo)
			|| do_eat(philo, philo->data)
			|| leave_forks(philo)
			|| do_sleep_think(philo, philo->data))
			break ;
		if (philo->data->number_of_time_must_eat == 0)
		{
			philo->state = END;
			print_messsage_stdout(philo);
			philo->data->number_of_done_to_eat++;
			break ;
		}
		if (philo->data->number_of_time_must_eat > 0)
			philo->data->number_of_time_must_eat -= 1;
	}
	return (NULL);
}