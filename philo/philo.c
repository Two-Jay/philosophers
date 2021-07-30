/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 05:06:14 by jekim             #+#    #+#             */
/*   Updated: 2021/07/30 19:48:52 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(void)
{
	t_data	*data;

	data = fn_datanew();
	ft_printf("data pointer [%p]\n", &data);
	ft_printf("data T_eat [%d]\n", data->T_eat);
	return (0);
}
