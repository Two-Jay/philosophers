/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:13:05 by jekim             #+#    #+#             */
/*   Updated: 2021/07/30 20:20:27 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	fn_print_err(char *err)
{
	write(2, err, ft_strlen(err));
	return (0);
}

int	fn_clear_data(t_data *data)
{
	int	ix;

	ix = 0;
	while (data->philo_arr[ix])
		free(data->philo_arr[ix++]);
	ix = 0;
	while (data->fork_arr[ix])
		free(data->fork_arr[ix++]);
	free(data);
	return (0);
}