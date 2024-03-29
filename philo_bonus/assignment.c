/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 02:11:02 by jekim             #+#    #+#             */
/*   Updated: 2021/10/05 00:41:19 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	assign_data(t_setting *set, int argc, char **argv)
{
	set->data = malloc(sizeof(t_data));
	if (!set->data)
		return (ERROR_OCCURED);
	set->data->number_of_philo = ft_atoi(argv[1]);
	set->data->time_to_die = ft_atoi(argv[2]);
	set->data->time_to_eat = ft_atoi(argv[3]);
	set->data->time_to_sleep = ft_atoi(argv[4]);
	set->data->number_of_time_must_eat = -1;
	set->data->number_of_done_to_eat = -1;
	if (argc == 6)
	{
		set->data->number_of_time_must_eat = ft_atoi(argv[5]);
		set->data->number_of_done_to_eat = 0;
	}
	return (0);
}

int	assign_philo(t_setting *set, int argc, char **argv)
{
	int		ix;
	t_state	state;

	ix = 0;
	state = 0;
	set->philo = (t_philo *)malloc(
			sizeof(t_philo) * set->data->number_of_philo);
	if (!set->philo)
		return (ERROR_OCCURED);
	while (ix < set->data->number_of_philo)
	{
		memset(&set->philo[ix], 0, sizeof(t_philo));
		set->data->number_of_time_must_eat = -1;
		if (argc == 6)
			set->data->number_of_time_must_eat = ft_atoi(argv[5]);
		set->philo[ix].data = set->data;
		set->philo[ix].id = ix + 1;
		set->philo[ix].state = state;
		ix++;
	}
	return (0);
}