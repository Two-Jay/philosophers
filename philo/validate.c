/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:40:40 by jekim             #+#    #+#             */
/*   Updated: 2021/07/30 19:52:02 by jekim            ###   ########seoul.kr  */
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

int fn_validate_input(int argc, char **argv, t_data *data)
{
	(void)argc;
	(void)argv;
	(void)data;
	return (0);
}