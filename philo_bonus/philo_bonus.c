/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 07:04:42 by jekim             #+#    #+#             */
/*   Updated: 2021/10/04 02:32:38 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	assign_setting(t_setting *set, int argc, char **argv)
{
	if (validate_argv(argc, argv)
		|| assign_data(set, argc, argv)
		|| validate_assigned_data(set))
		return (ERROR_OCCURED);
	return (0);
}

int	main(void)
{
	t_setting	set;

	if (assign_setting(&set))
		ft_strerr("Error\n");
	return (0);
}