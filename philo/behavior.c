/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 15:39:26 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int do_sleep_than_think(t_philo *philo, t_data *data)
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
		do_eat(philo, philo->data);
		do_sleep_than_think(philo, philo->data);
	}
	return (NULL);
}
