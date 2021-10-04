/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 07:04:42 by jekim             #+#    #+#             */
/*   Updated: 2021/10/05 00:12:03 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	run_philo(t_setting *set)
{
	int	ix;

	ix = 0;
	while (ix < set->data->number_of_philo)
	{
		set->philo[ix].pid = fork();
		if (set->philo[ix].pid < 0)
			return (1);
		if (set->philo[ix].pid == 0)
		{
			philo_routine(&set->philo[ix]);
			exit(0);
		}
		usleep(100);
		ix++;
	}
	return (0);
}

int	assign_setting(t_setting *set, int argc, char **argv)
{
	if (validate_argv(argc, argv)
		|| assign_data(set, argc, argv)
		|| validate_assigned_data(set)
		|| assign_philo(set))
		return (ERROR_OCCURED);
	return (0);
}

int	main(int argc, char **argv)
{
	t_setting	set;

	if (assign_setting(&set, argc, argv)
		|| run_philo(&set))
		ft_strerr("Error\n");
	return (0);
}