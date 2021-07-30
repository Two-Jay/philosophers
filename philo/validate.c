/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:40:40 by jekim             #+#    #+#             */
/*   Updated: 2021/07/31 02:38:42 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

t_data	*fn_datanew(int argc)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(data));
	data->params_arr = (int *)ft_calloc(sizeof(int), argc - 1);
	data->philo_arr = NULL;
	data->fork_arr = NULL;
	return (data);
}

int	fn_validate_input(int argc, char **argv, t_data *data)
{
	int	ix;
	int	err_flag;

	ix = 0;
	err_flag = 0;
	if (argc < 5)
		return (fn_print_err("Error : a few params\n", data));
	if (argc > 6)
		return (fn_print_err("Error : too many params\n", data));
	while (ix < argc - 1 && !err_flag)
	{
		err_flag = ft_isable_strtonbr(argv[ix + 1]);
		if (!err_flag)
			data->params_arr[ix] = ft_atoi_covf(argv[ix + 1], &err_flag);
		if (err_flag || data->params_arr[ix] < 0)
			return (fn_print_err("Error : your input was error\n", data));
		ix++;
	}
	return (err_flag);
}

int	fn_assign_data(int argc, t_data *data)
{
	data->number_philo = data->params_arr[0];
	data->T_die = data->params_arr[1];
	data->T_eat = data->params_arr[2];
	data->T_sleep = data->params_arr[3];
	if (argc == 6)
		data->number_must_eat = data->params_arr[4];
	return (0);
}

int	fn_set_params(int argc, char **argv, t_data *data)
{
	if (fn_validate_input(argc, argv, data)
		|| fn_assign_data(argc, data))
		return (1);
	return (0);
}