/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:13:05 by jekim             #+#    #+#             */
/*   Updated: 2021/07/30 21:02:28 by jekim            ###   ########seoul.kr  */
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
	free(data->philo_arr);
	free(data->fork_arr);
	free(data);
	return (0);
}