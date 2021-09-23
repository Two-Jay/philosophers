/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:10 by jekim             #+#    #+#             */
/*   Updated: 2021/09/23 18:38:13 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_philo(t_setting *set)
{
	int ix;
	struct timeval start;

	ix = 0;
	gettimeofday(&start, NULL);
	set->data->time_to_start_tv = start;
	while (ix < set->data->number_of_philo)
	{
		pthread_create(set->philo[ix].tid,
			NULL,
			routine,
			(void *)&set->philo[ix]);
		pthread_detach(*set->philo[ix].tid);
		ix++;
	}
	return (0);
}

int run_monitor(t_setting *set)
{
	while (1)
	{
		if (set->data->isAnyoneDead || (set->data->number_of_done_to_eat == set->data->number_of_philo))
			break ;
		usleep(100);
	}
	return (0);
}

int	set_data(t_setting *set, int argc, char **argv)
{
	if (init_data(set)
		|| check_argc(argc)
		|| validate_argv(argc, argv)
		|| assign_data(set, argc, argv)
		|| assign_fork(set)
		|| assign_philo(set)
		|| validate_assigned_data(set))
		return (ERROR_OCCURED);
	return (0);
}

int	main(int argc, char **argv)
{
	t_setting set;

	if (set_data(&set, argc, argv)
		|| test_print_assigned_data(set.data)
		|| run_philo(&set)
		|| run_monitor(&set))
		return (ft_strerr("Error\n"));
	return (free_data(&set));
}
