/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 17:48:55 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int do_sleep(t_philo *philo, t_data *data)
{
	philo->state = SLEEP;
	print_messsage_stdout(philo);
	usleep(data->time_to_sleep);
	return (0);
}

int do_think(t_philo *philo)
{

	philo->state = THINK;
	print_messsage_stdout(philo);
	return (0);
}

int do_eat(t_philo *philo, t_data *data)
{
	take_lfork(philo);
	take_rfork(philo);
	usleep(data->time_to_eat);
	philo->state = EAT;
	print_messsage_stdout(philo);
	leave_forks(philo);
	return (0);
}

void	*routine(void *phl)
{
	t_philo *philo;

	philo = (t_philo *)phl;
	while (1)
	{
		if (do_eat(philo, philo->data)
			|| do_sleep(philo, philo->data)
			|| do_think(philo))
			break ;
		if (philo->data->number_of_time_must_eat == 0)
		{
			philo->state = END;
			print_messsage_stdout(philo);
			break ;
		}
		if (philo->data->number_of_time_must_eat > 0)
			philo->data->number_of_time_must_eat -= 1;
	}
	return (NULL);
}
