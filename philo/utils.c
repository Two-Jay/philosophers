/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:20:43 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 19:30:45 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

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

unsigned long	fn_gettime_from_lasteat(t_data *data)
{
	struct timeval	now_tv;
	struct timeval	lasteat_tv;
	unsigned long	ret;

	if (lasteat_tv.tv_sec == 0)
		lasteat_tv = data->time_to_start_tv;
	else
		lasteat_tv = data->time_lasteat_tv;
	gettimeofday(&now_tv, NULL);
	ret = ((now_tv.tv_sec - lasteat_tv.tv_sec) * 1000)
		+ ((now_tv.tv_usec - lasteat_tv.tv_usec) / 1000);
	data->time_lasteat_tv = now_tv;
	return (ret);
}
