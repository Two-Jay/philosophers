/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/28 20:42:57 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_sleep_think(t_philo *philo, t_data *data)
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

int	do_eat(t_philo *philo, t_data *data)
{
	if (data->number_of_philo == 1)
		get_sleep(2147483600, data, philo);
	take_forks(philo);
	philo->state = EAT;
	print_messsage_stdout(philo);
	check_philo_health(philo, 1);
	get_sleep(data->time_to_eat, data, philo);
	leave_forks(philo);
	return (0);
}

int	check_nbr_must_eat(t_philo *philo, t_data *data)
{
	if (data->number_of_time_must_eat == 0)
	{
		philo->state = END;
		print_messsage_stdout(philo);
		data->number_of_done_to_eat++;
		return (1);
	}
	if (data->number_of_time_must_eat > 0)
		data->number_of_time_must_eat -= 1;
	return (0);
}

void	*philo_routine(void *phl)
{
	t_philo	*philo;

	philo = (t_philo *)phl;
	philo->lasteat_tv = philo->data->start_tv;
	while (1)
	{
		if (do_eat(philo, philo->data)
			|| check_nbr_must_eat(philo, philo->data)
			|| do_sleep_think(philo, philo->data))
			break ;
	}
	return (NULL);
}
