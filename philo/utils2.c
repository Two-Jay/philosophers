/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:20:43 by jekim             #+#    #+#             */
/*   Updated: 2021/10/13 19:04:38 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	nowtv;

	gettimeofday(&nowtv, NULL);
	return ((nowtv.tv_sec * 1000) +(nowtv.tv_usec / 1000));
}

int	get_sleep(unsigned long sleep_time)
{
	unsigned long	target_time;

	target_time = sleep_time + get_time();
	while (target_time > get_time())
		;
	return (0);
}

int	print_message_stdout(t_philo *philo, t_state state)
{
	char	*msg;

	if (state == FORK)
		msg = "has taken a fork.\n";
	if (state == EAT)
		msg = "is eating.\n";
	if (state == SLEEP)
		msg = "is sleeping.\n";
	if (state == THINK)
		msg = "is thinking.\n";
	if (state == END)
		msg = "was eaten as the philo must eat.\n";
	if (state == DIE)
		msg = "dead.\n";
	pthread_mutex_lock(&(philo->data->isAnyoneDead_mtx));
	printf("%lu ms %dth philo %s",
		get_time() - philo->data->start_time,
		philo->id,
		msg);
	if (state == DIE)
		philo->data->isAnyoneDead++;
	else
		pthread_mutex_unlock(&(philo->data->isAnyoneDead_mtx));
	return (0);
}

int	print_die_message_stdout(t_philo *philo)
{
	char	*msg;

	msg = "dead.\n";
	pthread_mutex_lock(&(philo->data->isAnyoneDead_mtx));
	printf("%lu ms %dth philo %s",
		get_time() - philo->data->start_time,
		philo->id,
		msg);
	philo->data->isAnyoneDead++;
	return (0);
}

int	validate_argv(int argc, char **argv)
{
	int	ix;
	int	ret;

	if ((argc != 5 && argc != 6))
		return (ERROR_OCCURED);
	ix = 1;
	ret = 1;
	while (ix < argc)
	{
		if (argv[ix] && ft_isable_strtonbr(argv[ix]))
			ix++;
		else
		{
			ret--;
			break ;
		}
	}
	return ((ix != argc));
}

int	validate_assigned_data(t_setting *set)
{
	if (set->data->number_of_philo < 1
		|| set->data->number_of_philo > 200
		|| set->data->number_of_time_must_eat < -1
		|| set->data->time_to_die < 60
		|| set->data->time_to_eat < 60
		|| set->data->time_to_sleep < 60)
		return (ERROR_OCCURED);
	return (0);
}
