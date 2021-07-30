/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 05:06:14 by jekim             #+#    #+#             */
/*   Updated: 2021/07/31 02:33:31 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = fn_datanew(argc);
	if (fn_set_params(argc, argv, data))
		return (1);
	ft_printf("nbr philo [%d]\n", data->number_philo);
	ft_printf("time die [%d]\n", data->T_die);
	ft_printf("time eat [%d]\n", data->T_eat);
	ft_printf("time sleep [%d]\n", data->T_sleep);
	if (argc == 6)
		ft_printf("must eat time [%d]\n", data->number_must_eat);
	return (fn_clear_data(data, 0));
}
