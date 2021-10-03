/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 02:11:02 by jekim             #+#    #+#             */
/*   Updated: 2021/10/04 02:29:06 by jekim            ###   ########seoul.kr  */
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

int	validate_argv(int argc, char **argv)
{
	int	ix;
	int	ret;

	if ((argc != 5 && argc != 6))
		return (ERROR_OCCURED);
	ix = 1;
	ret = 1;
	while (ix < argc)
	{
		if (argv[ix] && ft_isable_strtonbr(argv[ix]))
			ix++;
		else
		{
			ret--;
			break ;
		}
	}
	return ((ix != argc));
}

int	validate_assigned_data(t_setting *set)
{
	if (set->data->number_of_philo < 1
		|| set->data->number_of_philo > 200
		|| set->data->number_of_time_must_eat < -1
		|| set->data->time_to_die < 60
		|| set->data->time_to_eat < 60
		|| set->data->time_to_sleep < 60)
		return (ERROR_OCCURED);
	return (0);
}
