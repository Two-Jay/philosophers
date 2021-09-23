/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/23 19:29:26 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int do_sleep_think(t_philo *philo, t_data *data)
{
	philo->state = SLEEP;
	print_messsage_stdout(philo);
	get_sleep(data->time_to_sleep, data);
	usleep(data->time_to_sleep * 1000);
	philo->state = THINK;
	print_messsage_stdout(philo);
	return (0);
}

int do_eat(t_philo *philo, t_data *data)
{
	unsigned long tmp;

	philo->state = EAT;
	print_messsage_stdout(philo);
	get_sleep(data->time_to_sleep, data);
	tmp = fn_gettimenow(data) - philo->last_eat_time;
	// printf("%dth philo dead detecting... %lu || %lu\n", philo->id, tmp, philo->last_eat_time);
	// if (tmp - philo->last_eat_time > data->time_to_die)
	// {
	// 	philo->state = DIE;
	// 	philo->data->isAnyoneDead++;
	// 	print_messsage_stdout(philo);
	// 	return (ERROR_OCCURED);
	// }
	// else
	// {
	// 	philo->last_eat_time = tmp;
	// 	return (0);
	// }
}

// 죽음탐지는 어떻게 해야하나?

void	*routine(void *phl)
{
	t_philo *philo;

	philo = (t_philo *)phl;
	while (1)
	{
		if (take_forks(philo)
			|| do_eat(philo, philo->data) // 
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