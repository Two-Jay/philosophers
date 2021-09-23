/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:20:43 by jekim             #+#    #+#             */
/*   Updated: 2021/09/23 20:27:11 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*(s + i++))
		;
	return (i);
}

int	ft_strerr(char *err)
{
	if (err)
		write(2, err, ft_strlen(err));
	return (ERROR_OCCURED);
}

unsigned long	fn_gettimenow(t_data *data)
{
	struct timeval	now_tv;
	struct timeval	start_tv;

	start_tv = data->time_to_start_tv;
	gettimeofday(&now_tv, NULL);
	return (((now_tv.tv_sec - start_tv.tv_sec) * 1000)
		+ ((now_tv.tv_usec - start_tv.tv_usec) / 1000));
}


int get_sleep(unsigned long target_time, t_data *data, t_philo *philo)
{
	unsigned long tmp;

	tmp = target_time + fn_gettimenow(data);
	while (tmp > fn_gettimenow(data))
	{
		if (check_philo_alive(philo))
		{
			leave_forks(philo);
			return (1);
		}
	}
	return (0);
}

int check_philo_alive(t_philo *philo)
{
	struct timeval now_tv;
	unsigned long now_time;
	gettimeofday(&now_time, NULL);
}


// 분할한 usleep의 총량이 정확한 최근사값으로 딸어질 수 있는 방법
// usleep return 0 if it success. return n as the remain time.
// ********반복하는 텀이 짧아서 더 많이 반복하게 된다면... 스레드에서 받는 영향도 증폭되지 않나?...
// 정수값을 더해주어서
