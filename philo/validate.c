/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:40:40 by jekim             #+#    #+#             */
/*   Updated: 2021/07/30 21:04:25 by jekim            ###   ########seoul.kr  */
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

	ix = 1;
	if (argc < 5 || argc > 6)
		fn_print_err("Error : a few params\n");
	params_arr = (int *)ft_calloc(sizeof(int), argc - 1);
	while (argv[ix] && ft_isable_strtonbr(argv[ix]))
	{
		params_arr[ix - 1] = ft_atoi_covf(argv[ix], &ovf_flag);
		if (ovf_flag)
			fn_print_err("Error : your input was overflowed");
	}
	return (0);
}

int	fn_set_params(int argc, char **argv, t_data *data)
{
	int	ix;
	int	*params_arr;

	(void)data;
	params_arr = NULL;
	fn_validate_input(argc, argv, params_arr);
	ix = 0;
	while (ix < argc)
	{
		ft_printf("params_arr[%d] -> [%d]", ix, params_arr[ix]);
		ix++;
	}
	return (0);
}