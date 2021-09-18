/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:10 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 02:58:08 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_philo(t_data *data)
{
	int ix;

	ix = 1;
	while (ix <= data->number_of_philo)
	{
		pthread_create(data->philo[ix - 1].tid, NULL, routine, (void *)&ix);
		ix++;
	}
	return (0);
}

int	set_data(t_data *data, int argc, char **argv)
{
	if (init_data(data)
		|| check_argc(argc)
		|| validate_arg(argc, argv)
		|| assign_data(data, argc, argv)
		|| assign_philo(data))
		return (ERROR_OCCURED);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (set_data(&data, argc, argv) || run_philo(&data))
		return (ft_strerr("Error\n"));
	return (free_data(&data));
}
