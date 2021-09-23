/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:41:24 by jekim             #+#    #+#             */
/*   Updated: 2021/09/22 23:47:12 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_setting *set)
{
	set->data = malloc(sizeof(t_data));
	if (!set->data)
		return (1);
	set->data->number_of_philo = 0;
	set->data->time_to_die = 0;
	set->data->time_to_eat = 0;
	set->data->time_to_sleep = 0;
	set->data->isAnyoneDead = 0;
	set->data->number_of_time_must_eat = -1;
	set->data->number_of_done_to_eat = -1;
	return (0);
}

int	check_argc(int argc)
{
	return ((argc != 5 && argc != 6));
}

int	validate_argv(int argc, char **argv)
{
	int	ix;
	int	ret;

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
