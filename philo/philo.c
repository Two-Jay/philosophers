/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:10 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 18:47:42 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_data(t_setting *set, int argc, char **argv)
{
	if (init_data(set)
		|| check_argc(argc)
		|| validate_arg(argc, argv)
		|| assign_data(set, argc, argv)
		|| assign_fork(set)
		|| assign_philo(set))
		return (ERROR_OCCURED);
	return (0);
}

int	main(int argc, char **argv)
{
	t_setting set;

	if (set_data(&set, argc, argv) || run_philo(&set))
		return (ft_strerr("Error\n"));
	return (free_data(&set));
}
