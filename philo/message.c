/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:35:41 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 17:34:08 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_message_by_state(t_state state)
{
	if (state == FORK)
		return ("has taken a fork\n");
	if (state == EAT)
		return ("is eating\n");
	if (state == SLEEP)
		return ("is sleeping\n");
	if (state == THINK)
		return ("is thinking\n");
	if (state == END)
		return ("was eaten as the philo must eat\n");
	if (state == DIE)
		return ("died\n");
	return (0);
}

int	print_messsage_stdout(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->isAnyoneDead_mtx));
	printf("%lu ms %dth philo %s",
		fn_gettimenow(philo->data),
		philo->id,
		get_message_by_state(philo->state));
	if (philo->data->isAnyoneDead == 0)
		pthread_mutex_unlock(&(philo->data->isAnyoneDead_mtx));
	return (0);
}