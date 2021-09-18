/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:41:24 by jekim             #+#    #+#             */
/*   Updated: 2021/09/18 23:54:34 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->number_of_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	return (0);
}

int check_argc(int argc)
{
	return ((argc != 5 && argc != 6));
}

int validate_arg(int argc, char **argv)
{
	int ix;
	int ret;

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

int assign_arg(t_data *data, int argc, char** argv)
{
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_time_must_eat = ft_atoi(argv[5]);
	return (0);
}

int set_data(t_data *data, int argc, char **argv)
{
	if (init_data(data)
		|| check_argc(argc)
		|| validate_arg(argc, argv)
		|| assign_arg(data, argc, argv))
		return (1);
	return (0);
}