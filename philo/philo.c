/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:10 by jekim             #+#    #+#             */
/*   Updated: 2021/09/22 04:30:41 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_philo(t_setting *set)
{
	int ix;
	struct timeval start;

	ix = 0;
	gettimeofday(&start, NULL);
	set->data->time_to_start_tv = start;
	while (ix < set->data->number_of_philo)
	{
		pthread_create(set->philo[ix].tid,
			NULL,
			routine,
			(void *)&set->philo[ix]);
		pthread_detach(*set->philo[ix].tid);
		ix++;
	}
	return (0);
}
// monitor

// 1. 공용데이터 어떤 하나의 변수를 뮤텍스로 설정하고 set->data
// 2. 모든 스레드가 생성될때 1번의 뮤텍스를 잡고 있는 거...
// 3. 시작신호를 특정시점에 하는 거죠....
// 	- timeline 맞춰주고
// 	- detach(all_thread)
// 4. 2.에서 잡고 있던 뮤텍스 변수를 unlock

// 스레드 개별이 개별논리를 가지고
// 스레드의 집합으로 시뮬레이션을 돌릴때
// 공용자원에서 데드락 회피를 적절하게 해주면
// 시뮬레이션은 돌아간다.

int run_monitor(t_setting *set)
{
	while (1)
	{
		if (set->data->isAnyoneDead || (set->data->number_of_done_to_eat == set->data->number_of_philo))
			break ;
		usleep(100);
	}
	return (0);
}

int	set_data(t_setting *set, int argc, char **argv)
{
	if (init_data(set)
		|| check_argc(argc)
		|| validate_argv(argc, argv)
		|| assign_data(set, argc, argv)
		|| assign_fork(set)
		|| assign_philo(set)
		|| validate_assigned_data(set))
		return (ERROR_OCCURED);
	return (0);
}

int	main(int argc, char **argv)
{
	t_setting set;

	if (set_data(&set, argc, argv)
		|| test_print_assigned_data(set.data)
		|| run_philo(&set)
		|| run_monitor(&set))
		return (ft_strerr("Error\n"));
	return (free_data(&set));
}
