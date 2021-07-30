/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:13:05 by jekim             #+#    #+#             */
/*   Updated: 2021/07/31 08:58:31 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	fn_print_err(char *err, t_data *data)
{
	write(2, err, ft_strlen(err));
	fn_clear_data(data, 0);
	return (1);
}

int	fn_clear_data(t_data *data, int ret)
{
	free(data->philo_arr);
	free(data->fork_arr);
	free(data);
	return (ret);
}

long	fn_gettime_milisec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}