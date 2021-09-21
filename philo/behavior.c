/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 19:36:57 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int do_sleep_think(t_philo *philo, t_data *data)
{
	philo->state = SLEEP;
	print_messsage_stdout(philo);
	usleep(data->time_to_sleep);
	philo->state = THINK;
	print_messsage_stdout(philo);
	return (0);
}

int do_eat(t_philo *philo, t_data *data)
{
	if (fn_gettime_from_lasteat(data) > data->time_to_die / 1000)
	{
		philo->state = DIE;
		philo->data->isAnyoneDead++;
		print_messsage_stdout(philo);
		return (ERROR_OCCURED);
	}
	else
	{
		philo->state = EAT;
		print_messsage_stdout(philo);
		usleep(data->time_to_eat);
		return (0);
	}
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
			break ;
		}
		if (philo->data->number_of_time_must_eat > 0)
			philo->data->number_of_time_must_eat -= 1;
		if (philo->data->isAnyoneDead)
			return (NULL);
	}
	return (NULL);
}