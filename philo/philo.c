/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:10 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 00:28:04 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int run_philo(t_data *data)
{
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (set_data(&data, argc, argv) || run_philo(&data))
		return (ft_strerr("Error\n"));
	return (free_data(&data));
}
