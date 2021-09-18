/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:41:24 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 02:44:11 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data)
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

int	check_argc(int argc)
{
	return ((argc != 5 && argc != 6));
}

int	validate_arg(int argc, char **argv)
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
