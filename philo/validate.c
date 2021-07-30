/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:40:40 by jekim             #+#    #+#             */
/*   Updated: 2021/07/30 21:21:52 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

t_data	*fn_datanew(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(data));
	data->philo_arr = NULL;
	data->fork_arr = NULL;
	return (data);
}

int	fn_validate_input(int argc, char **argv, int *params_arr)
{
	int	ix;
	int	ovf_flag;

	ix = 0;
	ovf_flag = 0;
	if (argc != 5 && argc != 6)
		fn_print_err("Error : a few params\n");
	while (ix < argc - 1 && !ft_isable_strtonbr(argv[ix + 1]) && !ovf_flag)
	{
		params_arr[ix] = ft_atoi_covf(argv[ix + 1], &ovf_flag);
		ft_printf("value [%d], ovf_flag [%d]\n", params_arr[ix], ovf_flag);
		if (ovf_flag)
			fn_print_err("Error : your input was overflowed\n");
		ix++;
	}
	return (ovf_flag);
}

int	fn_set_params(int argc, char **argv, t_data *data)
{
	int	ix;
	int	*params_arr;

	(void)data;
	params_arr = (int *)ft_calloc(sizeof(int), argc - 1);
	fn_validate_input(argc, argv, params_arr);
	ix = 0;
	while (ix < argc - 1)
	{
		ft_printf("params_arr[%d] -> [%d]\n", ix, params_arr[ix]);
		ix++;
	}
	return (0);
}